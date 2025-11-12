// .c
// OS Networking Socket Functions
// by Kyle Furey

#include "socket.h"
#include "lib.h"

/**
 * Attempts to connect to the given IP address and port.
 * If a connection is successful, <socket> is set to the connected socket.
 * Returns whether the connection was successful.
 */
bool_t connect(ip_address_t ip, ushort_t port, socket_t *socket) {
    assert(socket != NULL, "connect() - socket was NULL!");
    // TODO
    return false;
}

/**
 * Disconnects from the given socket.
 * Returns whether a connection was successfully terminated.
 */
bool_t leave(const socket_t *socket) {
    assert(socket != NULL, "leave() - socket was NULL!");
    // TODO
    return false;
}

/**
 * Sends data of the given size to the given socket.
 * Returns whether the data was successfully sent.
 */
bool_t send(const socket_t *socket, const void *data, uint_t size) {
    assert(socket != NULL, "send() - socket was NULL!");
    assert(data != NULL, "send() - data was NULL!");
    // TODO
    return false;
}

/**
 * Awaits a response from the given socket for the given number of milliseconds.
 * <size> is set to the amount of bytes received.
 * Returns an array of bytes of length <size>.
 */
void *receive(const socket_t *socket, uint_t ms, uint_t *size) {
    assert(socket != NULL, "receive() - socket was NULL!");
    // TODO
    return NULL;
}
