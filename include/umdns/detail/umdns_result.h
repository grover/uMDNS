/**
 * umdns_result.h
 * uMDNS Project
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 * @file umdns_result.h
 * @brief uMDNS return code header.
 *
 * Any project should include #include <umdns/umdns.h> to gain
 * access to the full functionality.
 *
 */

#ifndef UMDNS_UMDNS_RESULT_H
#define UMDNS_UMDNS_RESULT_H

/**
 * @brief An enumeration of uMDNS result codes.
 */
typedef enum umdns_result {
  /// @brief Success return code
  kUMDNSOk = 0,
  /// @brief General failure code
  kUMDNSErrorFailed = -1,
  /// @brief A call was made to @ref umnds_init after it was already initialized
  kUMDNSErrorAlreadyInitialized = -2,
  /// @brief MDNS not initialized
  kUMDNSErrorNotInitialized = -3
} umdns_result_t;

#endif // #ifndef UMDNS_UMDNS_RESULT_H