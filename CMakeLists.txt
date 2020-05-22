cmake_minimum_required(VERSION 3.13)

project(VectorFun)

set(CMAKE_CXX_STANDARD 14)

# Change this path to wherever you have catch.hpp.
include_directories(/Users/jjpal/CLionProjects)

add_executable(VectorFun VectorFunTest.cpp catch-main.cpp)