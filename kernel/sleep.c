// .c
// OS Sleep Function
// by Kyle Furey

#include "sleep.h"

/** Pauses the OS for about the given number of milliseconds. */
void sleep(ulong_t ms) {
	ms *= MS_TO_CYCLES;
	while (ms-- > 0) {}
}
