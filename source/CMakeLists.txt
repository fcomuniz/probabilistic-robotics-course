add_subdirectory(core)
include_directories(core)
if(WITH_TEST)
    message(WARNING "building tests folder")
    enable_testing()
    add_subdirectory(tests)
else()
    message(WARNING "not building tests folder")
endif()