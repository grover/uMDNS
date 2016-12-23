
add_library(uMDNS STATIC 
  # Source code
  umdns.c

  # Include files
  ../include/umdns/umdns.h
  ../include/umdns/umdns_config.h
  ../include/umdns/detail/umdns_logging.h
  ../include/umdns/detail/umdns_network.h
  ../include/umdns/detail/umdns_records.h
  ../include/umdns/detail/umdns_result.h
  ../include/umdns/detail/umdns_scheduler.h
  ../include/umdns/detail/umdns_state.h)

add_feature_toggle(uMDNS ENABLE_LOGGING "Include logging calls in the the UMDNS code." OFF)
add_feature_toggle(uMDNS DEFAULT_TTL "The default MDNS TTL of resource records." 120)
set_feature_toggle_header(uMDNS ../include/umdns/umdns_config.h)

add_sanitizers(uMDNS)

set_property(TARGET uMDNS PROPERTY C_STANDARD 99)

target_include_directories(uMDNS PUBLIC
  ../include)
