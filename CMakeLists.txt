cmake_minimum_required(VERSION 3.15)
project(CppProject LANGUAGES C CXX)

# 强制新策略行为
cmake_policy(SET CMP0000 NEW)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0076 NEW)

# 基础配置
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 第三方库配置
include(env_conf.cmake)
add_subdirectory(third_party)

# 主项目构建
add_subdirectory(src)

# 安装路径配置
include(GNUInstallDirs)
set(INSTALL_LIB_DIR "${CMAKE_INSTALL_LIBDIR}" CACHE PATH "Installation directory for libraries")
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Install lib dir: ${CMAKE_CURRENT_SOURCE_DIR}")
