
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
    set(JsonCpp_INCLUDE_DIR "/usr/local/include/json")
    set(JsonCpp_LIBRARIES "/usr/local/lib/libjsoncpp.a")
    include_directories(${JsonCpp_INCLUDE_DIR})

    set(CJSON_INCLUDE_DIR "/usr/local/include/cjson")
    set(CJSON_LIBRARY "/usr/local/lib/libcjson.a")
    include_directories(${CJSON_INCLUDE_DIR})

    set(OPENSSL_ROOT_DIR "/usr/openssl")
    set(OPENSSL_INCLUDE_DIR "/usr/openssl/include")
    set(OPENSSL_LIBRARIES "/usr/lib/libssl.so;/usr/lib/libcrypto.so")
    include_directories(${OPENSSL_INCLUDE_DIR})
endif()
