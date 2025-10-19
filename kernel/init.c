// .c
// OS Initialization Function
// by Kyle Furey

#include "init.h"
#include "lib.h"

/** Initializes the kernel. */
void init() {
	// Zero uninitialized data
	byte_t* bss = &__bss_start;
	while (bss < &__bss_end) {
		*bss++ = 0;
	}
}
