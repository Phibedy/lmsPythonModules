project(PythonCXXTest)
cmake_minimum_required(VERSION 2.8.12)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Wpedantic")

add_executable(test src/test.cpp)
add_executable(boostTest src/simple.cpp)
target_link_libraries(test ${PYTHON_LIBRARY} ${CONAN_LIBS})
target_link_libraries(boostTest ${CONAN_LIBS})
message("conan_libs: ${CONAN_LIBS}")
