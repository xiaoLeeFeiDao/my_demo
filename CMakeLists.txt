cmake_minimum_required(VERSION 3.0.0)
project(test.out VERSION 0.1.0)
aux_source_directory(. CURRENT_SRC_LIST)
aux_source_directory(cpp_learn CURRENT_SRC_LIST)
aux_source_directory(demo CURRENT_SRC_LIST)
include_directories(cpp_learn)
include_directories(demo)
message(STATUS ${CURRENT_SRC_LIST})
add_executable(${PROJECT_NAME} ${CURRENT_SRC_LIST})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/Debug/Exe)
# target_link_libraries(${PROJECT_NAME} cpp_learn demo)