
# addding qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "~/Qt/5.8/gcc_64/")
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})


file(GLOB_RECURSE EXECUTABLES ${CMAKE_CURRENT_SOURCE_DIR}/applications/*main.cpp )

file(GLOB_RECURSE SRCS *.cpp)

file(GLOB_RECURSE UIS *.ui)

list(REMOVE_ITEM SRCS ${EXECUTABLES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(source_lib ${SRCS})
target_link_libraries(source_lib Qt5::Widgets Qt5::PrintSupport)
foreach(executable ${EXECUTABLES})
	get_filename_component(executable_we ${executable} NAME_WE)
	add_executable(${executable_we} ${executable})
	target_link_libraries(${executable_we} source_lib)

endforeach(executable)
