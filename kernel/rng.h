// .h
// OS Random Number Functions
// by Kyle Furey

#ifndef HLOS_RNG_H
#define HLOS_RNG_H

#include "types.h"

/** The seed for random number generation. */
extern uint_t seed;

/** Returns a pseudo-randomly generated number. */
uint_t rng();

/** Returns a pseudo-randomly generated number within the given range. */
uint_t rngrange(uint_t min, uint_t max);

#endif // HLOS_RNG_H
