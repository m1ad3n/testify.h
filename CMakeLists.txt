cmake_minimum_required(VERSION 3.25)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Testify)

add_executable(Testify)

add_subdirectory(src)

include_directories(${CMAKE_SOURCE_DIR}/include)
