// .c
// OS Memory Allocation Functions
// by Kyle Furey

#include "malloc.h"

/** Allocates the given number of bytes on the heap. */
void* malloc(uint_t size) {
	if (size == 0) {
		return NULL;
	}
	// TODO
	return NULL;
}

/** Allocates and zeroes out an array of the given size and count on the heap. */
void* calloc(uint_t count, uint_t size) {
	uint_t total = count * size;
	byte_t* mem = (byte_t*)malloc(total);
	if (mem == NULL) {
		return NULL;
	}
	for (uint_t i = 0; i < total; ++i) {
		mem[i] = 0;
	}
	return mem;
}

/** Reallocates the given heap memory to the given size. */
void* realloc(void* mem, uint_t size) {
	if (mem == NULL) {
		return NULL;
	}
	// TODO
	return NULL;
}

/** Releases the given memory from the heap. */
void free(void* mem) {
	// TODO
}
