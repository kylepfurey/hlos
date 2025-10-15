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
void assert(const bool_t cond, const string_t err);

/** Generates a unique hash code from the given data. */
ulong_t hash(const void* const data, const ulong_t size);

/** Returns whether the data in <left> and <right> is equal. */
bool_t compare(const void* const left, const void* const right, const ulong_t size);

/** Copies <src> into <dest> for the given size. */
void copy(const void* const src, void* const dest, const ulong_t size);

#endif // HLOS_LIB_H
