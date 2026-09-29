import json
import os
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "build_pages.py"


class BuildPagesTests(unittest.TestCase):
    def commit(self, directory: Path, message: str, date: str) -> str:
        env = os.environ.copy()
        env.update({"GIT_AUTHOR_DATE": date, "GIT_COMMITTER_DATE": date})
        subprocess.run(
            ["git", "-C", directory, "-c", "user.name=Test", "-c", "user.email=test@example.com", "commit", "-qm", message],
            check=True,
            env=env,
        )
        return subprocess.check_output(["git", "-C", directory, "rev-parse", "HEAD"], text=True).strip()

    def make_repo(self, directory: Path) -> None:
        subprocess.run(["git", "init", "-q", directory], check=True)
        subprocess.run(["git", "-C", directory, "config", "core.autocrlf", "false"], check=True)
        (directory / "index.html").write_text("<h1>CodeHub</h1>\n", encoding="utf-8")
        dist = directory / "dist"
        (dist / "assets").mkdir(parents=True)
        (dist / "index.html").write_text("<div id=\"root\"></div>\n", encoding="utf-8")
        (dist / "assets" / "app.js").write_text("console.log('vite')\n", encoding="utf-8")
        (directory / "A.cpp").write_bytes(b"int main(){}\n")
        (directory / "题目 #1.md").write_bytes("# 题目\n".encode("utf-8"))
        (directory / "skip.exe").write_bytes(b"MZ")
        (directory / "untracked.cpp").write_text("// untracked\n", encoding="utf-8")
        nested = directory / "nested"
        nested.mkdir()
        (nested / "tracked.cpp").write_text("// nested\n", encoding="utf-8")
        subprocess.run(
            ["git", "-C", directory, "add", "--", "index.html", "A.cpp", "题目 #1.md", "skip.exe", "nested/tracked.cpp"],
            check=True,
        )
        self.commit(directory, "initial files", "2020-01-01T00:00:00+00:00")

    def run_builder(self, directory: Path, commit: str = "a" * 40) -> subprocess.CompletedProcess[str]:
        return subprocess.run(
            [
                sys.executable,
                SCRIPT,
                "--root",
                directory,
                "--output",
                directory / "_site",
                "--commit",
                commit,
            ],
            text=True,
            capture_output=True,
        )

    def test_builds_manifest_from_all_tracked_files(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            repo = Path(tmp)
            self.make_repo(repo)

            result = self.run_builder(repo)

            self.assertEqual(result.returncode, 0, result.stderr)
            manifest = json.loads((repo / "_site" / "files.json").read_text(encoding="utf-8"))
            self.assertEqual(manifest["schemaVersion"], 2)
            self.assertEqual(manifest["commit"], "a" * 40)
            self.assertRegex(manifest["generatedAt"], r"^\d{4}-\d{2}-\d{2}T.*Z$")
            self.assertEqual(manifest["count"], 5)
            self.assertEqual({file["path"] for file in manifest["files"]}, {"A.cpp", "题目 #1.md", "index.html", "skip.exe", "nested/tracked.cpp"})
            self.assertEqual({file["path"]: file["size"] for file in manifest["files"]}["A.cpp"], 13)
            self.assertEqual({file["path"]: file["type"] for file in manifest["files"]}["skip.exe"], "exe")
            self.assertTrue(all(file["updatedAt"] == "2020-01-01T00:00:00Z" for file in manifest["files"]))
            self.assertTrue(all(len(file["lastCommit"]) == 40 for file in manifest["files"]))
            self.assertEqual((repo / "_site" / "index.html").read_text(encoding="utf-8"), "<div id=\"root\"></div>\n")
            self.assertEqual((repo / "_site" / "assets" / "app.js").read_text(encoding="utf-8"), "console.log('vite')\n")
            self.assertTrue((repo / "_site" / ".nojekyll").is_file())
            history = json.loads((repo / "_site" / "history.json").read_text(encoding="utf-8"))
            self.assertEqual(history["schemaVersion"], 1)
            self.assertEqual(history["buildCommit"], "a" * 40)
            self.assertIsNone(history["remoteMain"])
            self.assertEqual(len([row for row in history["rows"] if "sha" in row]), 1)
            self.assertEqual(history["rows"][0]["subject"], "initial files")

    def test_rejects_non_sha_commit(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            repo = Path(tmp)
            self.make_repo(repo)

            result = self.run_builder(repo, "main")

            self.assertNotEqual(result.returncode, 0)
            self.assertIn("40-character hexadecimal", result.stderr)

    def test_orders_numeric_problem_ids_naturally(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            repo = Path(tmp)
            self.make_repo(repo)
            (repo / "P10.cpp").write_bytes(b"10\n")
            (repo / "P2.cpp").write_bytes(b"2\n")
            subprocess.run(["git", "-C", repo, "add", "--", "P10.cpp", "P2.cpp"], check=True)
            self.commit(repo, "add two problems", "2020-01-02T00:00:00+00:00")

            result = self.run_builder(repo)

            self.assertEqual(result.returncode, 0, result.stderr)
            manifest = json.loads((repo / "_site" / "files.json").read_text(encoding="utf-8"))
            names = [file["name"] for file in manifest["files"]]
            self.assertLess(names.index("P2.cpp"), names.index("P10.cpp"))

    def test_orders_files_by_latest_commit_time(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            repo = Path(tmp)
            self.make_repo(repo)
            (repo / "Z.cpp").write_text("// new\n", encoding="utf-8")
            subprocess.run(["git", "-C", repo, "add", "--", "Z.cpp"], check=True)
            first = self.commit(repo, "add Z", "2020-01-02T00:00:00+00:00")
            (repo / "题目 #1.md").write_text("# 更新\n", encoding="utf-8")
            subprocess.run(["git", "-C", repo, "add", "--", "题目 #1.md"], check=True)
            latest = self.commit(repo, "update note", "2020-01-03T00:00:00+00:00")

            result = self.run_builder(repo)

            self.assertEqual(result.returncode, 0, result.stderr)
            files = json.loads((repo / "_site" / "files.json").read_text(encoding="utf-8"))["files"]
            self.assertEqual([file["name"] for file in files[:2]], ["题目 #1.md", "Z.cpp"])
            self.assertEqual(files[0]["lastCommit"], latest)
            self.assertEqual(files[1]["lastCommit"], first)


if __name__ == "__main__":
    unittest.main()
