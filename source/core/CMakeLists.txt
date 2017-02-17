file(GLOB_RECURSE SRCS *.cpp)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(source_lib ${SRCS})
