cmake_minimum_required(VERSION 3.0)
project(robotics_probabilistics_course)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Ofast -fext-numeric-literals")


find_package(PkgConfig)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
pkg_check_modules(Eigen3 REQUIRED eigen3)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/binaries)

add_subdirectory(source)
