cmake_minimum_required(VERSION 3.9)
project(libfml)

add_library(fml SHARED
  src/curve.cpp
  src/quat.cpp
  src/surface.cpp
  src/vec2.cpp
  src/vec3.cpp)

set_target_properties(fml PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION 1)

install(DIRECTORY "include/"
  DESTINATION "include"
  FILES_MATCHING
  PATTERN "*.h")

target_include_directories(fml PRIVATE include)

include(GNUInstallDirs)
install(TARGETS fml
  LIBRARY DESTINATION /usr/lib
  PUBLIC_HEADER DESTINATION /usr/include)
