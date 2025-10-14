// .h
// OS Random Number Function
// by Kyle Furey

#ifndef HLOS_RANDOM_H
#define HLOS_RANDOM_H

#include "extern.h"

/** The seed for random number generation. */
extern uint32_t seed;

/** Returns a pseudo-randomly generated number. */
uint32_t rand();

/** Returns a pseudo-randomly generated number within the given range. */
uint32_t randrange(const uint32_t min, const uint32_t max);

#endif // HLOS_RANDOM_H
