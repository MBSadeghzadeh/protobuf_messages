project(Tests VERSION 1.0)

add_executable(${PROJECT_NAME} test1.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC protobuf_messages)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_BINARY_DIR})