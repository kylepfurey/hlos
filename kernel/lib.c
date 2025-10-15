// .c
// OS Library
// by Kyle Furey

#include "lib.h"
#include "print.h"

/** Returns the length of a string. */
uint32_t len(const char* const str) {
	uint32_t length = 0;
	while (str[length] != '\0') {
		++length;
	}
	return length;
}

/** Halts the kernel. */
void pause() {
	while (true);
}

/** Crashes the kernel with an error if the given condition is false. */
void assert(const bool cond, const char* const err) {
	if (!cond) {
		pos(0, 0);
		color(VGA_COLOR_WHITE, VGA_COLOR_RED);
		print("ASSERTION FAILED: ");
		print(err);
		printchar('\n');
		pause();
	}
}
