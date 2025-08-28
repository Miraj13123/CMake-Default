# '#' is the starting of a single line comment
cmake_minimum_required(VERSION 3.5...4.0) # setting a minimum version of cmake to avoid error [ i used 4.0 ]
project(My_Calculator_project LANGUAGES CXX) # project name "Calculator", Language "CXX" means C++

# Collect all .cpp files recursively from the project folder [ where 'CMakeLinsts.txt' lives ]
file(GLOB_RECURSE ALL_CPP_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.cpp")

# list(FILTER ALL_CPP_FILES EXCLUDE REGEX ".*/bin/.*")
list(FILTER ALL_CPP_FILES EXCLUDE REGEX "^${CMAKE_SOURCE_DIR}/[^/]*bin[^/]*")


# Set C++ standard
set(CMAKE_CXX_STANDARD 17) # setting the C++ standard to c++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # turns off compiler specific flags [ so that supports any compiler you are using ]

# Add executable
add_executable(app ${ALL_CPP_FILES}) # will create a app.exe where ever i build the project

# Manual include directories (-I)
set(MANUAL_INCLUDE_DIRS # include header paths [ -I ]
    "${CMAKE_SOURCE_DIR}/src"

    # Add more include paths here, e.g.:
    # "${CMAKE_SOURCE_DIR}/include"
    # "${CMAKE_SOURCE_DIR}/lib/some-lib/include"
)

foreach(DIR ${MANUAL_INCLUDE_DIRS})
    if(EXISTS "${DIR}")
        target_include_directories(app PRIVATE "${DIR}")
    endif()
endforeach()

# Library directories (-L) and libraries (-l)
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(MANUAL_LIBRARY_DIRS linking # external library paths [ -L ]

    # Add library directories here, e.g.:
    # "${LIB_DIR}/some-lib/lib"
)
set(MANUAL_LIBRARIES # linking external libraries [ -l ]

    # Add library names here (without 'lib' prefix), e.g.:
    # some-lib
)

add_library(ExternalLibrary INTERFACE)

foreach(DIR ${MANUAL_LIBRARY_DIRS})
    if(EXISTS "${DIR}")
        target_link_directories(ExternalLibrary INTERFACE "${DIR}")
    endif()
endforeach()

if(MANUAL_LIBRARIES)
    target_link_libraries(ExternalLibrary INTERFACE ${MANUAL_LIBRARIES})
endif()

# add the external library to the target
target_link_libraries(app PRIVATE ExternalLibrary) # include -I, -L, -l to the target 'app'

# Non-compiler-specific flags
target_compile_options(app PRIVATE
    -O2 # Optimization level 2 (GCC/Clang: -O2, MSVC: /O2)
    -Wall # Enable most warnings (GCC/Clang, translated to /W4 for MSVC)
    -Wextra # Enable extra warnings (GCC/Clang, included in /W4 for MSVC)
)

# Toolchain-specific flags for static linking
if(MINGW)
    target_compile_options(app PRIVATE -static-libgcc -static-libstdc++)
    target_link_options(app PRIVATE -static) # Ensure all libraries are linked statically
endif()

if(MSVC AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(app PRIVATE /MT) # Static MSVC runtime
    target_link_options(app PRIVATE /NODEFAULTLIB:msvcrt) # Avoid dynamic runtime
endif()

# Custom run target
add_custom_target(run
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target app
    COMMAND ${CMAKE_BINARY_DIR}/app${CMAKE_EXECUTABLE_SUFFIX}
    DEPENDS app
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Building and running app"
)