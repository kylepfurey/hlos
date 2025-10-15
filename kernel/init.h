// .h
// OS Initialization Function
// by Kyle Furey

#ifndef HLOS_INIT_H
#define HLOS_INIT_H

#include "types.h"

/** The first byte of the kernel. */
extern byte_t __kernel_start;

/** The last byte of the kernel. */
extern byte_t __kernel_end;

/** The first byte of uninitialized data. */
extern byte_t __bss_start;

/** The last byte of uninitialized data. */
extern byte_t __bss_end;

/** Initializes the kernel. */
void init();

#endif // HLOS_INIT_H
