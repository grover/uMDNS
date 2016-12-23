/**
 * umdns.h
 * uMDNS Project
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 * @file umdns.h
 * @brief uMDNS main header
 *
 * Any project should include this file to gain access to all functions
 * exposed by uMDNS.
 *
 */

#ifndef UMDNS_UMDNS_H
#define UMDNS_UMDNS_H

#include <stdint.h>
#include <stdlib.h>

#include "records.h"
#include "umdns_external.h"

/// @brief Success return code
#define UMDNS_OK (0)
/// @brief General failure code
#define UMDNS_ERR_FAILED (-1)
/// @brief MDNS not initialized
#define UMDNS_ERR_NOT_INITIALIZED (-2)

/**
 * @brief Initializes uMDNS.
 *
 * @retval @ref MDNS_OK
 * Initialization has succeeded.
 *
 */
int umdns_init(void);

/**
 * @brief Shuts down uMDNS.
 *
 * A shutdown sends MDNS goodbye packets and closes the network
 * interface.
 *
 */
void umdns_shutdown(void);

/**
 * @brief Restarts probing after name conflicts.
 *
 * After the client has created new MDNS names in response to a call
 * to @ref umdns_name_conflict_detected, it should call this function
 * to restart probing.
 *
 */
void umdns_restart_probing(void);

/**
 * @brief Passes data received from the socket to uMDNS.
 *
 * This function will process any incoming data from the socket and
 * will handle it according to the current internal uMDNS state. This
 * includes responding to queries.
 *
 * @param sender
 * The IPv4 endpoint information of the sender of the MDNS packet.
 *
 * @param packet
 * A pointer to the buffer of the just received data packet. The caller
 * keeps ownership of the buffer. uMDNS will not keep references to this
 * past the return of this function.
 *
 * @param length
 * The number of bytes in packet.
 *
 * @retval @ref UMDNS_OK
 * The packet was handled.
 *
 * @retval @ref UMDNS_ERR_NOT_INITIALIZED
 * uMDNS was not initialized with @ref umdns_init.
 *
 */
int umdns_packet_received(
    const umdns_endpoint_t *sender,
    const uint8_t *packet,
    size_t length);

/**
 * @mainpage uMDNS source code documentation
 *
 * This was generated using Doxygen (See http://www.stack.nl/~dimitri/doxygen/) from
 * the source code of uMDNS (See http://github.com/grover/uMDNS).\n
 * \n
 * uMDNS is an RFC 6762 compatible implementation of an MDNS responder for small,
 * connected microcontrollers. It is possible to run this pure C library on other
 * systems as well.
 *
 */

#endif // #ifndef UMDNS_UMDNS_H
