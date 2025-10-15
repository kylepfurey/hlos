// .c
// OS Networking Socket Functions
// by Kyle Furey

#include "socket.h"

/**
 * Attempts to connect to the given IP address and port.
 * If a connection is successful, <socket> is set to the connected socket.
 * Returns whether the connection was successful.
 */
bool connect(const ip_address_t ip, const uint16_t port, socket_t* const socket) {
	// TODO
	return false;
}

/**
 * Disconnects from the given socket.
 * Returns whether a connection was successfully terminated.
 */
bool disconnect(const socket_t socket) {
	// TODO
	return false;
}

/**
 * Disconnects from the given socket.
 * Returns whether a connection was successfully terminated.
 */
bool send(const socket_t socket, const uint16_t size, const void* const data) {
	// TODO
	return false;
}

/**
 * Awaits a response from the given socket for the given number of milliseconds.
 * <size> is set to the amount of bytes received.
 * Returns an array of bytes of length <size>.
 */
void* receive(const socket_t socket, const uint16_t ms, uint16_t* const size) {
	// TODO
	return NULL;
}
