// .c
// OS Library Functions
// by Kyle Furey

#include "lib.h"
#include "print.h"

/** Halts the kernel. */
void pause() {
	while (true);
}

/** Crashes the kernel with an error if the given condition is false. */
void assert(bool_t cond, string_t err) {
	if (!cond) {
		pos(0, 0);
		color(VGA_COLOR_WHITE, VGA_COLOR_RED);
		print("ASSERTION FAILED: ");
		print(err);
		printchar('\n');
		pause();
	}
}

/** Generates a unique hash code from the given data. */
uint_t hash(const void* data, uint_t size) {
	if (data == NULL) {
		return 0;
	}
	// FNV-1a
	byte_t* ptr = (byte_t*)data;
	uint_t hash = 2166136261u; // FNV offset
	for (uint_t i = 0; i < size; ++i) {
		hash ^= ptr[i];
		hash *= 16777619u; // FNV prime
	}
	return hash;
}
