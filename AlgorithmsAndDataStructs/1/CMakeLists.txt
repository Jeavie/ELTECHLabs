cmake_minimum_required(VERSION 3.5.1)
project(Lab1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp mass.h spisok.h mass.cpp spisok.cpp help_f.cpp help_f.h bit.cpp bit.h bit_mass.cpp bit_mass.h test_gen.cpp test_gen.h)
add_executable(Lab1 ${SOURCE_FILES} help_f.cpp help_f.h bit.cpp bit.h)