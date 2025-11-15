// .h
// OS Dynamic Code Execution Function
// by Kyle Furey

#ifndef HLOS_EXEC_H
#define HLOS_EXEC_H

#include "types.h"

/** The return instruction in machine code. */
#define RET 0xC3

/** Dynamically executes the given string as assembled machine code. */
void exec(string_t code);

/**
 * Dynamically executes the given string as a shell-like command script.
 * Returns an error string or NULL if the script completed successfully.
 */
string_t cmd(string_t script);

#endif // HLOS_EXEC_H
