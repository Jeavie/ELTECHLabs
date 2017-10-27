cmake_minimum_required(VERSION 3.7)
project(Alg_lab3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Tree.cpp Tree.h Node.cpp Node.h STACK.cpp STACK.h QUEUE.cpp QUEUE.h)
add_executable(Alg_lab3 ${SOURCE_FILES})