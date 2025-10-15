// .c
// OS Sleep Functions
// by Kyle Furey

#include "sleep.h"

/** Pauses the OS for about the given number of milliseconds. */
void sleep(uint32_t ms) {
	ms *= MS_TO_CYCLES;
	while (ms-- > 0) {}
}
