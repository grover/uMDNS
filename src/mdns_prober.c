/**
 * mdns_prober.c
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

void umdns_start_probing() {
  umdns_state_t state = umdns_get_current_state();
  if (state != kShutdown && state != kNameConflictDetected) {
    return;
  }

  UMDNS_LOG("uMDNS: Start probing...\r\n");
  umdns_set_state(kProbing);
}
