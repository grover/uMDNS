/**
 * mdns_responder.c
 * uMDNS
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 */

#ifndef UMDNS_RESPONDER_H
#define UMDNS_RESPONDER_H

/**
 * @brief Starts the responder.
 *
 * The responder starts by sending out multiple flushing responses holding 
 * all resource records. After these initial responses the responder keeps
 * announcing them at 50% of the TTL.
 *
 * The responder starts responding to queries for the resource records
 * immediately with the call to this function.
 *
 */
void umdns_start_responding(void);

#endif // #ifndef UMDNS_RESPONDER_H
