file(GLOB_RECURSE SRCS *Test.cpp)

#Google test

# We need thread support
find_package(Threads REQUIRED)

include(ExternalProject)
ExternalProject_Add(
        googletest
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        GIT_REPOSITORY "https://github.com/google/googletest.git"
        GIT_TAG master
        INSTALL_COMMAND ""
        UPDATE_DISCONNECTED 1
)

ExternalProject_Get_Property(googletest source_dir binary_dir)

set_directory_properties(${binary_dir} CLEAN_NO_CUSTOM 1)

add_library(libgtest IMPORTED STATIC)
add_dependencies(libgtest googletest)
set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
        )


include_directories(${source_dir}/googletest/include)


add_library(libgmock IMPORTED STATIC)

add_dependencies(libgmock googletest)
set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")
# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
#	include_directories("${source_dir}/include")

include_directories(${source_dir}/googlemock/include)
# End of google test

set(UNIT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

foreach(file_path ${SRCS})
    get_filename_component(dir_path ${file_path} PATH)
    get_filename_component(file_name_we ${file_path} NAME_WE)
    add_executable(${file_name_we} ${file_path} ${UNIT_DIR}/AllTests.cpp)
    target_link_libraries(${file_name_we} libgtest libgmock source_lib )
    add_test(NAME ${file_name_we}
            COMMAND ${file_name_we})
endforeach()

add_executable(AllTests ${SRCS} ${UNIT_DIR}/AllTests.cpp)
target_link_libraries(AllTests libgtest libgmock source_lib )
add_test(NAME AllTests
        COMMAND AllTests)

