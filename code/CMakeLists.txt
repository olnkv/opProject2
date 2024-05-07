cmake_minimum_required(VERSION 3.25)
project(opProject)

set(GTEST_LIBRARY "C:/msys64/mingw64/lib/libgtest.a")
set(GTEST_MAIN_LIBRARY "C:/msys64/mingw64/lib/libgtest_main.a")
set(GTEST_INCLUDE_DIR "C:/msys64/mingw64/include/gtest")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

file(GLOB MAIN "main.cpp")
file(GLOB FUNC "func.cpp")
file(GLOB TEST "test.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
add_executable(${PROJECT_NAME} ${MAIN} ${FUNC})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Tests)
add_executable(testout ${TEST} ${FUNC})
target_link_libraries(testout ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})