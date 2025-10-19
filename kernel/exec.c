// .c
// OS Dynamic Code Execution Function
// by Kyle Furey

#include "exec.h"
#include "lib.h"

/**
 * Allocates a page of memory and executes the given HLOS code as a program.
 * Returns an error string or NULL on a successful execution.
 */
string_t exec(string_t code) {
	assert(code != NULL, "exec() - code was NULL!");
	// TODO
	return NULL;
}
