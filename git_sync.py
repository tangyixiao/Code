#!/usr/bin/env python3
"""Commit all Git changes with a millisecond timestamp and push the branch."""

import os
import subprocess
import sys
import tempfile
from datetime import datetime
from pathlib import Path


def git(*args: str, capture_output: bool = False) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        ["git", *args],
        check=True,
        text=True,
        capture_output=capture_output,
    )


def timestamp_now() -> str:
    return datetime.now().strftime("%Y-%m-%d-%H-%M-%S-%f")[:-3]


def build_commit_message(timestamp: str, changed_files: list[str]) -> str:
    return f"{timestamp}\n\n变更文件:\n" + "\n".join(changed_files) + "\n"


def main() -> int:
    try:
        root = git("rev-parse", "--show-toplevel", capture_output=True).stdout.strip()
        branch = git(
            "symbolic-ref", "--quiet", "--short", "HEAD", capture_output=True
        ).stdout.strip()
    except subprocess.CalledProcessError:
        print("错误：当前目录不在 Git 仓库中，或处于 detached HEAD 状态。", file=sys.stderr)
        return 1

    if not root or not branch:
        print("错误：无法确定仓库根目录或当前分支。", file=sys.stderr)
        return 1

    os.chdir(root)
    git("add", "-A")
    changed = git("diff", "--cached", "--name-status", capture_output=True).stdout
    changed_files = changed.splitlines()

    if not changed_files:
        print("没有需要提交的变更。")
        return 0

    message = build_commit_message(timestamp_now(), changed_files)
    message_path = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="w", encoding="utf-8", suffix=".gitmessage", delete=False
        ) as message_file:
            message_file.write(message)
            message_path = message_file.name
        git("commit", "-F", message_path)
    finally:
        if message_path:
            Path(message_path).unlink(missing_ok=True)

    git("push", "origin", branch)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
