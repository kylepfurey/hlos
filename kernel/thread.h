// .h
// OS Multithreading Function
// by Kyle Furey

#ifndef HLOS_THREAD_H
#define HLOS_THREAD_H

#include "types.h"

/**
 * Executes the given function asynchronously on the next available hardware thread.
 * <func> is a function pointer with a void pointer to arguments as a parameter and no return type.
 * Returns whether the thread was able to run immediately.
 */
bool_t thread(void(*func)(void*));

#endif // HLOS_THREAD_H
