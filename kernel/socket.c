// .c
// OS Networking Socket Functions
// by Kyle Furey

#include "socket.h"

/**
 * Attempts to connect to the given IP address and port.
 * If a connection is successful, <socket> is set to the connected socket.
 * Returns whether the connection was successful.
 */
bool_t connect(const ip_address_t ip, const uint_t port, socket_t* const socket) {
	// TODO
	return false;
}

/**
 * Disconnects from the given socket.
 * Returns whether a connection was successfully terminated.
 */
bool_t disconnect(const socket_t socket) {
	// TODO
	return false;
}

/**
 * Sends data of the given size to the given socket.
 * Returns whether the data was successfully sent.
 */
bool_t send(const socket_t socket, const void* const data, const ulong_t size) {
	// TODO
	return false;
}

/**
 * Awaits a response from the given socket for the given number of milliseconds.
 * <size> is set to the amount of bytes received.
 * Returns an array of bytes of length <size>.
 */
void* receive(const socket_t socket, const ulong_t ms, ulong_t* const size) {
	// TODO
	return NULL;
}
