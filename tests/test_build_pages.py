import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "scripts" / "build_pages.py"


class BuildPagesTests(unittest.TestCase):
    def make_repo(self, directory: Path) -> None:
        subprocess.run(["git", "init", "-q", directory], check=True)
        subprocess.run(["git", "-C", directory, "config", "core.autocrlf", "false"], check=True)
        (directory / "index.html").write_text("<h1>CodeHub</h1>\n", encoding="utf-8")
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

    def test_builds_manifest_from_tracked_root_cpp_and_markdown(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            repo = Path(tmp)
            self.make_repo(repo)

            result = self.run_builder(repo)

            self.assertEqual(result.returncode, 0, result.stderr)
            manifest = json.loads((repo / "_site" / "files.json").read_text(encoding="utf-8"))
            self.assertEqual(manifest["schemaVersion"], 1)
            self.assertEqual(manifest["commit"], "a" * 40)
            self.assertRegex(manifest["generatedAt"], r"^\d{4}-\d{2}-\d{2}T.*Z$")
            self.assertEqual(manifest["count"], 2)
            self.assertEqual(
                manifest["files"],
                [
                    {"name": "A.cpp", "path": "A.cpp", "type": "cpp", "size": 13},
                    {"name": "题目 #1.md", "path": "题目 #1.md", "type": "md", "size": 9},
                ],
            )
            self.assertEqual((repo / "_site" / "index.html").read_text(encoding="utf-8"), "<h1>CodeHub</h1>\n")
            self.assertTrue((repo / "_site" / ".nojekyll").is_file())

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

            result = self.run_builder(repo)

            self.assertEqual(result.returncode, 0, result.stderr)
            manifest = json.loads((repo / "_site" / "files.json").read_text(encoding="utf-8"))
            names = [file["name"] for file in manifest["files"]]
            self.assertLess(names.index("P2.cpp"), names.index("P10.cpp"))


if __name__ == "__main__":
    unittest.main()
