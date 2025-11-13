// .c
// OS Dynamic Code Execution Function
// by Kyle Furey

#include "exec.h"
#include "lib.h"
#include "assembly.h"

/** Dynamically executes the given string as assembled machine code. */
void exec(string_t code) {
    assert(code != NULL, "exec() - code was NULL!");
    call(code);
}
