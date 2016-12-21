
add_library(uMDNS STATIC 
  umdns.c)

target_include_directories(uMDNS PUBLIC
  ../include)
