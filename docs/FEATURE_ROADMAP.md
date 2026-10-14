# MMORPG/RPG Feature Roadmap

## Goal

Extend tbaMUD into an original, server-authoritative MMORPG while preserving the existing CircleMUD-derived text server, compatibility, and applicable licenses. This catalogue is a roadmap, not a claim every feature is already implemented. Initial C99 primitives live in `modules/rpg/`.

Do not copy World of Warcraft proprietary source, content, maps, quests, dialogue, models, textures, sounds, UI art, or trademarks. Build original implementations and content around common genre mechanics.

## Feature catalogue

### Character and progression
- Character creation; configurable races, classes, class resources and specialization/role profiles.
- Attributes and derived stats; XP/levels; level caps; rested XP; skill ranks; talent trees; respec rules.
- Reputation, titles, achievements, collections, appearance/cosmetics, death, resurrection and durability.

### Combat
- Authoritative hit resolution; range and line of sight; cast times; cooldowns; interrupts; resource costs; global cooldown.
- Physical/magic damage, armor/resistance, crits, avoidance, threat, taunts, crowd control, dispels, healing, shields, damage-over-time and healing-over-time.
- Encounter phases, boss abilities, enrage timers, wipe/reset, combat logs and replayable deterministic tests.
- PvP rulesets, diminishing returns, ratings, arenas, battleground objectives, safe-zone rules and anti-exploit checks.

### Items and economy
- Inventory, stacking, equipment slots, stat modifiers, item rarity, set bonuses, durability and cosmetic transmog.
- Data-driven item definitions, loot tables, seeded loot rolls, bind rules, personal/group loot and anti-duplication.
- Vendors, currency, bank, mail, auction house, player trading, guild bank and transaction audit logs.
- Gathering, professions, crafting recipes, proficiency, material costs, discovery, enchanting, gems and upgrades.

### Quests and world
- Quest chains, prerequisites, kill/collect/explore/interact/escort/event objectives, branches, daily/weekly resets, abandonment and rewards.
- Quest journal/tracker, dialogue choices, markers, party credit policies and replay rules.
- Zones, instances, phases, portals, transports, discovery, maps, flight paths, weather and day/night.
- NPC AI: patrol, aggro/leash, social assist, threat, flee, respawn, scripting and sandboxed encounter logic.
- Dynamic events, world bosses, rare spawns, gathering nodes and deterministic procedural generation with validation.

### Multiplayer and social
- Parties, role selection, ready checks, leadership, markers, shared credit, loot policies, group reconnect recovery.
- Guilds, ranks, permissions, banks, rosters, achievements, calendars and audit logs.
- Friends, ignore/block, whispers, chat channels, emotes, moderation, mute/ban and player reports.
- LFG/LFR-style queues, role-aware matchmaking, latency-aware selection, deserter policies and ratings/seasons.

### Dungeons, raids and endgame
- Instanced dungeons, raid groups, scalable difficulty, encounter scripting, boss loot and completion records.
- Challenge timers, affixes, seasonal rotations, leaderboards, lockouts and anti-cheat validation.
- World PvP objectives, battlegrounds, arenas, territory/faction systems, achievements and rotating events.

### Client and interface
- Keep telnet/text clients supported. Add versioned protocol capability negotiation.
- Optional Unreal Engine 5.7 graphical client adapter: authentication, character select, movement intents, world snapshots, combat intents, inventory, quests, chat, groups and guild events.
- UI: character sheet, action bars, cooldowns, bags/equipment, quest journal/tracker, minimap/world map, social panes, group/raid frames, talents, professions, settings and accessibility.
- Graphical clients are untrusted: never accept client-authoritative positions, damage, inventory, currency, cooldowns, loot or quest completion.

### Persistence, infrastructure and operations
- Versioned schemas/migrations for characters, items, quests, guilds, mail, auctions, achievements, cooldowns and instance locks.
- Atomic item/currency transactions, idempotency keys, uniqueness constraints, backups, restore drills and crash recovery.
- Session/auth service, vetted password hashing, rate limits, session revocation and account recovery.
- Structured logs, metrics, tracing, health checks, moderator tools, reports, economy monitoring and deployment runbooks.
- Optional cluster/zone servers only after character/session/world ownership, durable writes, routing and split-brain fencing are defined.
- Fuzz protocol parsers; validate bounds/permissions; sandbox scripts; audit dependencies and secrets.

## Delivery phases

1. **Gameplay primitives:** stats, XP, inventory stacks, quest counters and isolated unit tests (started in `modules/rpg/`).
2. **Data definitions and integration:** versioned classes/items/abilities/quests/loot; adapters for existing character/object/world/save structures; migration and regression tests.
3. **Core RPG loop:** abilities, talents, equipment, loot, quests, NPC AI, crafting, professions, cooldowns, threat and death/recovery.
4. **MMORPG systems:** parties, guilds, social, instances, raids, PvP, matchmaking, account/session APIs and negotiated client protocol.
5. **Production and graphical client:** persistence hardening, telemetry, moderation, anti-exploit controls, load tests, deployment automation and optional UE5.7 client.

## Architecture requirements

- Server authoritative; clients send intents, never final outcomes.
- Data-driven content and stable IDs; avoid hard-coded content logic.
- Keep existing clients compatible and negotiate extensions.
- Treat item/currency changes as atomic, auditable transactions.
- Test happy paths, invalid inputs, overflow, persistence failures and rollback.
- Do not change existing world/player formats without migration and rollback plans.
- Original intellectual property only.

A feature is not complete until it has a data model, server-side validation, persistence/migration behavior, permission checks, failure-path handling, automated tests, documentation and operational logs/metrics.
