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

#include "umdns_config.h"
#include "detail/umdns_logging.h"
#include "detail/umdns_result.h"
#include "detail/umdns_records.h"
#include "detail/umdns_state.h"
#include "detail/umdns_scheduler.h"
#include "detail/umdns_network.h"

/**
 * @brief Initializes uMDNS.
 *
 * @returns kUMDNSOk
 * Initialization has succeeded.
 *
 * @returns kUMDNSErrorAlreadyInitialized
 * uMDNS has already been initialized. The second call was ignored.
 *
 */
umdns_result_t umdns_init(void);

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
 * to umdns_name_conflict_detected, it should call this function
 * to restart probing.
 *
 */
void umdns_restart_probing(void);

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
