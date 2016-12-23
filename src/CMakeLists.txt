
add_library(uMDNS STATIC 
  # Source code
  mdns_prober.c
  umdns.c
  umdns_state.c

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
set_property(TARGET uMDNS PROPERTY C_STANDARD_REQUIRED ON)

target_include_directories(uMDNS PUBLIC
  ../include)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  target_compile_options(uMDNS PRIVATE -Werror -Weverything -pedantic -Wall -Wextra -Wno-padded)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(uMDNS PRIVATE -Werror -pedantic -Wall -Wextra -Wno-padded)
endif()
