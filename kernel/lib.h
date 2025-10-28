// .h
// OS Library Functions
// by Kyle Furey

#ifndef HLOS_LIB_H
#define HLOS_LIB_H

#include "types.h"

/** Returns the number of elements in an array. */
#define ARRAY_SIZE(array, type) (sizeof(array) / sizeof(type))

/** An indicator that a value was not found. */
#define NOT_FOUND ((uint_t)-1)

/** An enumeration of different comparison results. */
typedef enum comparison {
	LESS_THAN = -1,
	EQUAL_TO = 0,
	GREATER_THAN = 1
} comparison_t;

/** Halts the kernel. */
void pause();

/** Crashes the kernel with an error if the given condition is false. */
void assert(bool_t cond, string_t err);

/** Generates a unique hash code from the given data. */
uint_t hash(const void* data, uint_t size);

/** Copies <size> number of bytes from <src> into <dest> without overlap. Returns <dest>. */
void* copy(void* dest, const void* src, uint_t size);

/**
 * Compares <left> and <right> byte by byte for <size>.
 * Returns a comparison enum of <left> to <right> for the first differing byte.
 */
comparison_t compare(const void* left, const void* right, uint_t size);

/** Sets each byte of <dest> to <num> for <size>. Returns <dest>. */
void* set(void* dest, byte_t num, uint_t size);

/** Swaps each byte of <left> and <right> for <size>. Returns <left>. */
void* swap(void* left, void* right, uint_t size);

/** Reverses <size> number of bytes in <src>. Returns <src>. */
void* flip(void* src, uint_t size);

/** Finds the first matching byte equal to <num> for <size> and returns its index (or NOT_FOUND). */
uint_t first(const void* src, byte_t num, uint_t size);

/** Finds the last matching byte equal to <num> for <size> and returns its index (or NOT_FOUND). */
uint_t last(const void* src, byte_t num, uint_t size);

/**
 * Returns the index of the first byte where the value of <src> of size <size2>
 * is located within <dest> within <size1> bytes (or NOT_FOUND).
 */
uint_t find(const void* dest, uint_t size1, const void* src, uint_t size2);

/** Copies <src> of size <size2> right after <dest> at <size1>. Returns <dest>. */
void* append(void* dest, uint_t size1, const void* src, uint_t size2);

#endif // HLOS_LIB_H
