#include "rpg_core.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
int main(void) { rpg_character c={1,0,0,{5,3,4,2,1}}; uint32_t gained=0; rpg_derived_stats d; rpg_inventory inv; rpg_quest_progress q; memset(&inv,0,sizeof inv); memset(&q,0,sizeof q); assert(rpg_grant_experience(&c,1000,&gained)==RPG_OK&&c.level==2&&gained==1); assert(rpg_derive_stats(&c,&d)==RPG_OK&&d.max_health==180); assert(rpg_inventory_add(&inv,"herb",8,10)==RPG_OK); assert(rpg_inventory_add(&inv,"herb",5,10)==RPG_OK&&inv.size==2); assert(rpg_inventory_remove(&inv,"herb",11)==RPG_OK); assert(rpg_inventory_remove(&inv,"herb",3)==RPG_ERR_INSUFFICIENT); q.objective_count=1; q.objectives[0].required=3; assert(rpg_quest_add_progress(&q,0,5)==RPG_OK&&rpg_quest_is_complete(&q)); q.turned_in=1; assert(rpg_quest_add_progress(&q,0,1)==RPG_ERR_ARGUMENT); puts("RPG core tests: PASS"); return 0; }
