set(SOURCES
    "src/python_module_container.cpp"
    "src/interface.cpp"
)

set(HEADERS
    "include/python_module_container.h"
)

include_directories(include)
add_library(python_module_container MODULE ${SOURCES} ${HEADERS})
target_link_libraries(python_module_container PRIVATE lmscore ${PYTHON_LIBRARY} ${CONAN_LIBS})
