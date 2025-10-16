// .h
// OS Dynamic Code Execution Function
// by Kyle Furey

#ifndef HLOS_EXEC_H
#define HLOS_EXEC_H

#include "types.h"

/**
 * Allocates a page of memory and executes the given HLOS code as a program.
 * Returns an error string or NULL on a successful execution.
 */
string_t exec(string_t code);

#endif // HLOS_EXEC_H
