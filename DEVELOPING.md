# Developer Guide

This guide is a practical entry point for configuring, building, testing, and contributing to tbaMUD. It complements the historical platform-specific files in `doc/`; those files remain authoritative for platform-specific details.

## Project at a glance

tbaMUD is a C-based multiplayer text-game server. The repository includes the game server and utilities in `src/`, world/player data and runtime configuration directories, multiple build systems, historical platform notes under `doc/`, and a C unit-test suite under `tests/`.

## Requirements

For the Unix-like configure/make workflow, install a C compiler (GCC or Clang), GNU make, and the standard build tools required by the checked-in `configure` script. Python 3 is used by the test-result converter to write JUnit XML. CMake builds require CMake 3.12 or newer, as declared in the root `CMakeLists.txt`.

## Build with configure/make

Run from the repository root:

```sh
./configure
touch src/.accepted
make -C src
```

The `src/.accepted` marker is required by this repository's documented build procedure. Consult `doc/README.UNIX` and `doc/building.txt` for platform and installation details.

## Run unit tests

Configure first, then run:

```sh
./configure
make -C tests test
```

The tests use the vendored Unity C test framework. JUnit-compatible results are written under `tests/test-results/`. To clean generated test artifacts:

```sh
make -C tests clean
```

For test authoring, test inventory, known fixture limitations, and JUnit conversion, see [testing.md](doc/testing.md).

## Build and test with CMake

Use an out-of-tree build:

```sh
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

The CMake project describes Linux-oriented support; verify [README.CMAKE.md](doc/README.CMAKE.md) before relying on CMake on another operating system. Tests depending on GCC/Clang section garbage collection are conditionally omitted on unsupported toolchains.

## Continuous integration

The workflow in `.github/workflows/build.yml` configures and builds on Ubuntu, runs the Autotools test suite, and publishes JUnit test results. `.github/workflows/codeql.yml` provides CodeQL analysis. A green CI run is useful evidence, but it does not replace testing the platform and configuration you intend to deploy.

## Repository map

| Path | Purpose |
| --- | --- |
| `src/` | C server, game systems, editors, and utilities |
| `tests/` | Unity unit tests and regression fixtures |
| `doc/` | Administration, building, protocol, coding, and testing documentation |
| `lib/` | Runtime data and game content |
| `cnf/` | Configuration templates and generated configuration inputs |
| `.github/workflows/` | CI and CodeQL workflows |
| `CMakeLists.txt` | CMake build configuration |
| `configure`, `cnf/configure.ac` | Configure-based build setup |

## Contribution checklist

1. Keep changes focused and preserve existing licenses and notices.
2. Add or extend regression tests for bug fixes where practical.
3. Run relevant tests and include the commands/results in the pull request.
4. Avoid committing generated binaries, local configuration, player data, logs, or test-result artifacts.
5. For world-file, editor, trigger, or save changes, test error paths as well as successful writes.
6. Document platform-specific assumptions and avoid claiming support that has not been verified.

## Security and deployment notes

Run the server as a dedicated unprivileged account, restrict network exposure to required ports, keep backups of world and player data, and test upgrades against a copy of production data before deployment. Do not commit secrets or real player data. Review the project's security and protocol documentation before exposing a server publicly.

## Useful references

- [Unit testing guide](doc/testing.md)
- [CMake build guide](doc/README.CMAKE.md)
- [Unix build and administration notes](doc/README.UNIX)
- [Build instructions](doc/building.txt)
- [Coding standards](doc/coding.txt)
- [Protocol system](doc/ProtocolSystem.txt)
