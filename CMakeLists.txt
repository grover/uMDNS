
cmake_minimum_required(VERSION 3.2)

project(uMDNS)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/sanitizers-cmake/cmake" ${CMAKE_MODULE_PATH})

option(UMDNS_BUILD_EXAMPLES "Build the example programs." ON)
option(UMDNS_ENABLE_TESTS "Build unit tests and run them as part of the build." ON)

#
# Adapter library options, used to enable/disable adapter libs.
#
option(UMDNS_USE_SOCKETS "Build UMDNS integrated BSD socket support." OFF)
option(UMDNS_USE_LWIP "Build UMDNS integrated LwIP support." OFF)

# Option determines if we should build the unity test framework as part of uMDNS
option(UMDNS_HAVE_UNITY "Enable this if you embed uMDNS in another project that already provides unity targets." OFF)

find_package(Sanitizers)

add_subdirectory(src)

if(UMDNS_ENABLE_EXAMPLES)
add_subdirectory(examples)
endif()

if(NOT UMDNS_HAVE_UNITY)
include(external/Unity.cmake)
endif()

if(UMDNS_ENABLE_TESTS)
add_subdirectory(tests)
endif()
