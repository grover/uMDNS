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

void test_umdns_init_succeeds_if_initialized(void);
void test_umdns_shutdown_must_reset_state(void);
void test_umdns_init_fails_if_initialized_twice(void);
void test_should_open_socket_in_init(void);
void test_should_close_socket_in_shutdown(void);
void test_should_not_close_socket_in_shutdown_if_not_initialized(void);
void test_should_start_probing_when_initialized(void);

void setUp(void) {
  socket_opened = 0;
  socket_closed = 0;
}

void tearDown(void) {
  umdns_shutdown();
}

int main(int argc, char **argv) {
  UNITY_BEGIN();
  RUN_TEST(test_umdns_init_succeeds_if_initialized);
  RUN_TEST(test_umdns_shutdown_must_reset_state);
  RUN_TEST(test_umdns_init_fails_if_initialized_twice);
  RUN_TEST(test_should_open_socket_in_init);
  RUN_TEST(test_should_close_socket_in_shutdown);
  RUN_TEST(test_should_not_close_socket_in_shutdown_if_not_initialized);
  RUN_TEST(test_should_start_probing_when_initialized);
  UNITY_END();

  return 0;
}
