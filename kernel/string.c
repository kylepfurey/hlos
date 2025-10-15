// .c
// OS String Type and Functions
// by Kyle Furey

#include "string.h"

/** Returns the length of a string. */
uint32_t strlen(const string_t str) {
	uint32_t length = 0;
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
bool strint(const string_t str, int32_t* const num) {
	// TODO
	return false;
}

/**
 * Converts a integer into a string.
 * The returned string is reused for all conversions.
 */
string_t intstr(const int32_t num) {
	static char buffer[12] = { 0 }; // Longest string: -2147483648\0
	// TODO
	return buffer;
}
