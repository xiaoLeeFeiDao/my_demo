aux_source_directory(. CURRENT_SRC_LIST)
aux_source_directory(cpp_learn CURRENT_SRC_LIST)
aux_source_directory(demo CURRENT_SRC_LIST)
include_directories(.)
include_directories(cpp_learn/include)
include_directories(demo/include)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(${PROJECT_NAME} ${CURRENT_SRC_LIST})