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
#include "umdns_responder.h"
#include "umdns_state.h"

#define MDNS_PROBING_INTERVAL_IN_MS 250

#define MDNS_PROBE_QUERIES 3

/**
 * @brief Holds the current call # to umdns_probe.
 *
 * Depending on the number, umdns_probe takes different actions:
 *
 * - Below MDNS_PROBE_QUERIES it sends out a query
 * - Above MDNS_PROBE_QUERIES and below MDNS_PROBE_TOTAL it sends out a flushing announcement
 * - Above MDNS_PROBE_TOTAL it switches to the responding mode
 *
 */
static int umdns_probing_attempt_ = 0;

/**
 * @brief Issues a single probe or announcement or switches to responding mode.
 *
 */
static void umdns_probe(void);

/**
 * @brief Sends a single probing query on the network.
 */
static void umdns_send_probing_query(void);

void umdns_start_probing() {
  umdns_state_t state = umdns_get_current_state();
  if (state != kShutdown && state != kNameConflictDetected) {
    return;
  }

  UMDNS_LOG("uMDNS: Start probing...\r\n");
  umdns_set_state(kProbing);
  umdnsx_schedule_callback(MDNS_PROBING_INTERVAL_IN_MS, &umdns_probe);
  umdns_probing_attempt_ = 0;
}

static void umdns_probe(void) {
  if (umdns_get_current_state() != kProbing) {
    return;
  }

  if (umdns_probing_attempt_ >= MDNS_PROBE_QUERIES) {
    umdns_start_responding();
    return;
  }

  umdns_send_probing_query();

  umdns_probing_attempt_++;
  umdnsx_schedule_callback(MDNS_PROBING_INTERVAL_IN_MS, &umdns_probe);
}

void umdns_send_probing_query(void) {
}
