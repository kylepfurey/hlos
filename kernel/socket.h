// .h
// OS Networking Socket Functions
// by Kyle Furey

#ifndef HLOS_SOCKET_H
#define HLOS_SOCKET_H

#include "string.h"

/** Represents a 32-bit IPv4 address. */
typedef union ip_address {
	/** Each byte of this IP address. */
	const uint8_t bytes[4];

	/** The numeric representation of this IP address. */
	const uint32_t number;
} ip_address_t;

/** Represents a remote socket connection. */
typedef struct socket {
	/** The IP address of this connection. */
	const ip_address_t ip;

	/** The port of this connection. */
	const uint16_t port;
} socket_t;

/** The maximum number of bytes sent and received from a socket at once. */
#define MAX_NET_SIZE 1024

/**
 * Attempts to connect to the given IP address and port.
 * If a connection is successful, <socket> is set to the connected socket.
 * Returns whether the connection was successful.
 */
bool connect(const ip_address_t ip, const uint16_t port, socket_t* const socket);

/**
 * Disconnects from the given socket.
 * Returns whether a connection was successfully terminated.
 */
bool disconnect(const socket_t socket);

/**
 * Sends data of the given size to the given socket.
 * Returns whether the data was successfully sent.
 */
bool send(const socket_t socket, const uint16_t size, const void* const data);

/**
 * Awaits a response from the given socket for the given number of milliseconds.
 * <size> is set to the amount of bytes received.
 * Returns an array of bytes of length <size>.
 */
void* receive(const socket_t socket, const uint16_t ms, uint16_t* const size);

#endif // HLOS_SOCKET_H
