/**
 * test_umdns_probing.c
 * uMDNS
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 */

#include <unity.h>

#include <umdns/umdns.h>
#include "mdns_prober.h"

#include "umdns_fake_scheduler.h"

void test_umdns_start_probing_changes_state_to_probing(void) {
  umdns_start_probing();
  TEST_ASSERT(umdns_get_current_state() == kProbing);
}

void test_umdns_start_probing_schedules_probing_callback(void) {
  umdns_start_probing();

  TEST_ASSERT(scheduled_callback != NULL);
  TEST_ASSERT(scheduled_timeout == 250);
}

void test_umdns_should_schedule_three_probing_queries_and_an_initial_callback(void) {
  umdns_start_probing();
  for (int i = 0; i < 4; i++) {
    scheduled_callback();
  }
  
  TEST_ASSERT(schedule_calls == 4);
}

void test_umdns_should_switch_to_responding_state_after_four_probing_callbacks(void) {
  umdns_start_probing();
  scheduled_callback();
  scheduled_callback();
  scheduled_callback();
  scheduled_callback();
  
  TEST_ASSERT(umdns_get_current_state() == kResponding);
}

// TODO: Shutdown while probing
// TODO: Record number of network sends
