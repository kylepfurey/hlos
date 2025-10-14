// .c
// OS Initialization Functions
// by Kyle Furey

#include "init.h"

/** Initializes the kernel. */
void init() {
	// Zero out .bss
	uint8_t* bss = &__bss_start;
	while (bss < &__bss_end) {
		*bss++ = 0;
	}
}

/** Halts the kernel. */
void pause() {
	while (true);
}
