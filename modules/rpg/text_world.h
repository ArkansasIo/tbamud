#ifndef TBAMUD_TEXT_WORLD_H
#define TBAMUD_TEXT_WORLD_H
#include <stddef.h>
#include <stdint.h>
#define TW_MAX_EVENTS 32u
#define TW_MAX_RUMORS 32u
#define TW_ID_LEN 31u
#define TW_TEXT_LEN 159u
typedef enum { TW_OK=0, TW_ERR_ARGUMENT, TW_ERR_CAPACITY, TW_ERR_DUPLICATE, TW_ERR_NOT_FOUND } tw_result;
typedef enum { TW_EVENT_SCHEDULED=0, TW_EVENT_ACTIVE, TW_EVENT_ENDED } tw_event_state;
typedef struct { char id[TW_ID_LEN+1u]; uint32_t zone_id; uint64_t starts_at, ends_at; tw_event_state state; } tw_world_event;
typedef struct { size_t count; tw_world_event entries[TW_MAX_EVENTS]; } tw_event_calendar;
typedef struct { char id[TW_ID_LEN+1u]; char text[TW_TEXT_LEN+1u]; uint32_t origin_zone, current_zone, confidence, hops_left, ttl; } tw_rumor;
typedef struct { size_t count; tw_rumor entries[TW_MAX_RUMORS]; } tw_rumor_board;
tw_result tw_event_schedule(tw_event_calendar *, const char *, uint32_t, uint64_t, uint64_t);
size_t tw_event_advance(tw_event_calendar *, uint64_t);
const tw_world_event *tw_event_find(const tw_event_calendar *, const char *);
tw_result tw_rumor_publish(tw_rumor_board *, const char *, const char *, uint32_t, uint32_t, uint32_t, uint32_t);
tw_result tw_rumor_spread(tw_rumor_board *, const char *, uint32_t, uint32_t);
size_t tw_rumor_advance_day(tw_rumor_board *);
const tw_rumor *tw_rumor_find(const tw_rumor_board *, const char *);
#endif
