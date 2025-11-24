cmake_minimum_required(VERSION 3.30)
project(CPP11 CXX)
add_library(CPP11 cpp11.cpp)
target_include_directories(CPP11 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})