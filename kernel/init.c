// .c
// OS Initialization Function
// by Kyle Furey

#include "init.h"
#include "lib.h"
#include "assembly.h"
#include "interrupt.h"
#include "time.h"

/** Initializes the Programmable Interval Timer. */
static void PIT_init() {
	out(PIT_CMD_PORT, PIT_CMD_NUM);
	uint_t divisor = PIT_DIVISOR(PIT_SPEED_HZ);
	out(PIT_CHANNEL0_PORT, (byte_t)(divisor & 255));
	out(PIT_CHANNEL0_PORT, (byte_t)((divisor >> 8) & 255));
	IDT_bind(PIC_TIMER, timer_interrupt, IDT_KERNEL_SELECTOR, IDT_KERNEL_FLAGS);
	IRQ_enable(IRQ_TIMER);
}

/** Initializes the kernel. */
void init() {
	// Zero uninitialized data
	set(&__bss_start, 0, abs(&__bss_end - &__bss_start));
	// Initialize the Programmable Interval Timer
	PIT_init();
}
