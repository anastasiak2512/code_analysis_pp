cmake_minimum_required(VERSION 3.20)
project(code_analysis_pp)

set(CMAKE_CXX_STANDARD 20)

add_executable(lifetimes lifetime_safety_samples.cpp)
add_executable(code_analysis_pp main.cpp)
