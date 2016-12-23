/**
 * umdns_state.h
 * uMDNS Project
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 */

#include <umdns/umdns.h>

static umdns_state_t umdns_state_ = kShutdown;

umdns_state_t umdns_get_current_state(void) {
  return umdns_state_;
}

void umdns_set_state(umdns_state_t state) {
  umdns_state_ = state;
}
