// .h
// OS Input Reading Functions
// by Kyle Furey

#ifndef HLOS_READ_H
#define HLOS_READ_H

#include "string.h"

/** The maximum length of a received input string. */
#define MAX_INPUT_LEN MAX_STRING_LEN

/** Reads an input string from the user. */
string_t read();

/** Reads a single character from the user. */
char_t readchar();

/**
 * Reads an integer from the user.
 * If the user inputted a valid number, <num> is set to it.
 * Returns whether the read was successful.
 */
bool_t readint(int_t* num);

#endif // HLOS_READ_H
