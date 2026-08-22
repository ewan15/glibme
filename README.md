# glibme

A small C++ project for learning how glibc works by implementing libc-style
functions from scratch.

## Building

Configure and build the project with CMake:

```sh
cmake -S . -B build
cmake --build build
```

By default this builds:

- `build/libglibme.a`
- `build/libglibme.dylib` on macOS, or `build/libglibme.so` on Linux
- `build/glibme_tests`

Run the test suite:

```sh
ctest --test-dir build --output-on-failure
```

Format the source:

```sh
./scripts/format.sh
```

Check formatting without changing files:

```sh
./scripts/format.sh --check
```

Install the library and headers:

```sh
cmake --install build --prefix ./dist
```

Build only the static library:

```sh
cmake -S . -B build -DGLIBME_BUILD_SHARED=OFF
cmake --build build
```

## Function Implementation Roadmap

See [ROADMAP.md](ROADMAP.md) for the implementation checklist.
