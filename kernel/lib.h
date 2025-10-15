// .h
// OS Library
// by Kyle Furey

#ifndef HLOS_LIB_H
#define HLOS_LIB_H

#include "extern.h"

/** Returns the number of elements in an array. */
#define ARRAY_SIZE(array, type) (sizeof(array) / sizeof(type))

/** Returns the length of a string. */
uint32_t len(const char* const str);

#endif // HLOS_LIB_H
