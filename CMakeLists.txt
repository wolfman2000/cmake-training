cmake_minimum_required(VERSION 2.8)
project(Tutorial)
add_executable(Tutorial tutorial.cpp)

if (APPLE)
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
    set(CMAKE_XCODE_ATTRIBUTE_GCC_C_LANGUAGE_STANDARD "c11")
endif(APPLE)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(UNIX)
