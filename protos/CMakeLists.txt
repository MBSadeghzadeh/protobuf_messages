set(CMAKE_DEBUG_POSTFIX d)

# Find Protobuf package
find_package(Protobuf REQUIRED)

# Set the path to the .proto file
set(PROTO_FILES SampleMessage.proto)

# Generate C++ code from the .proto file
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

# Add executable target
add_library(protobuf_messages SHARED
    ${PROTO_SRCS} 
    ${PROTO_HDRS}
)

set_target_properties(protobuf_messages PROPERTIES PUBLIC_HEADER ${PROTO_HDRS})

target_link_libraries(protobuf_messages INTERFACE protobuf::libprotobuf)

target_include_directories(protobuf_messages 
    INTERFACE 
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

unset(CMAKE_DEBUG_POSTFIX)