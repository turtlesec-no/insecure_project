# A fuzz test runs until it finds an error. This particular one is going to rely on libFuzzer.
#

SET(fuzz_options -fsanitize=fuzzer,undefined,address)

add_executable(fuzz_tester fuzz_tester.cpp)
target_link_libraries(fuzz_tester PRIVATE project_options project_warnings CONAN_PKG::fmt -coverage ${fuzz_options})
target_compile_options(fuzz_tester PRIVATE ${fuzz_options})

# Allow short runs during automated testing to see if something new breaks
set(FUZZ_RUNTIME 10 CACHE STRING "Number of seconds to run fuzz tests during ctest run")
set(FUZZ_MEMORY 2048 CACHE STRING "Number of Mb used during ctest run")

add_test(NAME fuzz_tester_run COMMAND fuzz_tester -max_total_time=${FUZZ_RUNTIME} -rss_limit_mb=${FUZZ_MEMORY})
