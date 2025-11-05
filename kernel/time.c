// .c
// OS Time and Sleep Functions
// by Kyle Furey

#include "time.h"
#include "lib.h"
#include "assembly.h"

/** The number of ticks since the kernel started. */
volatile uint_t ticks = 0;

/** The number of ticks to increment each interrupt by the Programmable Interval Timer. */
uint_t speed = 1;

/** Returns the total number of milliseconds since the kernel booted. */
uint_t time() {
	uint_t ms;
	cli();
	ms = ticks;
	sti();
	return ms * PIT_TICK_MS;
}

/** Pauses the kernel for about the given number of milliseconds. */
void sleep(uint_t ms) {
	ms += time();
	while (time() < ms) {
		hlt();
	}
}

/** Increments the kernel timer. */
void tick() {
	ticks += speed;
}
