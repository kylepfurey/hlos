// .h
// OS String Functions
// by Kyle Furey

#ifndef HLOS_STRING_H
#define HLOS_STRING_H

#include "types.h"

/** The maximum length of a string (including the null terminator). */
#define MAX_STRING_LEN 1028

/** Returns the length of a string. */
uint_t strlen(string_t str);

/**
 * Converts a string into an integer if possible.
 * <num> is set to the integer if <str> represents a valid integer.
 * Returns whether the string was successfully converted.
 */
bool_t strint(string_t str, int_t* num);

/**
 * Converts a integer into a string.
 * The returned string is reused for all conversions.
 */
string_t intstr(int_t num);

#endif // HLOS_STRING_H
