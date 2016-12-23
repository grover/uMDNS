/**
 * records.h
 * uMDNS Project
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 */

#ifndef UMDNS_RECORDS_H
#define UMDNS_RECORDS_H

#include <stdint.h>

// @brief Indicates an A record
#define UMDNS_A_RECORD   0x00
// @brief Indicates a PTR record
#define UMDNS_PTR_RECORD 0x01
// @brief Indicates an TXT record
#define UMDNS_TXT_RECORD 0x02
// @brief Indicates an SRV record
#define UMDNS_SRV_RECORD 0x03

/**
 * @brief Basic DNS resource record structure per RFC 1035.
 */
typedef struct umdns_record {
  /// @brief Pointer to the name of the resource
  const char*                 name;
  /// @brief The record type represented by this structure
  uint8_t                     type;
  /// @brief Pointer to a list of additional records that describe this
  const struct umdns_record** additional;
} umdns_record_t;

/**
 * @brief DNS A Record structure per RFC 1035.
 */
typedef struct umdns_a_record {
  /// @brief The DNS resource record header
  umdns_record_t record;
  /// @brief Pointer to the IPv4 address in host byte order.
  uint32_t* inaddr;
} umdns_a_record_t;

/**
 * @brief DNS TXT record structure per RFC 1035.
 */
typedef struct umdns_txt_record {
  /// @brief The DNS resource record header
  umdns_record_t record;
  /** 
   * @brief Poiter to an array of strings. 
   *
   * Each string in the record is limited to 255 characters.
   *
   * Last entry must be NULL. 
   */
  const char **txt;
} umdns_txt_record_t;

/**
 * @brief DNS PTR record structure per RFC 1035.
 */
typedef struct umdns_ptr_record {
  /// @brief The DNS resource record header
  umdns_record_t record;
  /**
   * @brief Zero terminated string representing the name pointed to.
   *
   * The name is limited to 63 characters per label and 255 characters total.
   *
   */
  const char* name;
} umdns_ptr_record_t;

/**
 * @brief DNS SRV record structure per RFC 2782.
 */
typedef struct umdns_srv_record {
  /// @brief The DNS resource record header
  umdns_record_t record;

  /// @brief The priority of the record in relation to other records.
  uint16_t priority;
  /// @brief Weight is used to select servers with the same priority.
  uint16_t weight;
  /// @brief The port number of the service on the host.
  uint16_t port;
  /// @brief The name of the the host that provides the service.
  const char *target;
} umdns_srv_record_t;

#endif // #ifndef UMDNS_RECORDS_H
