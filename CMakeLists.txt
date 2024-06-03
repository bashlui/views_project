cmake_minimum_required(VERSION 3.27)
project(views_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/Classes)

add_executable(views_project
        src/Classes/Movies.cpp
        src/Classes/Movies.h
        src/Classes/Series.cpp
        src/Classes/Series.h
        src/Classes/Video.cpp
        src/Classes/Video.h
        src/main.cpp
        holamellamotono.cpp)
