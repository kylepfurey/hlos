// .h
// OS Sleep Function
// by Kyle Furey

#ifndef HLOS_SLEEP_H
#define HLOS_SLEEP_H

#include "types.h"

/** Multiply this number by a number of milliseconds to estimate the time in CPU cycles. */
#define MS_TO_CYCLES 600000

/** Multiply this number by a number of CPU cycles to estimate the time in milliseconds. */
#define CYCLES_TO_MS (1.0 / MS_TO_CYCLES)

/** Pauses the OS for about the given number of milliseconds. */
void sleep(ulong_t ms);

#endif // HLOS_SLEEP_H
