cmake_minimum_required(VERSION 3.20.0)

project(test)
message(STATUS "my system:${CMAKE_HOST_SYSTEM_NAME}")
set(CMAKE_EXE_LINKER_FLAGS "-static") ## 减少对动态库的依赖

include(src_conf.cmake)
