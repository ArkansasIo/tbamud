# Contributing

Thanks for helping improve tbaMUD.

## Before making a change

1. Read [DEVELOPING.md](DEVELOPING.md), [doc/coding.txt](doc/coding.txt), and the applicable platform notes.
2. Keep patches focused; preserve existing license headers and notices.
3. For bug fixes, add a regression test when a practical test seam exists.
4. Do not commit generated executables, local config, logs, world/player data, or test output.

## Validate

For the configure/make path:

```sh
./configure
touch src/.accepted
make -C src
make -C tests test
```

For CMake:

```sh
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

CMake and Autotools may not support identical platform/toolchain combinations. Report the operating system, compiler, build system, and actual test output in your pull request.

## Pull requests

Explain the problem, impact, and chosen fix. Include tests run, tests not run, compatibility considerations, and required world/configuration migration notes.
