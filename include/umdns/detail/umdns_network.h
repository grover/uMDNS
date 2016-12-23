/**
 * umdns_external.h
 * uMDNS Project
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 * The functions in this file need to be implemented by clients that
 * want to use the uMDNS library. They provide MDNS conflict notifications
 * as well as the minimal network interface required.
 *
 * @file umdns_external.h @include umdns/umdns_external.h
 *
 */

#ifndef UMDNS_UMDNS_NETWORK_H
#define UMDNS_UMDNS_NETWORK_H

/**
 * @brief Structure that represents an IPv4 endpoint.
 *
 * An instance of this structure is used to report incoming packet sources
 * and outgoing packet destinations. The incoming packets must be tagged
 * with an address in order to enable unicast responses.
 *
 */
typedef struct umdns_endpoint {
  /// @brief The IPv4 address in host byte order
  uint32_t address;
  /// @brief The IPv4 port in host byte order
  uint16_t port;
} umdns_endpoint_t;

/**
 * @brief Reports that a name conflict was detected.
 *
 * If this is called the MDNS responder has detected a name conflict, while
 * probing the network for the records it was configured to announce.
 *
 * When this function is called uMDNS stops probing, announcing and responding
 * to MDNS queries for the configured records. To enable MDNS again, it is
 * expected that the client of the library changes names in the MDNS records
 * and calls @ref mdns_restart_probing to restart MDNS.
 *
 * @remarks This function should be provided by the client of the library. 
 * There's no standard implementation for name conflict resolution.
 *
 */
extern void umdnsx_name_conflict_detected(void);

/**
 * @brief Called by uMDNS to initialize the network interface.
 *
 * This function should create a socket (or the equivalent on your platform),
 * bind it to port 5353 and join the MDNS multicast group.
 *
 * @retval @ref kUMDNSOk
 * Opening the socket and all of the above described steps have succeeded.
 *
 * @retval @ref kUMDNSErrorFailed
 * Opening the socket has failed. This will fail the initialization of uMDNS.
 *
 */
extern int umdnsx_open_socket();

/**
 * @brief Closes the network interface opened with @ref umdns_open_socket.
 *
 * This is the last function uMDNS calls as part of the shutdown process. It will
 * call this after all network packets have been sent via @ref umdns_send.
 *
 * The implementation should flush all pending network packets and shutdown the
 * network interface by leaving the multicast group and closing the interface.
 *
 */
extern void umdnsx_close_socket();

/**
 * @brief Sends a MDNS packet.
 *
 * This function is called by uMDNS to send packets. A recipient is optinally
 * specified that indicates a unicast MDNS response to be sent as a response
 * to a query.
 *
 * The packet and length are owned by uMDNS. If they are needed beyond the scope
 * of this function call, the callee has to make a copy.
 *
 * uMDNS is not interested in error conditions arising from the network
 * stack. These should be handled by the client by calling @ref umdns_shutdown
 * and @ref umdns_init appropriately.
 *
 * @param recipient
 * The unicast receiver of the packet. If this parameter is NULL, the packet
 * must be sent via the multicast group to all listening MDNS receivers.
 *
 * @param packet
 * The data of the MDNS packet to send.
 *
 * @param length
 * The number of bytes to send.
 *
 */
extern void umdnsx_send(
  const umdns_endpoint_t *recipient,
  const uint8_t *packet,
  size_t length);

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
 * @retval @ref kUMDNSOk
 * The packet was handled.
 *
 * @retval @ref kUMDNSErrorNotInitialized
 * uMDNS was not initialized with @ref umdns_init.
 *
 */
int umdns_packet_received(
    const umdns_endpoint_t *sender,
    const uint8_t *packet,
    size_t length);

#endif // #ifndef UMDNS_UMDNS_NETWORK_H
