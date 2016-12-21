
cmake_minimum_required(VERSION 3.2)

project(uMDNS)

option(ENABLE_TESTS "Build unit tests and run them as part of the build." OFF)

add_subdirectory(src)
add_subdirectory(tests)
