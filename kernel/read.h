// .h
// OS Input Reading Functions
// by Kyle Furey

#ifndef HLOS_READ_H
#define HLOS_READ_H

#include "string.h"

/** Reads an input string from the user. */
string_t read();

/** Reads a single character from the user. */
char readchar();

/**
 * Reads an integer from the user.
 * If the user inputted a valid number, <num> is set to it.
 * Returns whether the read was successful.
 */
bool readint(int32_t* const num);

#endif // HLOS_READ_H
