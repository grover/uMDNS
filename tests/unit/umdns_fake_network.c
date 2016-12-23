/**
 * mdns.c
 * uMDNS
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 */

#include <umdns/umdns.h>

int socket_opened = 0;
int socket_closed = 0;

umdns_result_t umdnsx_open_socket() {
  socket_opened = 1;
  return kUMDNSOk;
}

void umdnsx_close_socket() {
  socket_closed = 1;
}

void umdnsx_send(const umdns_endpoint_t *recipient, const uint8_t *packet, size_t length) {
}
