// .c
// OS Event Invocation Functions
// by Kyle Furey

#include "event.h"
#include "lib.h"

/** Each bound event function. */
void (*events[MAX_EVENTS])(void *) = {0};

/** Sets the event callback at the given index. */
void event(uint_t index, void (*event)(void *)) {
    assert(index < MAX_EVENTS, "event() - index was >= MAX_EVENTS!");
    events[index] = event;
}

/** Invokes the event callback at the given index with the given args. */
void invoke(uint_t index, void *args) {
    assert(index < MAX_EVENTS, "event() - index was >= MAX_EVENTS!");
    void (*event)(void *) = events[index];
    if (event != NULL) {
        event(args);
    }
}
