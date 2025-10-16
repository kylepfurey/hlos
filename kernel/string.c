// .c
// OS String Functions
// by Kyle Furey

#include "string.h"

/** Returns the length of a string. */
uint_t strlen(string_t str) {
	if (str == NULL) {
		return 0;
	}
	uint_t length = 0;
	while (str[length] != '\0') {
		++length;
	}
	return length;
}

/**
 * Converts a string into an integer if possible.
 * <num> is set to the integer if <str> represents a valid integer.
 * Returns whether the string was successfully converted.
 */
bool_t strint(string_t str, int_t* num) {
	if (str == NULL) {
		return false;
	}
	// TODO
	return false;
}

/**
 * Converts a integer into a string.
 * The returned string is reused for all conversions.
 */
string_t intstr(int_t num) {
	static char_t buffer[12] = { 0 }; // Longest string: -2147483648\0
	// TODO
	return buffer;
}
