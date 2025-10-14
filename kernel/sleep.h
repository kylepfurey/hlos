// .h
// OS Sleep Functions
// by Kyle Furey

#ifndef HLOS_SLEEP_H
#define HLOS_SLEEP_H

#include "extern.h"

/** A counter the BIOS increments approximately every 55 milliseconds. */
extern volatile const uint32_t* const BIOS_ticks;

/** Pauses the OS for about the given number of milliseconds. */
void sleep(const uint32_t ms);

#endif // HLOS_SLEEP_H
