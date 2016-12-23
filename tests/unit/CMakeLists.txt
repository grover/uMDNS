
add_executable(uMDNSUnitTests
  main.c
  umdns_fake_network.c
  
  test_umdns_initialization.c)

add_sanitizers(uMDNSUnitTests)

target_link_libraries(uMDNSUnitTests PRIVATE
  unity
  uMDNS)
