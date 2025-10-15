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
void assert(const bool_t cond, const string_t err) {
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
ulong_t hash(const void* const data, const ulong_t size) {
	if (data == NULL) {
		return 0;
	}
	// FNV-1a
	byte_t* const ptr = (byte_t* const)data;
	ulong_t hash = 2166136261u; // FNV offset
	for (ulong_t i = 0; i < size; i++) {
		hash ^= ptr[i];
		hash *= 16777619u; // FNV prime
	}
	return hash;
}

/** Returns whether the data in <left> and <right> is equal. */
bool_t compare(const void* const left, const void* const right, const ulong_t size) {
	const byte_t* const left_data = (const byte_t* const)left;
	const byte_t* const right_data = (const byte_t* const)right;
	for (ulong_t i = 0; i < size; i++) {
		if (left_data[i] != right_data[i]) {
			return false;
		}
	}
	return true;
}

/** Copies <src> into <dest> for the given size. */
void copy(const void* const src, void* const dest, const ulong_t size) {
	const byte_t* const src_data = (const byte_t* const)src;
	byte_t* const dest_data = (byte_t* const)dest;
	for (ulong_t i = 0; i < size; i++) {
		dest_data[i] = src_data[i];
	}
}
