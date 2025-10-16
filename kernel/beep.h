// .h
// OS Beep Sound Functions
// by Kyle Furey

#ifndef HLOS_BEEP_H
#define HLOS_BEEP_H

#include "types.h"

/** Beeps the computer. */
void beep();

/** Beeps for the given frequency in hertz and duration in milliseconds. */
void freq(uint_t hz, uint_t ms);

#endif // HLOS_BEEP_H
