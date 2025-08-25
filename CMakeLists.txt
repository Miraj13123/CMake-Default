# '#' is the starting of a single line comment
cmake_minimum_required(VERSION 3.5...4.0)  # setting a minimum version of cmake to avoid error [ i used 4.0 ]

project(Calculator LANGUAGES CXX)  # project name "Calculator", Language "CXX" means C++

# Recursively glob all .cpp files in the project folder [ where 'CMakeLinsts.txt' lives ]
file(GLOB_RECURSE ALL_CPP_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.cpp")

# Exclude files from the bin directory [ cause we are going to use bin to build the project ]
list(FILTER ALL_CPP_FILES EXCLUDE REGEX ".*/.*bin.*/.*")

add_executable(app ${ALL_CPP_FILES})  # will create a app.exe where ever i build the project

set(CMAKE_CXX_STANDARD 17)             # setting the C++ standard to c++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)          # turns off compiler specific flags [ so that supports any compiler you are using ]

if(MINGW)  # seting flags for GNU/ MinGW setup
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
endif()

#if(MSVC AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")  # seting flags for clang+MSVC setup
#    # Example: enable warnings and treat warnings as errors for Clang with MSVC
#    target_compile_options(app PRIVATE -Wextra -Wall)
#endif()     # -Werror
