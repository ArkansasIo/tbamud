#ifndef TBAMUD_RPG_CORE_H
#define TBAMUD_RPG_CORE_H
#include <stddef.h>
#include <stdint.h>
#define RPG_MAX_LEVEL 100u
#define RPG_INVENTORY_CAPACITY 64u
#define RPG_QUEST_OBJECTIVES 8u
#define RPG_ITEM_ID_MAX 63u
typedef enum { RPG_OK=0, RPG_ERR_ARGUMENT, RPG_ERR_CAPACITY, RPG_ERR_INSUFFICIENT, RPG_ERR_OVERFLOW } rpg_result;
typedef struct { int32_t strength, agility, stamina, intellect, spirit; } rpg_attributes;
typedef struct { int64_t max_health, max_mana, attack_power, armor; } rpg_derived_stats;
typedef struct { uint32_t level; uint64_t experience, currency; rpg_attributes attributes; } rpg_character;
typedef struct { char item_id[RPG_ITEM_ID_MAX+1u]; uint32_t count, max_stack; } rpg_item_stack;
typedef struct { size_t size; rpg_item_stack slots[RPG_INVENTORY_CAPACITY]; } rpg_inventory;
typedef struct { uint32_t required, progress; } rpg_quest_objective;
typedef struct { uint32_t objective_count; rpg_quest_objective objectives[RPG_QUEST_OBJECTIVES]; uint8_t turned_in; } rpg_quest_progress;
uint64_t rpg_experience_for_next_level(uint32_t level);
rpg_result rpg_grant_experience(rpg_character *character, uint64_t amount, uint32_t *levels_gained);
rpg_result rpg_derive_stats(const rpg_character *character, rpg_derived_stats *out_stats);
rpg_result rpg_inventory_add(rpg_inventory *inventory, const char *item_id, uint32_t count, uint32_t max_stack);
rpg_result rpg_inventory_remove(rpg_inventory *inventory, const char *item_id, uint32_t count);
rpg_result rpg_quest_add_progress(rpg_quest_progress *quest, uint32_t objective_index, uint32_t amount);
int rpg_quest_is_complete(const rpg_quest_progress *quest);
#endif
