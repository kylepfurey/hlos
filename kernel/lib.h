// .h
// OS Library
// by Kyle Furey

#ifndef HLOS_LIB_H
#define HLOS_LIB_H

#include "string.h"

/** Returns the number of elements in an array. */
#define ARRAY_SIZE(array, type) (sizeof(array) / sizeof(type))

/** Halts the kernel. */
void pause();

/** Crashes the kernel with an error if the given condition is false. */
void assert(const bool cond, const string_t err);

#endif // HLOS_LIB_H
