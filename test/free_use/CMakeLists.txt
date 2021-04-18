add_executable(free_use_tests free_use_tests.cpp free_use.cpp)

if (ENABLE_TEST_WARNINGS)
    target_link_libraries(free_use_tests PRIVATE project_warnings project_options catch_main)
else ()
    target_link_libraries(free_use_tests PRIVATE project_options catch_main)
endif ()

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
        free_use_tests
        TEST_PREFIX
        "unittests."
        REPORTER
        xml
        OUTPUT_DIR
        .
        OUTPUT_PREFIX
        "unittests."
        OUTPUT_SUFFIX
        .xml)
