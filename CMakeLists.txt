cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        config.cpp
        config.h
        symptom.cpp
        symptom.h)

include_directories(include)
target_link_libraries(untitled winmm)