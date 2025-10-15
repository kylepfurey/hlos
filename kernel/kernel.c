// .c
// OS Kernel Entry Point
// by Kyle Furey

#include "hlos.h"

/** The entry point of the HLOS kernel. */
void kernel_main() {
	init();

	sleep(1000);
	clear();
	print("\n\t\t");
	color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	string_t welcome = "Welcome to the\n\n";
	sleep(1000);
	while (*welcome != '\0') {
		printchar(*welcome++);
		sleep(75);
	}

	color(VGA_COLOR_BROWN, VGA_COLOR_BLACK);
	sleep(300);
	print(" High");
	sleep(300);
	print("-Level ");
	sleep(300);
	print("Operating ");
	sleep(300);
	print("System!");
	color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

	welcome = " High-Level Operating System!";
	const ulong_t length = strlen(welcome);
	const VGA_color_t rainbow[] = {
		VGA_COLOR_LIGHT_RED,
		VGA_COLOR_LIGHT_BLUE,
		VGA_COLOR_LIGHT_CYAN,
		VGA_COLOR_LIGHT_GREEN,
		VGA_COLOR_LIGHT_MAGENTA,
		VGA_COLOR_YELLOW,
		VGA_COLOR_BROWN,
		VGA_COLOR_RED,
	};
	const ulong_t size = ARRAY_SIZE(rainbow, VGA_color_t);
	ulong_t index = (ulong_t)-1;
	sleep(750);
	print("\n\n\t\t\tYaay!");
	VGA.row -= 2;
	while (true) {
		for (ulong_t i = 0; i < length; i++) {
			const char_t character = pos(i, VGA.row);
			color(rainbow[(index + i) % size], VGA_COLOR_BLACK);
			printchar(character);
			sleep(1);
		}
		--index;
	}

	pause();
}
