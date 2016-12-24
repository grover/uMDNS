/**
 * mdns_responder.c
 * uMDNS
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 */

#include "umdns_responder.h"

#include "umdns_state.h"

void umdns_start_responding(void) {
  umdns_set_state(kResponding);
}
