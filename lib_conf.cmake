
if (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "CYGWIN")
    set(CMAKE_EXE_LINKER_FLAGS "-static") ## 减少对动态库的依赖
    set(JsonCpp_INCLUDE_DIR "/usr/local/include/json;C:\\cygwin64\\usr\\local\\include\\json")
    set(JsonCpp_LIBRARIES "/usr/local/lib/libjsoncpp.a;C:\\cygwin64\\usr\\local\\lib\\libjsoncpp.a")
    include_directories(${JsonCpp_INCLUDE_DIR})

    set(CJSON_INCLUDE_DIR "/usr/local/include/cjson;C:\\cygwin64\\usr\\local\\include\\cjson")
    set(CJSON_LIBRARY "/usr/local/lib/libcjson.so;C:\\cygwin64\\usr\\local\\lib\\libcjson.so")
    include_directories(${CJSON_INCLUDE_DIR})

    set(OPENSSL_ROOT_DIR "/usr/local/openssl;C:/cygwin64/usr/local/openssl/")
    set(OPENSSL_INCLUDE_DIR "/usr/local/openssl/include;C:/cygwin64/usr/local/openssl/include")
    set(OPENSSL_LIBRARIES "C:/cygwin64/usr/local/openssl/lib/libssl.a;C:/cygwin64/usr/local/openssl/lib/libcrypto.a;")
    include_directories(${OPENSSL_INCLUDE_DIR})
elseif (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Linux")
    # set(JsonCpp_INCLUDE_DIR "/usr/lib/json")
    # set(JsonCpp_LIBRARIES "/usr/lib/libjsoncpp.a")
    # include_directories(${JsonCpp_INCLUDE_DIR})

    # set(CJSON_INCLUDE_DIR "/usr/include/cjson")
    # set(CJSON_LIBRARY "/usr/lib/libcjson.a")
    # include_directories(${CJSON_INCLUDE_DIR})

    # set(OPENSSL_ROOT_DIR "/usr/openssl")
    # set(OPENSSL_INCLUDE_DIR "/usr/openssl/include")
    # # set(OPENSSL_LIBRARIES "/usr/lib/x86_64-linux-gnu/libssl.so;/usr/lib/libcrypto.so")
    # find_library(OPENSSL_LIBRARIES NAMES ssl PATHS /usr/lib/x86_64-linux-gnu /usr/local/lib)
    # include_directories(${OPENSSL_INCLUDE_DIR})

    # 指定库文件存放路径
    set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/third_party)

    # 查找已编译的库
    find_library(CJSON_LIB cjson PATHS ${THIRD_PARTY_DIR}/cJSON/build NO_DEFAULT_PATH)
    find_library(JSONCPP_LIB jsoncpp PATHS ${THIRD_PARTY_DIR}/jsoncpp/build NO_DEFAULT_PATH)
    # find_library(CRYPTO_LIB crypto PATHS ${THIRD_PARTY_DIR}/openssl/build NO_DEFAULT_PATH)

    # 查找头文件
    find_path(CJSON_INCLUDE_DIR cJSON.h PATHS ${THIRD_PARTY_DIR}/cJSON NO_DEFAULT_PATH)
    find_path(JSONCPP_INCLUDE_DIR json/json.h PATHS ${THIRD_PARTY_DIR}/jsoncpp NO_DEFAULT_PATH)
    # find_path(OPENSSL_INCLUDE_DIR openssl/crypto.h PATHS ${THIRD_PARTY_DIR}/openssl/include NO_DEFAULT_PATH)

    # 如果库文件不存在，则添加子目录进行编译
    if (NOT CJSON_LIB OR NOT CJSON_INCLUDE_DIR)
        message(STATUS "cJSON not found, adding subdirectory...")
        add_subdirectory(${THIRD_PARTY_DIR}/cJSON)
        set(CJSON_LIB cjson)
    endif()

    if (NOT JSONCPP_LIB OR NOT JSONCPP_INCLUDE_DIR)
        message(STATUS "jsoncpp not found, adding subdirectory...")
        add_subdirectory(${THIRD_PARTY_DIR}/jsoncpp)
        set(JSONCPP_LIB jsoncpp_lib)
    endif()
# include(ExternalProject)

# 设置 OpenSSL 安装路径
# set(OPENSSL_INSTALL_DIR ${CMAKE_BINARY_DIR}/openssl)

# 添加 OpenSSL 外部项目
# ExternalProject_Add(
#     openssl_project
#     PREFIX ${OPENSSL_INSTALL_DIR}
#     GIT_REPOSITORY https://github.com/openssl/openssl.git
#     GIT_TAG OpenSSL_1_1_1-stable
#     CONFIGURE_COMMAND ./config --prefix=${OPENSSL_INSTALL_DIR} --openssldir=${OPENSSL_INSTALL_DIR}/ssl
#     BUILD_COMMAND make -j$(nproc)
#     INSTALL_COMMAND make install
#     BUILD_IN_SOURCE 1
# )

# 查找 OpenSSL 头文件和库
# set(OPENSSL_INCLUDE_DIR ${OPENSSL_INSTALL_DIR}/include)
# set(OPENSSL_LIB_DIR ${OPENSSL_INSTALL_DIR}/lib)
# set(OPENSSL_CRYPTO_LIB ${OPENSSL_LIB_DIR}/libcrypto.a)
# set(OPENSSL_SSL_LIB ${OPENSSL_LIB_DIR}/libssl.a)

# 指定目标需要依赖 OpenSSL 编译完成
# include_directories(${OPENSSL_INCLUDE_DIR})

    # 包含头文件
    include_directories(
        ${CJSON_INCLUDE_DIR}
        ${JSONCPP_INCLUDE_DIR}
        # ${OPENSSL_INCLUDE_DIR}
    )

    # 链接库
    target_link_libraries(${PRODUCT_NAME} ${CJSON_LIB} ${JSONCPP_LIB} ${OPENSSL_CRYPTO_LIB} ${OPENSSL_SSL_LIB})
    add_dependencies(${PRODUCT_NAME} openssl_project)
endif()
