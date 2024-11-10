set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 添加源文件
aux_source_directory(. CURRENT_SRC_LIST)
aux_source_directory(cpp_learn CURRENT_SRC_LIST)
aux_source_directory(demo CURRENT_SRC_LIST)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${CURRENT_SRC_LIST})

# 设置 include 目录
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/cpp_learn"
    "${CMAKE_SOURCE_DIR}/cpp_learn/include"
    "${CMAKE_SOURCE_DIR}/demo"
    "${CMAKE_SOURCE_DIR}/demo/include"
)

# 链接外部库
target_link_libraries(${PROJECT_NAME} ${JsonCpp_LIBRARIES} ${CJSON_LIBRARY} ${OPENSSL_LIBRARIES})

message(STATUS ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../lib")

# # 添加源文件
# aux_source_directory(. CURRENT_SRC_LIST)
# aux_source_directory(cpp_learn CURRENT_SRC_LIST)
# aux_source_directory(demo CURRENT_SRC_LIST)

# # 创建可执行文件
# add_executable(${PROJECT_NAME} ${CURRENT_SRC_LIST})

# # 设置 include 目录
# target_include_directories(${PROJECT_NAME} PRIVATE
#     # "${CMAKE_CURRENT_SOURCE_DIR}/cpp_learn"
#     # "${CMAKE_CURRENT_SOURCE_DIR}/cpp_learn/include"
#     # "${CMAKE_CURRENT_SOURCE_DIR}/demo"
#     # "${CMAKE_CURRENT_SOURCE_DIR}/demo/include"
#     "cpp_learn"
#     "cpp_learn/include"
#     "demo"
#     "demo/include"
# )

# 链接外部库
# target_link_libraries(${PROJECT_NAME} ${JsonCpp_LIBRARIES} ${CJSON_LIBRARY} ${OPENSSL_LIBRARIES})
