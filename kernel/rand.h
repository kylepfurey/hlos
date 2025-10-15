// .h
// OS Random Number Functions
// by Kyle Furey

#ifndef HLOS_RAND_H
#define HLOS_RAND_H

#include "types.h"

/** The seed for random number generation. */
extern ulong_t seed;

/** Returns a pseudo-randomly generated number. */
ulong_t rand();

/** Returns a pseudo-randomly generated number within the given range. */
ulong_t randrange(const ulong_t min, const ulong_t max);

#endif // HLOS_RAND_H
