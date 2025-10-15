// .h
// OS Input Reading Functions
// by Kyle Furey

#ifndef HLOS_READ_H
#define HLOS_READ_H

#include "types.h"

/** Reads an input string from the user. */
string_t read();

/** Reads a single character from the user. */
char_t readchar();

/**
 * Reads an integer from the user.
 * If the user inputted a valid number, <num> is set to it.
 * Returns whether the read was successful.
 */
bool_t readint(long_t* const num);

#endif // HLOS_READ_H
