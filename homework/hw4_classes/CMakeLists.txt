cmake_minimum_required(VERSION 3.8)
project(hw4_classes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp person_class.h person_class.cpp functions.h functions.cpp)
add_executable(hw4_classes ${SOURCE_FILES} person_class.h person_class.cpp functions.h functions.cpp)