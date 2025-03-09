# ---------------------------
# File: src_conf.cmake
# ---------------------------
# 源文件收集（排除指定目录）
file(GLOB_RECURSE SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/*.c"
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.h"
    "${CMAKE_SOURCE_DIR}/src/*.hpp"
)

list(APPEND EXCLUDE_DIRS
    ".*/vscode/.*"
    ".*/iar_build/.*"
    ".*/src/js/.*"
    ".*/cJSON/(tests|fuzzing|test)/.*"
    ".*/jsoncpp/(test|example|src/(test_lib_json|jsontestrunner))/.*"
    ".*/unity/.*"
)

# 过滤排除目录
foreach(excl ${EXCLUDE_DIRS})
    list(FILTER SRC_FILES EXCLUDE REGEX "${excl}")
endforeach()

# 头文件包含路径
set(SRC_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/cpp_learn
    ${CMAKE_SOURCE_DIR}/src/demo
)

# 特殊目录处理
list(APPEND SRC_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/src/cpp_learn/include
    ${CMAKE_SOURCE_DIR}/src/demo/include
)
