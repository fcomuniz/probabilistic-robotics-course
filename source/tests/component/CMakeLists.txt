file(GLOB_RECURSE COMPONENT_TESTS *ComponentTest.cpp)

foreach(test ${COMPONENT_TESTS})
    get_filename_component(test_we ${test} NAME_WE)
    add_executable(${test_we} ${test})
    target_link_libraries(${test_we} source_lib)
endforeach()