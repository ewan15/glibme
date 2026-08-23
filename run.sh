#!/usr/bin/env sh
set -eu

cd "$(dirname "$0")"

cmake -S . -B build-cpp
cmake --build build-cpp --target glibme_tests
./build-cpp/glibme_tests
