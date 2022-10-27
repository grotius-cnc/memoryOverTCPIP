cmake_minimum_required(VERSION 3.5)
project(client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../test.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../picture.jpeg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(LIB_DIR "${SRC_DIR}")
set(PROJECT_DIR "${SRC_DIR}")
set(SOURCES
    # main.cpp is only used to tell cmake it has to be compiled for c++ language.
    "${PROJECT_DIR}/main.cpp"
    "${PROJECT_DIR}/../include/XChunker.h"
    "${PROJECT_DIR}/../include/lodepng/lodepng.h"
    "${PROJECT_DIR}/../include/lodepng/lodepng.cpp"
    )
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_DIR}/../include/lodepng/")
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_DIR}/../include/")


