set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories("${CMAKE_SOURCE_DIR}/cpp_learn/include")
include_directories("${CMAKE_SOURCE_DIR}/demo/include")

# 添加相对路径的源文件目录
aux_source_directory(. CURRENT_SRC_LIST)
aux_source_directory(cpp_learn CURRENT_SRC_LIST)
aux_source_directory(demo CURRENT_SRC_LIST)

# 输出源文件列表用于调试
message(STATUS "Source files: ${CURRENT_SRC_LIST}")

# 设置输出目录和编译类型
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/$ENV{default_env_name}_bin)
set(CMAKE_BUILD_TYPE Debug)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${CURRENT_SRC_LIST})
