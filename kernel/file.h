// .h
// OS File IO Functions
// by Kyle Furey

#ifndef HLOS_FILE_H
#define HLOS_FILE_H

#include "types.h"

/** The maximum size of a file (not including the file header). */
#define MAX_FILE_SIZE 1000000

/** Indicates the entire file will read. */
#define ENTIRE_FILE ((ulong_t)-1)

/**
 * Reads the file at the given path and offset for the given size.
 * Returns a string containing the file's data or NULL if no file was found.
 */
string_t fileread(const string_t path, const ulong_t offset, const ulong_t size);

/**
 * Writes the given data to the given file path.
 * Returns whether an existing file was overwritten.
 */
bool_t filewrite(const string_t path, const string_t data);

/**
 * Appends the given data to the given file path.
 * Returns whether an existing file was appended to.
 */
bool_t fileappend(const string_t path, const string_t data);

/**
 * Moves the file from <start> to <end>.
 * Returns whether an existing file was overwritten at <end>.
 */
bool_t filemove(const string_t start, const string_t end);

/** Deletes the file at the given path and returns whether a file was erased. */
bool_t filedelete(const string_t path);

/** Returns whether a file exists and writes its size into <size>. */
bool_t filesize(const string_t path, ulong_t* const size);

#endif // HLOS_FILE_H
