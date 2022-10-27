cmake_minimum_required(VERSION 3.5)
project(server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(LIB_DIR "${SRC_DIR}/include")
set(PROJECT_DIR "${SRC_DIR}")
set(SOURCES
    # main.cpp is only used to tell cmake it has to be compiled for c++ language.
    "${PROJECT_DIR}/main.cpp"
    "${PROJECT_DIR}/../include/XChunker.h"
    "${PROJECT_DIR}/../include/lodepng/lodepng.h"
    "${PROJECT_DIR}/../include/lodepng/lodepng.cpp"
    )
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_DIR}/../include/")
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_DIR}/../include/lodepng/")

