
add_executable(uMDNSUnitTests
  main.c)

add_sanitizers(uMDNSUnitTests)

target_link_libraries(uMDNSUnitTests PRIVATE
  unity)
