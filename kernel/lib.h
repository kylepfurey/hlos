// .h
// OS Library Functions
// by Kyle Furey

#ifndef HLOS_LIB_H
#define HLOS_LIB_H

#include "types.h"

/** Returns the number of elements in an array. */
#define ARRAY_SIZE(array, type) (sizeof(array) / sizeof(type))

/** Halts the kernel. */
void pause();

/** Crashes the kernel with an error if the given condition is false. */
void assert(bool_t cond, string_t err);

/** Generates a unique hash code from the given data. */
uint_t hash(const void* data, uint_t size);

#endif // HLOS_LIB_H
