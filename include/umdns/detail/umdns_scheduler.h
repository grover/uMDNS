/**
 * umdns_state.h
 * uMDNS Project
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 * @file umdns_state.h
 * @brief uMDNS state headers.
 *
 * Any project should include #include <umdns/umdns.h> to gain
 * access to the full functionality.
 *
 */

#ifndef UMDNS_UMDNS_SCHEDULER_H
#define UMDNS_UMDNS_SCHEDULER_H

/**
 * @brief Callback function for scheduled callbacks.
 *
 * @see @ref umdns_schedule_callback
 *
 */
typedef void (*umdns_callback_fn_t)();

/**
 * @brief Schedules a callback after a certain time interval.
 *
 * This function is used by MDNS to perform probing and announcements at
 * regular intervals. Only one callback can be scheduled at any point in
 * time.
 *
 * @param time
 * Specifies the time in milliseconds after which the callback should be
 * executed. This is a relative time from now.
 *
 * @param callback
 * The callback to invoke after the time has expired.
 *
 * @retval UMDNS_OK
 * The callback was scheduled successfully.
 *
 * @retval UMDNS_ERR_ALREADY_SCHEDULED
 * A callback is already scheduled.
 *
 * @retval UMDNS_ERR_FAILED
 * The callback could not be scheduled due to other errors.
 *
 * @remarks
 * If a callback fails to be scheduled the uMDNS stack shuts down as the
 * external state potentially becomes corrupted. This basically causes
 * all MDNS reservations to become unreserved. Goodbye network packets are
 * sent.
 *
 */
extern umdns_result_t umdnsx_schedule_callback(
  uint32_t timeout,
  umdns_callback_fn_t callback);

#endif // #ifndef UMDNS_UMDNS_SCHEDULER_H
