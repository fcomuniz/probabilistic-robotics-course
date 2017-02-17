cmake_minimum_required(VERSION 3.0)
project(robotics_probabilistics_course)


find_package(PkgConfig)
find_package(Eigen3 REQUIRED)
pkg_check_modules(Eigen3 REQUIRED eigen3)



add_subdirectory(source)