# ---------------------------
# File: lib_conf.cmake (完整修改版)
# ---------------------------
function(handle_third_party libname)
    set(options OPTIONAL)
    set(oneValueArgs HEADER LIBNAME SEARCH_PATH TARGET_NAME)
    set(multiValueArgs COMPONENTS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # 1. 优先查找系统库
    find_library(${libname}_LIB_SHARED
        NAMES ${ARG_LIBNAME} ${ARG_LIBNAME}.so
        PATHS ${ARG_SEARCH_PATH}
        PATH_SUFFIXES lib
        NO_DEFAULT_PATH
    )
    
    if(NOT ${libname}_LIB_SHARED)
        find_library(${libname}_LIB_STATIC
            NAMES ${ARG_LIBNAME}.a
            PATHS ${ARG_SEARCH_PATH}
            PATH_SUFFIXES lib
            NO_DEFAULT_PATH
        )
    endif()

    # 2. 系统库存在时的处理
    if(${libname}_LIB_SHARED OR ${libname}_LIB_STATIC)
        message(STATUS "Using system library for ${libname}")
        find_path(${libname}_INCLUDE_DIR ${ARG_HEADER}
            PATHS ${ARG_SEARCH_PATH}
            PATH_SUFFIXES include
            NO_DEFAULT_PATH
        )
        set(${libname}_INCLUDE_DIR ${${libname}_INCLUDE_DIR} PARENT_SCOPE)
        set(${libname}_LIB_SHARED ${${libname}_LIB_SHARED} PARENT_SCOPE)
        set(${libname}_LIB_STATIC ${${libname}_LIB_STATIC} PARENT_SCOPE)
    else()
        # 3. 系统库不存在，检查源码是否需要编译
        set(LIB_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/third_party/${libname})
        set(BINARY_DIR "${CMAKE_BINARY_DIR}/third_party_build/${libname}")
        set(LIB_NEEDS_BUILD FALSE)
        
        # 检查是否已有编译产物
        set(LIB_BUILT_SHARED "${BINARY_DIR}/lib${ARG_LIBNAME}.so")
        set(LIB_BUILT_STATIC "${BINARY_DIR}/lib${ARG_LIBNAME}.a")
        
        if(NOT (EXISTS ${LIB_BUILT_SHARED} OR EXISTS ${LIB_BUILT_STATIC}))
            message(STATUS "No prebuilt ${libname} found, will build from source")
            set(LIB_NEEDS_BUILD TRUE)
        else()
            # 检查源码是否有更新
            file(GLOB_RECURSE LIB_SOURCE_FILES 
                "${LIB_SOURCE_DIR}/*.c" 
                "${LIB_SOURCE_DIR}/*.cpp"
                "${LIB_SOURCE_DIR}/*.h"
            )
            
            foreach(source_file ${LIB_SOURCE_FILES})
                if(EXISTS ${LIB_BUILT_SHARED})
                    if(${source_file} IS_NEWER_THAN ${LIB_BUILT_SHARED})
                        message(STATUS "${libname} source modified, rebuilding...")
                        set(LIB_NEEDS_BUILD TRUE)
                        break()
                    endif()
                elseif(EXISTS ${LIB_BUILT_STATIC})
                    if(${source_file} IS_NEWER_THAN ${LIB_BUILT_STATIC})
                        message(STATUS "${libname} source modified, rebuilding...")
                        set(LIB_NEEDS_BUILD TRUE)
                        break()
                    endif()
                endif()
            endforeach()
        endif()

        # 4. 需要编译时的处理
        if(LIB_NEEDS_BUILD)
            message(STATUS "Building ${libname} from source")
            
            if(${libname} STREQUAL "cJSON")
                set(ENABLE_CJSON_TEST OFF CACHE BOOL "Disable cJSON tests" FORCE)
            elseif(${libname} STREQUAL "jsoncpp")
                set(JSONCPP_WITH_TESTS OFF CACHE BOOL "Disable jsoncpp tests" FORCE)
            endif()
            
            add_subdirectory(
                ${LIB_SOURCE_DIR}
                ${BINARY_DIR}
            )
            
            # 目标检测逻辑保持不变...
            set(target_name "")
            if(ARG_TARGET_NAME)
                foreach(name IN ITEMS ${ARG_TARGET_NAME} "${libname}" "${libname}_shared" "${libname}_static")
                    if(TARGET ${name})
                        set(target_name ${name})
                        break()
                    endif()
                endforeach()
            else()
                foreach(name IN ITEMS ${libname} ${libname}_shared ${libname}_static jsoncpp jsoncpp_lib)
                    if(TARGET ${name})
                        set(target_name ${name})
                        break()
                    endif()
                endforeach()
            endif()
            
            if(NOT target_name)
                message(FATAL_ERROR "Failed to determine target name for ${libname}")
            endif()
            
            set(THIRD_PARTY_LIBS ${THIRD_PARTY_LIBS} ${target_name} PARENT_SCOPE)
            set(THIRD_PARTY_INCLUDE_DIRS ${THIRD_PARTY_INCLUDE_DIRS} ${LIB_SOURCE_DIR}/include PARENT_SCOPE)
        else()
            # 5. 不需要重新编译时的处理
            if(EXISTS ${LIB_BUILT_SHARED})
                set(${libname}_LIB_SHARED ${LIB_BUILT_SHARED} PARENT_SCOPE)
                message(STATUS "Using prebuilt shared library for ${libname}")
            elseif(EXISTS ${LIB_BUILT_STATIC})
                set(${libname}_LIB_STATIC ${LIB_BUILT_STATIC} PARENT_SCOPE)
                message(STATUS "Using prebuilt static library for ${libname}")
            endif()
            set(${libname}_INCLUDE_DIR ${LIB_SOURCE_DIR}/include PARENT_SCOPE)
        endif()
    endif()
endfunction()

# 其余部分保持不变...
handle_third_party(cJSON
    HEADER       cjson/cJSON.h
    LIBNAME      cjson
    SEARCH_PATH  /usr/local
    TARGET_NAME  cjson
)

handle_third_party(jsoncpp
    HEADER       json/json.h
    LIBNAME      jsoncpp
    SEARCH_PATH  /usr/local
    TARGET_NAME  jsoncpp
)

find_package(OpenSSL REQUIRED)
