# RPG/MMORPG Foundation

An additive, standalone C99 gameplay library. It does not replace tbaMUD's existing character, object, room, world-file, or persistence structures; integration must be performed through reviewed adapters and regression tests.

Implemented primitives: attributes and derived stats, quadratic XP/level progression, stackable inventory operations, and bounded quest objective progress.

Run tests with `make -C modules/rpg test` using a C99 compiler.

All gameplay state must remain server-authoritative. Never trust client-reported damage, currency, item counts, cooldowns, quest completion, or loot. Persist stable IDs and versioned records rather than raw C structs/pointers. This project uses original code and does not include proprietary World of Warcraft code, assets, dialogue, maps, quests, or data.
