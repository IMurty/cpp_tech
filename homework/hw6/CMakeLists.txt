cmake_minimum_required(VERSION 3.7)
project(hw6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cards.h cards.cpp)
add_executable(hw6 ${SOURCE_FILES} cards.h cards.cpp)