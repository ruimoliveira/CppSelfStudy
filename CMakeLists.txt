cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

project(
  CppSelfStudy
  LANGUAGES CXX # C++ needs to be enabled.
)

# This project isn't using C++ modules; avoid bugs in module scanning CMake 3.28, 3.29 with GCC >= 14.
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set compiler to clang++ and Use libc++ as the standard library
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall -Wextra)

add_executable(${PROJECT_NAME} main.cpp)