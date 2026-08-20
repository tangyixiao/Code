import argparse
import json
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


def tracked_root_files(root: Path) -> list[dict[str, object]]:
    result = subprocess.run(
        ["git", "ls-files", "-z", "--", "*.cpp", "*.md"],
        cwd=root,
        check=True,
        stdout=subprocess.PIPE,
    )
    paths = result.stdout.decode("utf-8").split("\0")
    files = []
    for value in paths:
        if not value:
            continue
        path = Path(value)
        if path.parent != Path(".") or path.suffix.casefold() not in {".cpp", ".md"}:
            continue
        full_path = root / path
        files.append(
            {
                "name": path.name,
                "path": path.as_posix(),
                "type": path.suffix[1:].casefold(),
                "size": full_path.stat().st_size,
            }
        )
    return sorted(files, key=lambda item: natural_key(str(item["name"])))


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
    manifest = {
        "schemaVersion": 1,
        "commit": commit.lower(),
        "generatedAt": datetime.now(timezone.utc).isoformat(timespec="seconds").replace("+00:00", "Z"),
        "count": len(files),
        "files": files,
    }
    (output / "files.json").write_text(
        json.dumps(manifest, ensure_ascii=False, separators=(",", ":")) + "\n",
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
