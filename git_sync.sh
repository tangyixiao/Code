#!/usr/bin/env bash
set -euo pipefail

repo_root="$(git rev-parse --show-toplevel 2>/dev/null)" || {
    echo "错误：当前目录不在 Git 仓库中。" >&2
    exit 1
}

branch="$(git symbolic-ref --quiet --short HEAD 2>/dev/null)" || {
    echo "错误：当前处于 detached HEAD 状态，无法确定推送分支。" >&2
    exit 1
}

cd "$repo_root"
git add -A
changed_files="$(git diff --cached --name-status)"

if [[ -z "$changed_files" ]]; then
    echo "没有需要提交的变更。"
    exit 0
fi

timestamp="$(date '+%Y-%m-%d-%H-%M-%S-%3N')"
message_file="$(mktemp)"
trap 'rm -f "$message_file"' EXIT

{
    printf '%s\n\n变更文件:\n' "$timestamp"
    printf '%s\n' "$changed_files"
} >"$message_file"

git commit -F "$message_file"
git push origin "$branch"
