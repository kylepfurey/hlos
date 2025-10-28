// .c
// OS String Functions
// by Kyle Furey

#include "string.h"
#include "lib.h"

/** Returns whether the given character is a letter. */
bool_t isletter(char_t c) {
	// TODO
	return false;
}

/** Returns whether the given character is a number. */
bool_t isnumber(char_t c) {
	// TODO
	return false;
}

/** Returns whether the given character is whitespace. */
bool_t isspace(char_t c) {
	// TODO
	return false;
}

/** Returns whether the given character is an uppercase letter. */
bool_t isupper(char_t c) {
	// TODO
	return false;
}

/** Returns whether the given character is a lowercase letter. */
bool_t islower(char_t c) {
	// TODO
	return false;
}

/** Returns the uppercase version of the given character. */
char_t upper(char_t c) {
	// TODO
	return c;
}

/** Returns the lowercase version of the given character. */
char_t lower(char_t c) {
	// TODO
	return c;
}

/** Returns the length of a string. */
uint_t strlen(string_t str) {
	assert(str != NULL, "strlen() - str was NULL!");
	uint_t length = 0;
	while (str[length] != '\0') {
		++length;
	}
	return length;
}

/** Safely copies <src> into <dest> with proper null-termination. Returns <dest>. */
char_t* strcopy(char_t* dest, string_t src) {
	assert(dest != NULL, "strcopy() - dest was NULL!");
	assert(src != NULL, "strcopy() - src was NULL!");
	// TODO
	return dest;
}

/**
 * Compares <left> and <right> character by character.
 * Returns a comparison enum of <left> to <right> for the first differing character.
 */
comparison_t strcompare(string_t left, string_t right) {
	assert(left != NULL, "strcompare() - left was NULL!");
	assert(right != NULL, "strcompare() - right was NULL!");
	// TODO
	return EQUAL_TO;
}

/** Safely sets each character in <str> to <c>. Returns <str>. */
char_t* strset(char_t* str, char_t c) {
	assert(str != NULL, "strset() - str was NULL!");
	// TODO
	return str;
}

/** Safely swaps the characters of <left> and <right> with proper null-termination. Returns <left>. */
char_t* strswap(char_t* left, char_t* right) {
	assert(left != NULL, "strswap() - left was NULL!");
	assert(right != NULL, "strswap() - right was NULL!");
	// TODO
	return left;
}

/** Safely reverses each character in <str>. Returns <str>. */
char_t* strflip(char_t* str) {
	assert(str != NULL, "strflip() - str was NULL!");
	// TODO
	return str;
}

/** Returns the index of the first character that matches <c> in <str> (or NOT_FOUND). */
uint_t strfirst(string_t str, char_t c) {
	assert(str != NULL, "strfirst() - str was NULL!");
	// TODO
	return NOT_FOUND;
}

/** Returns the index of to the last character that matches <c> in <str> (or NOT_FOUND). */
uint_t strlast(string_t str, char_t c) {
	assert(str != NULL, "strlast() - str was NULL!");
	// TODO
	return NOT_FOUND;
}

/** Returns the first index of where <src> was found in <dest> (or NOT_FOUND). */
uint_t strfind(string_t dest, string_t src) {
	assert(dest != NULL, "strfind() - dest was NULL!");
	assert(src != NULL, "strfind() - src was NULL!");
	// TODO
	return NOT_FOUND;
}

/** Safely appends the characters in <src> to <dest> with proper null-termination. Returns <dest>. */
char_t* strappend(char_t* dest, string_t src) {
	assert(dest != NULL, "strappend() - dest was NULL!");
	assert(src != NULL, "strappend() - src was NULL!");
	// TODO
	return dest;
}

/** Safely copies <len> characters in <src> to <dest> with proper null-termination. Returns <dest>. */
char_t* substring(char_t* dest, string_t src, uint_t len) {
	assert(dest != NULL, "substring() - dest was NULL!");
	assert(src != NULL, "substring() - src was NULL!");
	// TODO
	return dest;
}

/** Converts all characters in <str> to uppercase. Returns <str>. */
char_t* strupper(char_t* str) {
	assert(str != NULL, "strupper() - str was NULL!");
	// TODO
	return str;
}

/** Converts all characters in <str> to lowercase. Returns <str>. */
char_t* strlower(char_t* str) {
	assert(str != NULL, "strlower() - str was NULL!");
	// TODO
	return str;
}

/** Safely normalizes all characters in <str> with proper null-termination. Returns <str>. */
char_t* strnormal(char_t* str) {
	assert(str != NULL, "strnormal() - str was NULL!");
	// TODO
	return str;
}

/**
 * Transforms all characters in <str>. Returns <str>.
 * <trans> is a pointer to a function that inputs the index of the current character,
 * a pointer to the current character, and returns whether it should be reinserted.
 */
char_t* strtrans(char_t* str, bool_t(*trans)(uint_t, char_t*)) {
	assert(str != NULL, "strtrans() - str was NULL!");
	assert(trans != NULL, "strtrans() - trans was NULL!");
	// TODO
	return str;
}

/**
 * Converts a string into an integer if possible.
 * <num> is set to the integer if <str> represents a valid integer.
 * Returns whether the string was successfully converted.
 */
bool_t strint(string_t str, int_t* num) {
	assert(str != NULL, "strint() - str was NULL!");
	// TODO
	return false;
}

/**
 * Converts a integer into a string.
 * The returned string is reused for all conversions.
 */
string_t intstr(int_t num) {
	static char_t buffer[12] = { 0 }; // Longest string: -2147483648\0
	// TODO
	return buffer;
}
