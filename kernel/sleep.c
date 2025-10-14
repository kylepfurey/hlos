// .c
// OS Sleep Functions
// by Kyle Furey

#include "sleep.h"

/** A counter the BIOS increments approximately every 55 milliseconds. */
volatile const uint32_t* const BIOS_ticks = (uint32_t*)0x046C;

/** Pauses the OS for about the given number of milliseconds. */
void sleep(const uint32_t ms) {
	const uint32_t start = *BIOS_ticks;
	const uint32_t count = (ms + 54) / 55;
	while ((*BIOS_ticks - start) < count) {}
}
