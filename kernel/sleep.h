// .h
// OS Sleep and Time Functions
// by Kyle Furey

#ifndef HLOS_SLEEP_H
#define HLOS_SLEEP_H

#include "types.h"

/** Programmable Interval Timer command port. */
#define PIT_CMD_PORT 0x43

/** Programmable Interval Timer command number. */
#define PIT_CMD_NUM 0x36

/** Programmable Interval Timer channel 0 (time). */
#define PIT_CHANNEL0_PORT 0x40

/** The frequency of the Programmable Interval Timer. */
#define PIT_FREQ 1193182

/** The number of Programmable Interval Timer interrupts per second. */
#define PIT_SPEED_HZ 1000

/** Calculates the value used to set the speed of the Programmable Interval Timer. */
#define PIT_DIVISOR(hz) (PIT_FREQ / (hz))

/** The time in milliseconds of a Programmable Interval Timer tick. */
#define PIT_TICK_MS (1000 / PIT_SPEED_HZ)

/** The number of ticks since the kernel started. */
extern volatile uint_t ticks;

/** The number of ticks to increment each interrupt by the Programmable Interval Timer. */
extern uint_t speed;

/** Pauses the kernel for about the given number of milliseconds. */
void sleep(uint_t ms);

/** Returns the total number of milliseconds since the kernel booted. */
uint_t time();

/** Increments the kernel timer. */
void tick();

#endif // HLOS_SLEEP_H
