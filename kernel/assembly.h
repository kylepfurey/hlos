// .h
// OS External Assembly Functions
// by Kyle Furey

#ifndef HLOS_ASSEMBLY_H
#define HLOS_ASSEMBLY_H

#include "types.h"

/** Pauses the CPU. */
extern void hlt();

/** Disables external interrupts. */
extern void cli();

/** Enables external interrupts. */
extern void sti();

/** Reads a byte from the given IO port. */
extern byte_t in(ushort_t port);

/** Writes a byte to the given IO port. */
extern void out(ushort_t port, byte_t num);

// INTERRUPTS

/** The callback for the timer interrupt. */
extern void timer_interrupt();

/** The callback for the keyboard interrupt. */
extern void keyboard_interrupt();

#endif // HLOS_ASSEMBLY_H
