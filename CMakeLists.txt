cmake_minimum_required(VERSION 3.13)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Options
option(ENABLE_WARNINGS "Enable all warnings on build" OFF)
option(ENABLE_WARNINGS_AS_ERROR "Enable all warnings as errors" OFF)
option(ENABLE_TESTS "Build the tests" OFF)
option(ENABLE_CLANG_TIDY_CHECK "Enable clang tidy check on compilation" OFF)
option(ENABLE_ERROR_ON_MISSING_TOOL "If a tools (clang-tidy, clang-format, doxygen) is not disabled and not installed, throws error" OFF)

option(DISABLE_EXTERNAL_WARNINGS "Disables warnings from exernal libs (gtest, freertos, etc)" ON)

# Project definition
project(propolis CXX C)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
set (CMAKE_CXX_STANDARD 17)


# Warning flags constants
set(WARNING_FLAG -Wall -Wextra -Wsign-conversion -Wuninitialized  -Wunused-variable -Wpedantic )
set(WARNING_NO_EXCEPTION_FLAG -fno-exceptions)
set(WARNING_AS_ERROR_FLAG -Werror)

# Generator expression doesn't work with clang-tidy, we need to make an IF statement manually
if(ENABLE_WARNINGS)
add_compile_options(${WARNING_FLAG})
    if(${CMAKE_CROSSCOMPILING})
        # Only remove exception support for target as ROS uses exceptions
        add_compile_options(${WARNING_NO_EXCEPTION_FLAG})
    endif()
endif()

if(ENABLE_WARNINGS_AS_ERROR)
  add_compile_options(${WARNING_AS_ERROR_FLAG})
endif()

# Includes
include(clang-tools/clang-tidy)
include(clang-tools/clang-format)
include(doc/doxygen)
include(utils)

# Testing
if(ENABLE_TESTS)
    include(googletest/common)
    enable_testing()
    if(NOT TARGET gtest)
        googletest_fetch_populate()
    endif()

    if(DISABLE_EXTERNAL_WARNINGS)
        googletest_disable_warnings()
    endif()
endif()

add_subdirectory(src)

