cmake_minimum_required(VERSION 3.8)
project(4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
if (CURSES_FOUND AND CURSES_HAVE_NCURSES_H)
    include_directories(${CURSES_INCLUDE_DIR})
    target_link_libraries (target ${CURSES_LIBRARIES})
endif()
add_executable(4 ${SOURCE_FILES})