cmake_minimum_required(VERSION 3.25)
project(opProject)

add_subdirectory(googletest)

find_package(GTest REQUIRED)

file(GLOB MAIN "main.cpp")
file(GLOB FUNC "func.cpp")
file(GLOB TEST "test.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
add_executable(${PROJECT_NAME} ${MAIN} ${FUNC})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Tests)
add_executable(testout ${FUNC} ${TEST})
target_link_libraries(testout gtest_main)