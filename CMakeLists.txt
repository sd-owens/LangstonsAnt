cmake_minimum_required(VERSION 3.14)
project(LangstonsAnt)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(LangstonsAnt
        main.cpp Ant.cpp Ant.hpp Board.cpp Board.hpp)
