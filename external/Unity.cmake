# CMake file to build unity in a CMake build environment.

add_library(unity STATIC
  external/Unity/src/unity.c
  external/Unity/src/unity.h
  external/Unity/src/unity_internals.h
  
  external/Unity/extras/fixture/src/unity_fixture.c
  external/Unity/extras/fixture/src/unity_fixture.h
  external/Unity/extras/fixture/src/unity_fixture_internals.h
  external/Unity/extras/fixture/src/unity_fixture_malloc_overrides.h)

target_include_directories(unity PUBLIC
  external/Unity/src
  external/Unity/extras/fixture/src)
