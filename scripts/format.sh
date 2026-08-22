#!/usr/bin/env sh
set -eu

cd "$(dirname "$0")/.."

mode="format"
if [ "${1:-}" = "--check" ]; then
  mode="check"
elif [ "${1:-}" != "" ]; then
  echo "usage: $0 [--check]" >&2
  exit 2
fi

if ! command -v clang-format >/dev/null 2>&1; then
  echo "error: clang-format is required but was not found" >&2
  exit 1
fi

files=$(find include src tests -type f \( -name '*.hpp' -o -name '*.cpp' \) | sort)

if [ "$mode" = "check" ]; then
  clang-format --dry-run --Werror $files
else
  clang-format -i $files
fi
