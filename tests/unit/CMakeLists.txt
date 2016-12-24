
add_executable(uMDNSUnitTests
  main.c
  umdns_fake_network.c
  umdns_fake_scheduler.c
  
  test_umdns_initialization.c
  test_umdns_probing.c)

set_property(TARGET uMDNSUnitTests PROPERTY C_STANDARD 99)
set_property(TARGET uMDNSUnitTests PROPERTY C_STANDARD_REQUIRED ON)

add_sanitizers(uMDNSUnitTests)

target_link_libraries(uMDNSUnitTests PRIVATE
  unity
  uMDNS)
target_include_directories(uMDNSUnitTests PRIVATE
  ../../src)
