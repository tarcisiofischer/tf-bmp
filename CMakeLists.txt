cmake_minimum_required(VERSION 3.27)
project(tf_bmp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

macro(add_example)
    set(options NONE)
    set(oneValueArgs NAME)
    set(multiValueArgs SOURCES)
    cmake_parse_arguments(IN "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    add_executable(${IN_NAME} ${IN_SOURCES} tf_bmp)
    target_compile_options(${IN_NAME} PRIVATE -Werror -Wall -Wextra -Wconversion -Wno-unused-parameter)
endmacro()

add_example(NAME static_checks SOURCES examples/static_checks.cc)
add_example(NAME example1 SOURCES examples/example1.cc)
add_example(NAME example2 SOURCES examples/example2_circular_view.cc)
