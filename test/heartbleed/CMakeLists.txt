add_executable(heartbleed_tests heartbleed_tests.cpp)
target_link_libraries(heartbleed_tests PRIVATE project_warnings project_options catch_main libheartbleed)
target_include_directories(heartbleed_tests PRIVATE ../../src/heartbleed)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
        heartbleed_tests
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
