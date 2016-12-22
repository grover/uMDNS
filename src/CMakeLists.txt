
add_library(uMDNS STATIC 
  umdns.c)
add_sanitizers(uMDNS)

target_include_directories(uMDNS PUBLIC
  ../include)
