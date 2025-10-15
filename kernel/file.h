// .h
// OS File IO Functions
// by Kyle Furey

#ifndef HLOS_FILE_H
#define HLOS_FILE_H

#include "string.h"

/** The maximum size of a file (not including the file header). */
#define MAX_FILE_SIZE 1000000

/**
 * Reads the file at the given path for the given size.
 * Returns a string containing the file's data or NULL if no file was found.
 */
string_t fileread(const string_t path, const uint32_t size);

/**
 * Writes the given data to the given file path.
 * Returns whether an existing file was overwritten.
 */
bool filewrite(const string_t path, const string_t data);

/**
 * Appends the given data to the given file path.
 * Returns whether an existing file was appended to.
 */
bool fileappend(const string_t path, const string_t data);

/**
 * Moves the file from <start> to <end>.
 * Returns whether an existing file was overwritten at <end>.
 */
bool filemove(const string_t start, const string_t end);

/** Deletes the file at the given path and returns whether a file was erased. */
bool filedelete(const string_t path);

/** Returns whether a file exists and writes its size into <size>. */
bool filesize(const string_t path, uint32_t* const size);

#endif // HLOS_FILE_H
