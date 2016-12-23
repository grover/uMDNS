/**
 * umdns_state.h
 * uMDNS Project
 *
 * Copyright (c) 2016 Michael Fröhlich. All rights reserved.  
 * Licensed under the MIT License. See LICENSE.md file at 
 * https://github.com/grover/uMDNS for full license information.
 *
 * @file umdns_state.h
 *
 * Any project using uMDNS should #include <umdns/umdns.h> instead.
 *
 */

#ifndef UMDNS_UMDNS_STATE_H
#define UMDNS_UMDNS_STATE_H

/**
 * @brief An enumeration of uMDNS states.
 */
typedef enum umdns_state {
  /**
   * @brief uMDNS is inactive.
   *
   * In this state the network interface is disabled.
   *
   */
  kShutdown,

  /**
   * @brief uMDNS is probing for network names.
   *
   * This state is transitional during the initialization period of uMDNS.
   * In this state uMDNS will send out probing packets periodically to
   * ensure that there are no name conflicts on the network.
   *
   */
  kProbing,
  
  /**
   * @brief uMDNS has detected name conflicts.
   *
   * In this state uMDNS is waiting for the resource records to be updated
   * and umdns_restart_probing to be called. It is not probing, not
   * announcing or responding to queries. This state is similar to the
   * shutdown state except that the network connection is still silently
   * active.
   *
   */
  kNameConflictDetected,

  /**
   * @brief uMDNS is active, announcing and responding to queries.
   *
   * This is the active state where everything is going well, the uMDNS
   * stack is owning the names of the resource records. It is announcing
   * these names periodically to refresh the TTL and is responding to
   * queries for any of the resource records.
   *
   */
  kAnnouncing,

  /**
   * @brief This is a transition state while uMDNS is sending Goodbye packets.
   *
   * After all resource records have been flushed uMDNS will transition to
   * the kShutdown state.
   *
   */
  kShuttingDown
} umdns_state_t;

/**
 * @brief Retrieves the current uMDNS state.
 *
 * @return One of the umnds_state_t values.
 *
 */
umdns_state_t umdns_get_current_state(void);

/**
 * @brief Reports uMDNS state changes.
 *
 * This function is executed whenever the state of the uMDNS stack has
 * changed. Its primary use is to schedule other work based on the state
 * of the uMDNS stack. Another use is for diagnostic purposes.
 *
 * A typical use case of this is to initiate uC sleep modes or disabling
 * the network interface after uMDNS has sent its Goodbye packets and
 * has transitioned into the shutdown state.
 *
 */
extern void umdnsx_state_changed(umdns_state_t state);

#endif // #ifndef UMDNS_UMDNS_STATE_H
