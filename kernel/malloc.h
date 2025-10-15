// .h
// OS Memory Allocation Functions
// by Kyle Furey

#ifndef HLOS_MALLOC_H
#define HLOS_MALLOC_H

#include "extern.h"

/** Allocates the given number of bytes on the heap. */
void* malloc(const uint32_t size);

/** Allocates and zeroes out an array of the given size and count on the heap. */
void* calloc(const uint32_t count, const uint32_t size);

/** Reallocates the given heap memory to the given size. */
void* realloc(void* const mem, const uint32_t size);

/** Releases the given memory from the heap. */
void free(void* const mem);

#endif // HLOS_MALLOC_H
