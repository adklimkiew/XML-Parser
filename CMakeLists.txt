cmake_minimum_required(VERSION 3.2)

project(XML-Parser
    VERSION 1.0.0
    LANGUAGES CXX C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_options(-Wall -Wextra -Wpedantic)

enable_testing()
add_subdirectory(src)
add_subdirectory(tests)
