cmake_minimum_required(VERSION 3.7)
project(hw6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp  plastic_card.cpp credit_card.cpp  debit_card.cpp)
add_executable(hw6 ${SOURCE_FILES} plastic_card.h plastic_card.cpp credit_card.cpp credit_card.h)