# Minimum version of CMake required
cmake_minimum_required(VERSION 3.0)

# Project name and version
project(protobuf_messages VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(protos)

# Define an option for building tests
option(BUILD_WITH_TESTS "Build with tests" OFF)

if(BUILD_WITH_TESTS)
    add_subdirectory(tests)
endif()

include(GNUInstallDirs)

install(TARGETS protobuf_messages EXPORT protobuf_messages
    RUNTIME 
        DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY 
        DESTINATION ${CMAKE_INSTALL_LIBDIR}  # shared library
    ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}  # static library
    PUBLIC_HEADER 
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT protobuf_messages
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/protobuf_messages
    FILE protobuf_messages-config.cmake
)