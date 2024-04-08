# Minimum version of CMake required
cmake_minimum_required(VERSION 3.0)

# Project name and version
project(protobuf_messages VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Protobuf package
find_package(Protobuf REQUIRED)

# Set the path to the .proto file
set(PROTO_FILES SampleMessage.proto)

# Generate C++ code from the .proto file
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

# Add executable target
add_library(protobuf_messages 
    ${PROTO_SRCS} 
    ${PROTO_HDRS}
)

target_link_libraries(protobuf_messages PRIVATE protobuf::libprotobuf)

# Define an option for building tests
option(BUILD_WITH_TESTS "Build with tests" OFF)

if(BUILD_WITH_TESTS)
    add_subdirectory(tests)
endif()
