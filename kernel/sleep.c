// .c
// OS Sleep and Time Functions
// by Kyle Furey

#include "sleep.h"
#include "lib.h"

/** Pauses the OS for about the given number of milliseconds. */
void sleep(uint_t ms) {
	ms *= MS_TO_CYCLES;
	while (ms-- > 0) {}
}

/** Returns the number of ticks since the OS booted. */
int_t time() {
	// TODO
	return 0;
}
