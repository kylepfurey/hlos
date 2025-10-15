// .c
// OS File IO Functions
// by Kyle Furey

#include "file.h"

/**
 * Reads the file at the given path for the given size.
 * Returns a string containing the file's data or NULL if no file was found.
 */
string_t fileread(const string_t path, const ulong_t offset, const ulong_t size) {
	// TODO
	return NULL;
}

/**
 * Writes the given data to the given file path.
 * Returns whether an existing file was overwritten.
 */
bool_t filewrite(const string_t path, const string_t data) {
	// TODO
	return false;
}

/**
 * Appends the given data to the given file path.
 * Returns whether an existing file was appended to.
 */
bool_t fileappend(const string_t path, const string_t data) {
	// TODO
	return false;
}

/**
 * Moves the file from <start> to <end>.
 * Returns whether an existing file was overwritten at <end>.
 */
bool_t filemove(const string_t start, const string_t end) {
	// TODO
	return false;
}

/** Deletes the file at the given path and returns whether a file was erased. */
bool_t filedelete(const string_t path) {
	// TODO
	return false;
}

/** Returns whether a file exists and writes its size into <size>. */
bool_t filesize(const string_t path, ulong_t* const size) {
	// TODO
	return false;
}
