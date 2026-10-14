# Architecture Overview

This is a high-level map of the existing tbaMUD source tree to guide code navigation. It does not claim a complete independent audit of every module.

## Runtime layers

### Server and connection loop

- `src/comm.c` and `src/comm.h`: core communication and server loop.
- `src/protocol.c` and `src/protocol.h`: protocol negotiation and client-facing protocol support.
- `src/interpreter.c` and `src/interpreter.h`: player command parsing and dispatch.

### World state and gameplay

- `src/db.c`, `src/db.h`: world/database loading and related state.
- `src/handler.c`, `src/handler.h`, `src/lists.c`, `src/lists.h`: shared entity and list operations.
- `src/act.*.c`: player-facing actions grouped by command category.
- `src/fight.c`, `src/magic.c`, `src/spells.c`, `src/class.c`, `src/limits.c`, and `src/weather.c`: combat and other gameplay rules.

### Builder tools and editable content

- `src/oasis.c` and the `src/*edit.c` modules: in-game world-building/editing support.
- `src/genmob.c`, `src/genobj.c`, `src/genwld.c`, `src/genzon.c`, and `src/genolc.c`: world data and save paths.
- `src/dg_*.c`: scripting/trigger support, events, script commands, and variables.

### Supporting services and utilities

- `src/house.c`, `src/mail.c`, `src/boards.c`, `src/shop.c`, and quest-related modules implement supporting game services.
- `src/util/`: standalone conversion, administration, and data-maintenance tools.
- `lib/`, `cnf/`, and related data directories contain runtime content and configuration templates.

## Build paths

- Configure-based: `./configure`, create the required `src/.accepted` marker, then `make -C src`.
- CMake: `cmake -S . -B build`, `cmake --build build`, and `ctest --test-dir build --output-on-failure`.
- Unit tests: `make -C tests test` after configuration.

Use the root [Developer Guide](../DEVELOPING.md) and [testing guide](testing.md) for commands and known test limitations. Exact supported toolchains can vary by build system; see the platform guides in this directory.
