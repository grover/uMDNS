/**
 * umdns_fake_scheduler.c
 * uMDNS
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 */

#include "umdns_fake_scheduler.h"

uint32_t schedule_calls = 0;
uint32_t scheduled_timeout = 0;
umdns_callback_fn_t scheduled_callback = NULL;

umdns_result_t umdnsx_schedule_callback(
  uint32_t timeout,
  umdns_callback_fn_t callback)
{
  schedule_calls++;
  scheduled_timeout = timeout;
  scheduled_callback = callback;

  return kUMDNSOk;  
}
