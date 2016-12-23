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

#include "mdns_prober.h"
#include "umdns_state.h"

umdns_result_t umdns_init(void) {

  if (umdns_get_current_state() != kShutdown) {
    return kUMDNSErrorAlreadyInitialized;
  }

  UMDNS_LOG("uMDNS: Initializing...\r\n");
  umdns_result_t result = umdnsx_open_socket();
  if (result == kUMDNSOk) {
    umdns_start_probing();
  }

  return result;
}

void umdns_shutdown(void) {
  umdns_state_t state = umdns_get_current_state();
  if (state == kShutdown || state == kShuttingDown) {
    return;
  }

  UMDNS_LOG("uMDNS: Closing socket...\r\n");
  umdnsx_close_socket();
  umdns_set_state(kShutdown);
}

void umdns_restart_probing(void) {
}
