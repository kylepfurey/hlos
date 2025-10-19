// .c
// OS Input Reading Functions
// by Kyle Furey

#include "read.h"
#include "lib.h"

/** Reads an input string from the user. */
string_t read() {
	static char_t buffer[MAX_INPUT_LEN] = { 0 };
	// TODO
	return buffer;
}

/** Reads a single character from the user. */
char_t readchar() {
	// TODO
	return 0;
}

/**
 * Reads an integer from the user.
 * If the user inputted a valid number, <num> is set to it.
 * Returns whether the read was successful.
 */
bool_t readint(int_t* num) {
	return strint(read(), num);
}
