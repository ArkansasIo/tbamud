# Text-First RPG: New Feature Theories and Design Models

These are original design hypotheses for a command-driven multiplayer world, not scientific laws. Keep them configurable and validate them with playtests.

## 1. Living-world event theory

Hypothesis: the world feels alive when meaningful state changes happen independently of player commands, but the text client receives concise, legible updates. An event has a zone, start time, end time and state:

- scheduled when now < start
- active when start <= now < end
- ended when now >= end

The implementation in modules/rpg/text_world.c supplies this deterministic event calendar. Text output should be emitted when state changes, not every server pulse. Examples: market day, caravan arrival, storm warning, bridge closure, faction patrol, harvest, or monster migration.

## 2. Rumor diffusion

Hypothesis: rumors create exploration and social play without relying on map markers. Each rumor has an origin, current zone, confidence C in [0,100], remaining hops H and time-to-live T. Propagation uses C_next = floor(C * credibility / 100), H_next = H - 1 and T_next = T - 1. Daily decay is C_next = floor(0.9 * C); a rumor expires at zero confidence or TTL.

The first implementation stores zone IDs but does not validate map adjacency. Before integration, restrict spread to connected routes, carriers, mail or explicitly defined communication channels. Server code must control rumor creation and confidence.

## 3. Emergent narrative loop

A world event can change vendor stock, alter a faction patrol, create a rumor, unlock a quest objective and add a history entry. Implement these as typed, idempotent event handlers rather than hidden side effects in room descriptions:

1. Simulation changes state.
2. Server emits an event with a stable ID.
3. Quest, NPC, economy, faction and narration systems validate prerequisites.
4. Each handler applies its effect at most once.
5. A concise entry is exposed through text commands such as events, rumors and history.

## 4. NPC memory and trust

Store `(actor_id, event_type, strength, last_seen, decay_rate)`. A possible model is memory(t) = initial_strength * exp(-lambda * elapsed_time). For a deterministic first version, use integer decay per world day. Memories may record rescue, theft, trade, insult, faction attack or a fulfilled promise. Dialogue should select from authored templates based on stored memories, never invent facts outside world state. Cap entries, decay stale ones, and distinguish witnessed facts from hearsay.

## 5. Faction reputation

For faction f, store reputation R_f in a bounded interval such as [-1000,1000]. Apply validated changes with R_f' = clamp(R_f + delta * witness_factor * evidence_factor, min, max). Use integer-scaled factors for determinism. Repeated actions need diminishing returns or daily caps. Reputation can change dialogue, service access, patrol behavior and quest branches. The server, not the client, calculates it.

## 6. Text combat readability

Report decision-relevant event types: intent, hit/miss, mitigation, status applied/expired, interrupt, defeat and reward. Coalesce repeated low-value lines but never hide state changes relevant to decisions. Resolve each action as S_next = Resolve(S, validated_action, seeded_rng), where S contains health, resources, cooldowns, statuses, position and threat. Log action IDs and random seeds for deterministic bug reproduction.

## 7. Exploration as an information interface

Rooms can reveal exits, landmarks, sounds, tracks, weather, local rumors and NPC behavior. Provide multiple channels for important clues: room description, NPC testimony and object inspection. Suggested commands include survey, listen, track, rumors, history, map and journal. Helpful syntax errors and command aliases are essential accessibility features in a text game.

## 8. Player-driven history and economy

Keep a durable ledger of major actions: a bridge repaired, regional boss defeated, treaty signed or trade route opened. Use it to drive history output and later NPC dialogue. Archive only significant events, not every movement. For dynamic prices, a candidate model is price_next = clamp(price_base * (1 + k * scarcity), min, max), where scarcity comes from server-maintained stock. Add fees and currency sinks to control inflation; simulate changes before enabling them live.

## 9. Validation and rollout

- Test time boundaries, duplicate event IDs, invalid confidence, exhausted rumor hops, expiration and capacity limits.
- Test persistence/restart so scheduled events do not fire twice.
- Playtest whether a new player can discover an event, investigate a rumor and understand changed NPC reactions.
- Measure event counts, rumor lifetime, abandoned objectives and command errors without logging secrets or private messages.
- Feature-flag new systems and preserve existing world files until migrations are tested.
