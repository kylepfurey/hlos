// .c
// OS Input Reading Functions
// by Kyle Furey

#include "read.h"

/** Reads an input string from the user. */
string_t read() {
	static char buffer[MAX_STRING_LEN] = { 0 };
	// TODO
	return buffer;
}

/** Reads a single character from the user. */
char readchar() {
	// TOOD
	return 0;
}

/**
 * Reads an integer from the user.
 * If the user inputted a valid number, <num> is set to it.
 * Returns whether the read was successful.
 */
bool readint(int32_t* const num) {
	return strint(read(), num);
}
