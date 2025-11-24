cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

project(
  CppSelfStudy
  LANGUAGES CXX # C++ needs to be enabled.
)

# This project isn't using C++ modules; avoid bugs in module scanning CMake 3.28, 3.29 with GCC >= 14.
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set compiler to clang++
# set(CMAKE_CXX_COMPILER clang++)
# Use libc++ as the standard library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Temporarily Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

## Feature Exploration Directories
# Option compilations for subdirectories
option(BUILD_CPP11 "Build example applications" ON)


add_executable(${PROJECT_NAME} main.cpp)


if (BUILD_CPP11)
  set(CPP11_DIR "./cpp11")
  add_subdirectory(${CPP11_DIR})
  target_link_directories(${PROJECT_NAME} PUBLIC ${CPP11_DIR})
  target_link_libraries(${PROJECT_NAME} CPP11)
  message(STATUS "CPP11 compilation enabled")
endif()
##


add_compile_options(-Wall -Wextra)