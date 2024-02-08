cmake_minimum_required(VERSION 3.0.0)
project(test)
message(STATUS "my system:${CMAKE_HOST_SYSTEM_NAME}")

aux_source_directory(. CURRENT_SRC_LIST)
aux_source_directory(cpp_learn CURRENT_SRC_LIST)
aux_source_directory(demo CURRENT_SRC_LIST)
include_directories(.)
include_directories(cpp_learn/include)
include_directories(demo/include)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

find_path(
  CJSON_INCLUDE_DIR cJSON.h
  # 你的头文件可能在这个路径下
  PATHS /usr/local/include /usr/include/cjson
  # 你的头文件可能在这个子目录下
  PATH_SUFFIXES cJSON)
message(STATUS "cJSON include dir:${CJSON_INCLUDE_DIR}")
# 如果找到头文件，则添加include目录
if(CJSON_INCLUDE_DIR)
  include_directories(${CJSON_INCLUDE_DIR})
endif()
find_package(cjson REQUIRED)
message(STATUS "cJSON libraries: ${CJSON_LIBRARIES}")

find_package(OpenSSL REQUIRED)

find_path(
  JSONCPP_INCLUDE_DIR json.h
  PATHS /opt/homebrew/Cellar/jsoncpp/1.9.5/include /usr/include/jsoncpp
  PATH_SUFFIXES json)

message(STATUS "jsoncpp include dir:${JSONCPP_INCLUDE_DIR}")
if(JSONCPP_INCLUDE_DIR)
  include_directories(JSONCPP_INCLUDE_DIR)
endif()
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/Cellar")


message(STATUS "cur src dir:${CMAKE_CURRENT_SOURCE_DIR}")


# target_include_directories(${PROJECT_NAME} PRIVATE ${jsoncpp_INCLUDE_DIRS})
if(NOT CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin")
  find_package(jsoncpp REQUIRED)
else()
  # 从 CURRENT_SRC_LIST 中移除 demo_test07.cpp 文件
  list(REMOVE_ITEM CURRENT_SRC_LIST "demo/demo_test07.cpp")
endif()
message(STATUS "cur src list:${CURRENT_SRC_LIST}")

add_executable(${PROJECT_NAME} ${CURRENT_SRC_LIST})
if(NOT CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin")
  target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::Crypto cjson jsoncpp)
else()
  target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::Crypto cjson)
endif()

