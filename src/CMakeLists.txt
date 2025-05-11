# 排除路径模式
set(EXCLUDE_REGEX
    ".*/third_party/.*"
    ".*/js/.*"
    ".*/iar_build/.*"
    # ".*[Tt]est.*"
    ".*_test.cpp$"
    ".*_tests.cpp$"
    ".*/CMakeFiles/.*"
)

# 收集源文件
file(GLOB_RECURSE SRC_FILES
    LIST_DIRECTORIES false
    "*.cpp"
    "*.c"
    "*.h"
    "*.hpp"
)

message(${SRC_FILES})
# 过滤文件
foreach(pattern ${EXCLUDE_REGEX})
    list(FILTER SRC_FILES EXCLUDE REGEX "${pattern}")
endforeach()

# 创建可执行文件
add_executable(${PROJECT_NAME} 
    ${SRC_FILES}
    main.cpp
)

# 包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp_learn
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp_learn/include
    ${CMAKE_CURRENT_SOURCE_DIR}/demo
    ${CMAKE_CURRENT_SOURCE_DIR}/demo/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/jsoncpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/third_party/cmark/src
)

message("THIRD_PARTY_DIR: ${THIRD_PARTY_BUILD_DIR}")
# 在这里链接所有库
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${OPENSSL_LIBRARIES}
    jsoncpp_lib
    cjson
    cmark
)

# 安装规则
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
