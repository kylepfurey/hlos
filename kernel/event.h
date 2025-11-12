// .h
// OS Event Invocation Functions
// by Kyle Furey

#ifndef HLOS_EVENT_H
#define HLOS_EVENT_H

#include "types.h"

/** The maximum number of events that can be bound at once. */
#define MAX_EVENTS 16

/** Each bound event function. */
extern void (*events[MAX_EVENTS])(void *);

/** Sets the event callback at the given index. */
void event(uint_t index, void (*event)(void *));

/** Invokes the event callback at the given index with the given args. */
void invoke(uint_t index, void *args);

#endif // HLOS_EVENT_H
