cmake_minimum_required(VERSION 3.5...4.0)

project(Calculator LANGUAGES CXX)

# Recursively glob all .cpp files except those in the bin directory
file(GLOB_RECURSE ALL_CPP_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.cpp")

# Exclude files in the bin directory
list(FILTER ALL_CPP_FILES EXCLUDE REGEX ".*/bin/.*")

add_executable(app ${ALL_CPP_FILES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

if(MSVC AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # Example: enable warnings and treat warnings as errors for Clang with MSVC
    target_compile_options(app PRIVATE -Wextra -Wall)
endif()     # -Werror