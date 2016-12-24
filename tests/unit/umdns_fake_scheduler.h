/**
 * umdns_fake_scheduler.h
 * uMDNS
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 */

#include <umdns/umdns.h>

extern uint32_t schedule_calls;
extern uint32_t scheduled_timeout;
extern umdns_callback_fn_t scheduled_callback;
