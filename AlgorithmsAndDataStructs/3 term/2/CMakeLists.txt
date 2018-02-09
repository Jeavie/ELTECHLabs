cmake_minimum_required(VERSION 3.7.2)
project(2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Array.cpp Array.h Bits.cpp Bits.h Helper.cpp Helper.h List.cpp List.h Machine.cpp Machine.h )
add_executable(2 ${SOURCE_FILES})