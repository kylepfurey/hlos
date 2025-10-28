// .h
// OS Sleep and Time Functions
// by Kyle Furey

#ifndef HLOS_SLEEP_H
#define HLOS_SLEEP_H

#include "types.h"

/** Multiply this number by a number of milliseconds to estimate the time in CPU cycles. */
#define MS_TO_CYCLES 600000

/** Multiply this number by a number of CPU cycles to estimate the time in milliseconds. */
#define CYCLES_TO_MS (1.0 / MS_TO_CYCLES)

/** Pauses the kernel for about the given number of milliseconds. */
void sleep(uint_t ms);

/** Returns the number of ticks since the kernel booted. */
uint_t time();

#endif // HLOS_SLEEP_H
