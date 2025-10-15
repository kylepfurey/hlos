// .c
// OS Library
// by Kyle Furey

#include "lib.h"

/** Returns the length of a string. */
uint32_t len(const char* const str) {
	uint32_t length = 0;
	while (str[length] != '\0') {
		++length;
	}
	return length;
}
