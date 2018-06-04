cmake_minimum_required(VERSION 3.9)
project(knowledge)

set(CMAKE_CXX_STANDARD 11)



add_executable(knowledge main.cpp)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
if (CURSES_FOUND AND CURSES_HAVE_NCURSES_H)
    include_directories(${CURSES_INCLUDE_DIR})
    target_link_libraries (knowledge ${CURSES_LIBRARIES})
endif()