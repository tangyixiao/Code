import argparse
import json
import os
import re
import shutil
import subprocess
from datetime import datetime, timezone
from pathlib import Path


def natural_key(value: str) -> tuple[tuple[int, object], ...]:
    return tuple(
        (1, int(part)) if part.isdigit() else (0, part)
        for part in re.split(r"(\d+)", value.casefold())
    )


def latest_file_commits(root: Path) -> dict[str, tuple[int, str, str]]:
    result = subprocess.run(
        ["git", "log", "--format=%x1e%H%x09%ct%x09%cI", "--name-only", "-z", "--diff-filter=AMRT"],
        cwd=root,
        check=True,
        stdout=subprocess.PIPE,
    )
    latest = {}
    for block in result.stdout.split(b"\x1e")[1:]:
        header, separator, names = block.partition(b"\0\n")
        if not separator:
            continue
        sha, timestamp, committed_at = header.decode("utf-8").split("\t")
        for raw_path in names.split(b"\0"):
            if not raw_path:
                continue
            path = raw_path.decode("utf-8")
            if path not in latest or int(timestamp) > latest[path][0]:
                latest[path] = (int(timestamp), committed_at, sha)
    return latest


def tracked_root_files(root: Path) -> list[dict[str, object]]:
    result = subprocess.run(
        ["git", "ls-files", "-z", "--", "*.cpp", "*.md"],
        cwd=root,
        check=True,
        stdout=subprocess.PIPE,
    )
    paths = result.stdout.decode("utf-8").split("\0")
    commits = latest_file_commits(root)
    files = []
    for value in paths:
        if not value:
            continue
        path = Path(value)
        if path.parent != Path(".") or path.suffix.casefold() not in {".cpp", ".md"}:
            continue
        if value not in commits:
            raise ValueError(f"missing commit history for {value}; fetch the full Git history")
        full_path = root / path
        files.append(
            {
                "name": path.name,
                "path": path.as_posix(),
                "type": path.suffix[1:].casefold(),
                "size": full_path.stat().st_size,
                "updatedAt": commits[value][1],
                "lastCommit": commits[value][2],
                "_sortTime": commits[value][0],
            }
        )
    files.sort(key=lambda item: (-int(item["_sortTime"]), natural_key(str(item["name"]))))
    for file in files:
        del file["_sortTime"]
    return files


def git_history(root: Path, commit: str, generated_at: str) -> dict[str, object]:
    log = subprocess.run(
        ["git", "log", "--all", "--graph", "--date-order", "--max-count=1200", "--format=%x1e%H%x1f%P%x1f%cI%x1f%an%x1f%s"],
        cwd=root,
        check=True,
        capture_output=True,
        text=True,
        encoding="utf-8",
        errors="replace",
    )
    rows = []
    for line in log.stdout.split("\n"):
        if "\x1e" not in line:
            if line.strip():
                rows.append({"graph": line})
            continue
        graph, details = line.split("\x1e", 1)
        sha, parents, committed_at, author, subject = details.split("\x1f", 4)
        rows.append({
            "graph": graph,
            "sha": sha,
            "parents": parents.split() if parents else [],
            "committedAt": committed_at,
            "author": author,
            "subject": subject,
        })

    refs = subprocess.run(
        ["git", "for-each-ref", "--format=%(refname)%09%(objectname)", "refs/heads", "refs/remotes/origin"],
        cwd=root,
        check=True,
        capture_output=True,
        text=True,
        encoding="utf-8",
    )
    branches = []
    for line in refs.stdout.splitlines():
        ref, sha = line.split("\t", 1)
        if ref.endswith("/HEAD"):
            continue
        remote = ref.startswith("refs/remotes/")
        name = ref.removeprefix("refs/remotes/") if remote else ref.removeprefix("refs/heads/")
        branches.append({"name": name, "sha": sha, "remote": remote})
    branches.sort(key=lambda branch: (not branch["remote"], branch["name"] != "origin/main", branch["name"]))

    return {
        "schemaVersion": 1,
        "generatedAt": generated_at,
        "buildCommit": commit.lower(),
        "pushEvent": os.environ.get("GITHUB_EVENT_NAME") == "push" and os.environ.get("GITHUB_REF") == "refs/heads/main",
        "remoteMain": next((branch["sha"] for branch in branches if branch["name"] == "origin/main"), None),
        "branches": branches,
        "rows": rows,
    }


def build(root: Path, output: Path, commit: str) -> None:
    if not re.fullmatch(r"[0-9a-fA-F]{40}", commit):
        raise ValueError("commit must be a 40-character hexadecimal SHA")
    dist = root / "dist"
    if not (dist / "index.html").is_file():
        raise FileNotFoundError(f"missing Vite build output: {dist / 'index.html'}")

    files = tracked_root_files(root)
    if not files:
        raise ValueError("no tracked root .cpp or .md files found")

    if output.exists():
        shutil.rmtree(output)
    shutil.copytree(dist, output)
    (output / ".nojekyll").write_text("", encoding="utf-8")
    generated_at = datetime.now(timezone.utc).isoformat(timespec="seconds").replace("+00:00", "Z")
    manifest = {
        "schemaVersion": 2,
        "commit": commit.lower(),
        "generatedAt": generated_at,
        "count": len(files),
        "files": files,
    }
    (output / "files.json").write_text(
        json.dumps(manifest, ensure_ascii=False, separators=(",", ":")) + "\n",
        encoding="utf-8",
    )
    (output / "history.json").write_text(
        json.dumps(git_history(root, commit, generated_at), ensure_ascii=False, separators=(",", ":")) + "\n",
        encoding="utf-8",
    )
    print(f"Built {len(files)} entries for {commit.lower()}")


def main() -> None:
    parser = argparse.ArgumentParser(description="Build the static CodeHub Pages artifact")
    parser.add_argument("--root", type=Path, default=Path.cwd())
    parser.add_argument("--output", type=Path, default=Path("_site"))
    parser.add_argument("--commit", required=True)
    args = parser.parse_args()
    try:
        build(args.root.resolve(), args.output.resolve(), args.commit)
    except (FileNotFoundError, ValueError, subprocess.CalledProcessError, UnicodeDecodeError) as error:
        parser.error(str(error))


if __name__ == "__main__":
    main()
