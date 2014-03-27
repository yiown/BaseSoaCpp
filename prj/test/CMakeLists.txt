# CMake flags
cmake_minimum_required(VERSION 2.8.3)

# project settings
project(baseSoaCpp-test)

# flags
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../bin/test")

# include common definitions
include(${CMAKE_CURRENT_SOURCE_DIR}/../common.cmake)

# sources
file(GLOB_RECURSE SRC_LIST  "${SRC_DIR}/*.c*")
list(REMOVE_ITEM SRC_LIST "${SRC_DIR}/main/base/main.cpp")

# make an executable
add_executable(${PROJECT_NAME} ${SRC_LIST})

# libraries
target_link_libraries(${PROJECT_NAME} ${LIB_COMMON}
    gtest gtest_main
)

# testing
enable_testing()
add_test(${PROJECT_NAME} ${PROJECT_NAME})
