// .c
// OS Random Number Functions
// by Kyle Furey

#include "random.h"

/** The seed for random number generation. */
uint32_t seed = 0xBADA55;

/** Returns a pseudo-randomly generated number. */
uint32_t rand() {
	seed = (1103515245 * seed + 12345) & 0x7fffffff;
	return seed;
}

/** Returns a pseudo-randomly generated number within the given range. */
uint32_t randrange(const uint32_t min, const uint32_t max) {
	const uint32_t range = max - min;
	return (rand() % range) + min;
}
