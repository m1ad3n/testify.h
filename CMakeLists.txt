cmake_minimum_required(VERSION 3.8)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Testify)

add_executable(Testify)

add_subdirectory(src)

include_directories(${CMAKE_SOURCE_DIR}/include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Testify PROPERTY CXX_STANDARD 20)
endif()
