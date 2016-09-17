project(PythonCXXTest)
cmake_minimum_required(VERSION 2.8.12)

include(conanbuildinfo.cmake)
conan_basic_setup()

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(test src/test.cpp)
add_executable(simple src/simple.cpp)
target_link_libraries(test ${PYTHON_LIBRARY})
target_link_libraries(simple ${CONAN_LIBS} ${PYTHON_LIBRARY})
message("conan_libs,${CONAN_LIBS}")
