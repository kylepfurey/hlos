// .c
// OS Initialization Function
// by Kyle Furey

#include "init.h"

/** Initializes the kernel. */
void init() {
	uint8_t* bss = &__bss_start;
	while (bss < &__bss_end) {
		*bss++ = 0;
	}
}
