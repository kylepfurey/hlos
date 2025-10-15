// .c
// OS Print Functions
// by Kyle Furey

#include "print.h"

/** The Video Graphics Array. */
VGA_t VGA = {
	(volatile VGA_char_t* const)0xB8000,
	0,
	0,
	VGA_COLOR(VGA_COLOR_LIGHT_GRAY, VGA_COLOR_BLACK),
	0,
};

/** Prints a message to the Video Graphics Array. */
void print(const char* msg) {
	while (*msg != '\0') {
		if (*msg == '\n') {
			VGA.column = 0;
			++VGA.row;
		}
		else if (*msg == '\r') {
			VGA.column = 0;
		}
		else if (*msg == '\t') {
			print("    ");
		}
		else {
			const uint16_t i = VGA.row * VGA_WIDTH + VGA.column;
			VGA.array[i].character = *msg;
			VGA.array[i].color = VGA.color;
			++VGA.column;
			if (VGA.column >= VGA_WIDTH) {
				VGA.column = 0;
				++VGA.row;
			}
		}
		++msg;
		if (VGA.row >= VGA_HEIGHT) {
			clear();
		}
	}
}

/** Prints a character to the Video Graphics Array. */
void printchar(const char c) {
	static char buffer[2] = { 0 };
	*buffer = c;
	print(buffer);
}

/** Clears the Video Graphics Array. */
void clear() {
	for (uint16_t i = 0; i < VGA_SIZE; ++i) {
		VGA.array[i].character = ' ';
		VGA.array[i].color = VGA.color;
	}
	VGA.column = 0;
	VGA.row = 0;
}

/** Sets the current color of the Video Graphics Array. */
void color(const VGA_color_t fg, const VGA_color_t bg) {
	VGA.color = VGA_COLOR(fg, bg);
}

/**
 * Sets the current column and row of the Video Graphics Array.
 * Returns the character at that position.
 */
char pos(const uint8_t col, const uint8_t row) {
	VGA.column = col % VGA_WIDTH;
	VGA.row = row % VGA_HEIGHT;
	return VGA.array[VGA.row * VGA_WIDTH + VGA.column].character;
}
