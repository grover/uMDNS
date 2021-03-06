/**
 * umdns_logging.h
 * uMDNS Project
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 * @file umdns_logging.h
 *
 * Any project using uMDNS should #include <umdns/umdns.h> instead.
 *
 */

#ifndef UMDNS_UMDNS_LOGGING_H
#define UMDNS_UMDNS_LOGGING_H

#ifdef UMDNS_FEATURE_ENABLE_LOGGING

/**
 * @brief Logging extension function.
 *
 * It is the responsibility of the client to provide a logging function for
 * uMDNS. This function is only called if the logging feature toggle is enabled
 * at compile time.
 *
 * @param format
 * A printf style format string with the log message.
 *
 * @param ...
 * Any number of arguments required by the format string.
 *
 */
void umdnsx_log(const char *format, ...);

/**
 * @brief uMDNS logging macro
 *
 * Use this macro instead of direct umdnsx_log calls to enable the logging
 * feature toggle to work.
 *
 */
#define UMDNS_LOG(...) umdnsx_log(__VA_ARGS__)

#else // #ifdef UMDNS_FEATURE_ENABLE_LOGGING

#define UMDNS_LOG(...)

#endif // #ifdef UMDNS_FEATURE_ENABLE_LOGGING

#endif // #ifndef UMDNS_UMDNS_LOGGING_H
