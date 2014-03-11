cmake_minimum_required(VERSION 2.8)
project(Tutorial)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings to the source code.
configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

if (APPLE)
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
    set(CMAKE_XCODE_ATTRIBUTE_GCC_C_LANGUAGE_STANDARD "c11")
endif(APPLE)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif(UNIX)

# Should we use our own math functions?
option(USE_MYMATH "Use tutorial provided math implementation" ON)

if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)

add_executable(Tutorial tutorial.cpp)
target_link_libraries(Tutorial ${EXTRA_LIBS})

# Add install targets.
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# Basic tests go here. Consider a cppunit project for the future.

# Does the application run?
add_test(TutorialRuns Tutorial 25)

# A macro for tests can be utilized.
macro(do_test arg result)
    add_test(TutorialComp${arg} Tutorial ${arg})
    set_tests_properties(TutorialComp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

# Does it calculate the square root of 25?
do_test(25 "25 is 5")

# Does it handle negative numbers?
do_test(-25 "-25 is nan")

# Does it handle small numbers?
do_test(0.0001 "0.0001 is 0.01")

# Does the usage message work?
add_test(TutorialUsage Tutorial)
set_tests_properties(TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")
