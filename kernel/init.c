// .c
// OS Initialization Function
// by Kyle Furey

#include "init.h"
#include "lib.h"

/** Initializes the kernel. */
void init() {
	// Zero uninitialized data
	set(&__bss_start, 0, abs(&__bss_end - &__bss_start));
}
