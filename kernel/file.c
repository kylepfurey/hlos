// .c
// OS File IO Functions
// by Kyle Furey

#include "file.h"

/**
 * Reads the file at the given path for the given size.
 * Returns a string containing the file's data or NULL if no file was found.
 */
string_t fileread(string_t path, uint_t offset, uint_t size) {
	if (path == NULL) {
		return NULL;
	}
	// TODO
	return NULL;
}

/**
 * Writes the given data to the given file path.
 * Returns whether an existing file was overwritten.
 */
bool_t filewrite(string_t path, string_t data) {
	if (path == NULL) {
		return false;
	}
	// TODO
	return false;
}

/**
 * Appends the given data to the given file path.
 * Returns whether an existing file was appended to.
 */
bool_t fileappend(string_t path, string_t data) {
	if (path == NULL) {
		return false;
	}
	// TODO
	return false;
}

/**
 * Moves the file from <start> to <end>.
 * Returns whether an existing file was overwritten at <end>.
 */
bool_t filemove(string_t start, string_t end) {
	if (start == NULL || end == NULL) {
		return false;
	}
	// TODO
	return false;
}

/** Deletes the file at the given path and returns whether a file was erased. */
bool_t filedelete(string_t path) {
	if (path == NULL) {
		return false;
	}
	// TODO
	return false;
}

/** Returns whether a file exists and writes its size into <size>. */
bool_t filesize(string_t path, uint_t* size) {
	if (path == NULL) {
		return false;
	}
	// TODO
	return false;
}
