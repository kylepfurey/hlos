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

#endif // HLOS_EXEC_H
