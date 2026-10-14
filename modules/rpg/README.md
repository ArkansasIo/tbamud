# RPG/MMORPG Foundation

An additive, standalone C99 gameplay library. It does not replace tbaMUD's existing character, object, room, world-file, or persistence structures; integration must be performed through reviewed adapters and regression tests.

Implemented primitives: attributes and derived stats, XP/level progression, stackable inventory, quest objective progress, timed world events, and a bounded rumor diffusion model.

Run tests with `make -C modules/rpg test` using a C99 compiler.

All gameplay state remains server-authoritative. Never trust client-reported damage, currency, item counts, cooldowns, quest completion, or loot. Persist stable IDs and versioned records rather than raw C structs/pointers. Use original content and assets; no proprietary game code or data is included.
