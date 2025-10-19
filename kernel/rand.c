// .c
// OS Random Number Functions
// by Kyle Furey

#include "rand.h"
#include "lib.h"

/** The seed for random number generation. */
uint_t seed = 0xBADA55;

/** Returns a pseudo-randomly generated number. */
uint_t rand() {
	seed = (1103515245 * seed + 12345) & 0x7fffffff; // LGC
	return seed;
}

/** Returns a pseudo-randomly generated number within the given range. */
uint_t randrange(uint_t min, uint_t max) {
	assert(min > max, "randrange() - min was greater than max!");
	uint_t range = max - min;
	return (rand() % range) + min;
}
