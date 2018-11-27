cmake_minimum_required(VERSION 3.9)

project(Rat VERSION 0.1.0 DESCRIPTION "Ratouney's C++ librairy, yes, i'm lazy...")

add_library(Rat SHARED
        src/Error.cpp
        src/File.cpp
        src/Regex.cpp
        include/Regex.hpp
        include/Error.hpp
        include/File.hpp
        include/Segment.hpp
        include/Monitor.hpp

        )

set_target_properties(Rat PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(Rat PUBLIC ./include)

add_executable(tester main.cpp)
target_include_directories(tester PUBLIC include)

find_package(Threads)
target_link_libraries(tester Rat ${CMAKE_THREAD_LIBS_INIT})