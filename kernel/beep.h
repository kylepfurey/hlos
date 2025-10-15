// .h
// OS Beep Sound Functions
// by Kyle Furey

#ifndef HLOS_BEEP_H
#define HLOS_BEEP_H

#include "extern.h"

/** Beeps the computer. */
void beep();

/** Beeps for the given frequency in hertz and duration in milliseconds. */
void freq(const uint16_t hz, const uint16_t ms);

#endif // HLOS_BEEP_H
