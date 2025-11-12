// .h
// OS Memory Allocation Functions
// by Kyle Furey

#ifndef HLOS_MALLOC_H
#define HLOS_MALLOC_H

#include "types.h"

/** Allocates the given number of bytes on the heap. */
void *malloc(uint_t size);

/** Allocates and zeroes out an array of the given size and count on the heap. */
void *calloc(uint_t count, uint_t size);

/** Reallocates the given heap memory to the given size. */
void *realloc(void *mem, uint_t size);

/** Releases the given memory from the heap. */
void free(void *mem);

#endif // HLOS_MALLOC_H
