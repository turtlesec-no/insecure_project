option(ENABLE_TEST_WARNINGS "Will enable project warnings on the tests" OFF)

add_executable(string_length_tests string_length_tests.cpp string_length.cpp)

if (ENABLE_TEST_WARNINGS)
    target_link_libraries(string_length_tests PRIVATE project_warnings project_options catch_main)
else ()
    target_link_libraries(string_length_tests PRIVATE project_options catch_main)
endif ()

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
        string_length_tests
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
