/**
 * mdns.c
 * uMDNS
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 */

#include <unity.h>

#include <umdns/umdns.h>
#include "umdns_fake_network.h"

void test_umdns_init_succeeds_if_initialized(void) {
  umdns_result_t result = umdns_init();
  TEST_ASSERT(result == kUMDNSOk);
}

void test_umdns_shutdown_must_reset_state(void) {
  umdns_result_t result = umdns_init();
  TEST_ASSERT(result == kUMDNSOk);

  umdns_shutdown();
  TEST_ASSERT(umdns_get_current_state() == kShutdown);  
}

void test_umdns_init_fails_if_initialized_twice(void) {
  umdns_result_t result = umdns_init();
  TEST_ASSERT(result == kUMDNSOk);

  result = umdns_init();
  TEST_ASSERT(result == kUMDNSErrorAlreadyInitialized);
}

void test_should_open_socket_in_init(void) {
  umdns_result_t result = umdns_init();
  TEST_ASSERT(result == kUMDNSOk);

  TEST_ASSERT(socket_opened == 1);
}

void test_should_close_socket_in_shutdown(void) {
  umdns_result_t result = umdns_init();
  TEST_ASSERT(result == kUMDNSOk);

  umdns_shutdown();
  TEST_ASSERT(socket_closed == 1);
}

void test_should_not_close_socket_in_shutdown_if_not_initialized(void) {
  umdns_shutdown();
  TEST_ASSERT(socket_closed == 0);
}

void test_should_start_probing_when_initialized(void) {
  umdns_result_t result = umdns_init();
  TEST_ASSERT(result == kUMDNSOk);

  TEST_ASSERT(umdns_get_current_state() == kProbing);  
}
