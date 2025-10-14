// .c
// OS Kernel Entry Point
// by Kyle Furey

#include "hlos.h"

/** The entry point of the HLOS kernel. */
void kernel_main() {
	init();

	sleep(1000);
	clear();
	color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	const char* welcome = "Welcome to the\n";
	while (*welcome != '\0') {
		printchar(*welcome++);
		sleep(100);
	}
	color(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK);
	sleep(500);
	print("High");
	sleep(500);
	print("-Level ");
	sleep(500);
	print("Operating ");
	sleep(500);
	print("System");
	color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	print("!");
	welcome = "High-Level Operating System!";
	uint32_t length = len(welcome);
	sleep(1000);
	while (true) {
		const char character = pos(randrange(0, length + 1), VGA.row);
		color(randrange(0, VGA_COLOR_WHITE + 1), VGA_COLOR_BLACK);
		printchar(character);
		sleep(100);
	}

	pause();
}
