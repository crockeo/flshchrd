cmake_minimum_required(VERSION 2.8)
project(flshchrd)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build/lib")

set(CMAKE_CXX_FLAGS "-std=c++11 -O2 -Wall ${CMAKE_CXX_FLAGS}")

set(SOURCES
  src/prompt.cpp
  src/deck.cpp
  src/main.cpp
)

add_executable(flshchrd ${SOURCES})
