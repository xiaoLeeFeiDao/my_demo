# env_conf.cmake
set(THIRD_PARTY_BUILD_DIR "${CMAKE_BINARY_DIR}/third_party_build")
file(MAKE_DIRECTORY "${THIRD_PARTY_BUILD_DIR}")

# OpenSSL配置（仅查找，不链接）
find_package(OpenSSL REQUIRED)
if(OpenSSL_FOUND)
    message(STATUS "Found OpenSSL: ${OPENSSL_INCLUDE_DIR}")
else()
    message(FATAL_ERROR "OpenSSL not found")
endif()

# jsoncpp配置
# jsoncpp 配置
if(NOT TARGET jsoncpp_lib)
    find_package(jsoncpp 1.9.0 QUIET)
    
    if(TARGET jsoncpp_lib)
        message(STATUS "Found system jsoncpp: ${jsoncpp_LIBRARIES}")
        # Arch Linux 使用小写目标名
        target_include_directories(jsoncpp_lib INTERFACE /usr/include/jsoncpp)
    else()
        message(STATUS "Building jsoncpp from source")
        set(JSONCPP_WITH_TESTS OFF)
        set(JSONCPP_WITH_CMAKE_PACKAGE OFF)
        add_subdirectory(third_party/jsoncpp EXCLUDE_FROM_ALL)
        
        if(TARGET jsoncpp_lib)
            set_target_properties(jsoncpp_lib PROPERTIES
                ARCHIVE_OUTPUT_DIRECTORY "${THIRD_PARTY_BUILD_DIR}/lib"
                LIBRARY_OUTPUT_DIRECTORY "${THIRD_PARTY_BUILD_DIR}/lib"
            )
            target_include_directories(jsoncpp_lib PUBLIC 
                ${CMAKE_CURRENT_SOURCE_DIR}/third_party/jsoncpp/include
            )
        else()
            message(FATAL_ERROR "jsoncpp target not found")
        endif()
    endif()
endif()

# cJSON配置
if(NOT TARGET cjson)
    find_package(cJSON QUIET)

    if(cJSON_FOUND AND TARGET cJSON::cJSON)
        message(STATUS "Found system cJSON")
        add_library(cjson ALIAS cJSON::cJSON)
    else()
        message(STATUS "Building cJSON from source")
        add_library(cjson_local SHARED third_party/cJSON/cJSON.c)
        target_include_directories(cjson_local PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/third_party/cJSON)
        set_target_properties(cjson_local PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${THIRD_PARTY_BUILD_DIR}/lib"
            LIBRARY_OUTPUT_DIRECTORY "${THIRD_PARTY_BUILD_DIR}/lib"
            OUTPUT_NAME "cjson"
        )
        add_library(cjson ALIAS cjson_local)
    endif()
endif()

# cmark 配置
if(NOT TARGET cmark)
    find_package(cmark QUIET)
    
    if(cmark_FOUND AND TARGET cmark::cmark)
        message(STATUS "Found system cmark")
        add_library(cmark ALIAS cmark::cmark)
    else()
        message(STATUS "Building cmark from source")
        add_subdirectory(third_party/cmark EXCLUDE_FROM_ALL)
        
        if(TARGET cmark)
            set_target_properties(cmark PROPERTIES
                ARCHIVE_OUTPUT_DIRECTORY "${THIRD_PARTY_BUILD_DIR}/lib"
                LIBRARY_OUTPUT_DIRECTORY "${THIRD_PARTY_BUILD_DIR}/lib"
            )
            # 修正包含目录
            target_include_directories(cmark PUBLIC 
                $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/third_party/cmark/include>
                $<INSTALL_INTERFACE:include>
            )
        else()
            message(FATAL_ERROR "cmark target not found")
        endif()
    endif()
endif()

# 导出变量供主CMake使用
set(OPENSSL_LIBRARIES OpenSSL::SSL OpenSSL::Crypto)
