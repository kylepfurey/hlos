// .c
// OS Random Number Functions
// by Kyle Furey

#include "rand.h"

/** The seed for random number generation. */
ulong_t seed = 0xBADA55;

/** Returns a pseudo-randomly generated number. */
ulong_t rand() {
	seed = (1103515245 * seed + 12345) & 0x7fffffff;
	return seed;
}

/** Returns a pseudo-randomly generated number within the given range. */
ulong_t randrange(const ulong_t min, const ulong_t max) {
	const ulong_t range = max - min;
	return (rand() % range) + min;
}
