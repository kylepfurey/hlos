// .h
// OS Buffer Struct
// by Kyle Furey

#ifndef HLOS_BUFFER_H
#define HLOS_BUFFER_H

#include "lib.h"

/** An ID used to locate data within a buffer. */
typedef uint32_t bid_t;

/** Declares the struct and functions of a fixed-sized buffer of the given type and size with the given name. */
#define DECLARE_BUFFER_NAMED(type, size, name)\
\
/** A fixed-sized buffer of a certain type and size. */\
typedef struct {\
	/** The underlying array containing the data of this buffer. */\
	type buffer[size];\
\
	/** A bitset used to check whether data is being stored in this buffer. */\
	uint8_t available[(size + 7) / 8];\
\
	/** The current number of spaces occupied in this buffer. */\
	uint32_t count;\
\
	/** The next available ID in this buffer. */\
	bid_t next_id;\
} name;\
\
/** The maximum size of this type of buffer. */\
enum {\
	name##_SIZE = size\
};\
\
/** Allocates a new zeroed-out buffer. */\
name name##_new();\
\
/** Inserts new data into the given buffer and returns its ID. */\
bid_t name##_insert(name *const self, const type data);\
\
/** Erases the data in the given buffer with the given ID and returns whether it was successful. */\
bool name##_erase(name *const self, const bid_t id);\
\
/** Returns a pointer to the data in the given buffer with the given ID, or NULL if no data exists. */\
type *name##_find(name *const self, const bid_t id);\
\
/** Returns a const pointer to the data in the given buffer with the given ID, or NULL if no data exists. */\
const type *name##_find_const(const name *const self, const bid_t id);\
\
/** Returns whether the given buffer has data associated with the given ID. */\
bool name##_contains(const name *const self, const bid_t id);\
\
/** Clears the given buffer. */\
uint32_t name##_clear(name *const self);\
\
/** Iterates through the given buffer with the given function and returns whether the iteration successfully completed. */\
bool name##_foreach(name *const self, bool(*const action)(type*));\
\
/** Iterates through the given buffer with the given const function and returns whether the iteration successfully completed. */\
bool name##_foreach_const(const name *const self, bool(*const action)(const type*));

/** Defines the functions of a fixed-sized buffer of the given type and size with the given name. */
#define DEFINE_BUFFER_NAMED(type, size, name)\
\
/** Allocates a new zeroed-out buffer. */\
name name##_new() {\
	return (name){0};\
}\
\
/** Inserts new data into the given buffer and returns its ID. */\
bid_t name##_insert(name *const self, const type data) {\
	if (self == NULL) {\
		return (bid_t)-1;\
	}\
	if (self->count >= size) {\
		assert(false, "Buffer overflow in "#name" of size "#size"!");\
		return (bid_t)-1;\
	}\
	const bid_t id = self->next_id++;\
	self->buffer[id] = data;\
	self->available[id / 8] |= 1u << (id % 8);\
	++self->count;\
	while (self->next_id < size && (self->available[self->next_id / 8] & 1u << (self->next_id % 8)) != 0) {\
		++self->next_id;\
	}\
	return id;\
}\
\
/** Erases the data in the given buffer with the given ID and returns whether it was successful. */\
bool name##_erase(name *const self, const bid_t id) {\
	if (self == NULL || id >= size || (self->available[id / 8] & 1u << (id % 8)) == 0) {\
		return false;\
	}\
	self->buffer[id] = (type){0};\
	self->available[id / 8] &= ~(1u << (id % 8));\
	--self->count;\
	self->next_id = id < self->next_id ? id : self->next_id;\
	return true;\
}\
\
/** Returns a pointer to the data in the given buffer with the given ID, or NULL if no data exists. */\
type *name##_find(name *const self, const bid_t id) {\
	if (self == NULL || id >= size || (self->available[id / 8] & 1u << (id % 8)) == 0) {\
		return NULL;\
	}\
	return &self->buffer[id];\
}\
\
/** Returns a const pointer to the data in the given buffer with the given ID, or NULL if no data exists. */\
const type *name##_find_const(const name *const self, const bid_t id) {\
	if (self == NULL || id >= size || (self->available[id / 8] & 1u << (id % 8)) == 0) {\
		return NULL;\
	}\
	return &self->buffer[id];\
}\
\
/** Returns whether the given buffer has data associated with the given ID. */\
bool name##_contains(const name *const self, const bid_t id) {\
	if (self == NULL || id >= size) {\
		return false;\
	}\
	return (self->available[id / 8] & 1u << (id % 8)) != 0;\
}\
\
/** Clears the given buffer. */\
uint32_t name##_clear(name *const self) {\
	if (self == NULL) {\
		return 0;\
	}\
	const uint32_t count = self->count;\
	*self = (name){0};\
	return count;\
}\
\
/** Iterates through the given buffer with the given function and returns whether the iteration successfully completed. */\
bool name##_foreach(name *const self, bool(*const action)(type*)) {\
	if (self == NULL) {\
		return false;\
	}\
	uint32_t count = self->count;\
	for (bid_t id = 0; id < size && count > 0; ++id) {\
		if ((self->available[id / 8] & 1u << (id % 8)) != 0) {\
			--count;\
			if (!action(&self->buffer[id])) {\
				return false;\
			}\
		}\
	}\
	return true;\
}\
\
/** Iterates through the given buffer with the given const function and returns whether the iteration successfully completed. */\
bool name##_foreach_const(const name *const self, bool(*const action)(const type*)) {\
	if (self == NULL) {\
		return false;\
	}\
	uint32_t count = self->count;\
	for (bid_t id = 0; id < size && count > 0; ++id) {\
		if ((self->available[id / 8] & 1u << (id % 8)) != 0) {\
			--count;\
			if (!action(&self->buffer[id])) {\
				return false;\
			}\
		}\
	}\
	return true;\
}

/** Declares the struct and functions of a fixed-sized buffer of the given type and size. */
#define DECLARE_BUFFER(type, size) DECLARE_BUFFER_NAMED(type, size, type##_buffer_##size)

/** Defines the functions of a fixed-sized buffer of the given type and size. */
#define DEFINE_BUFFER(type, size) DEFINE_BUFFER_NAMED(type, size, type##_buffer_##size)

#endif // HLOS_BUFFER_H
