cmake_minimum_required(VERSION 3.17)
project(gootuto)

set(CMAKE_CXX_STANDARD 14)

add_executable(gootuto main.cpp)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
target_link_libraries(gootuto gtest gtest_main)