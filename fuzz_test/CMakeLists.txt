# A fuzz test runs until it finds an error. This particular one is going to rely on libFuzzer.
#
option(RUN_HEARTBLEED_FUZZ_TEST_IN_CTEST "Enable running the heartbleed_fuzz_tester as a part of CTEST" OFF)

SET(fuzz_options -fsanitize=fuzzer,undefined,address)

# Allow short runs during automated testing to see if something new breaks
set(FUZZ_RUNTIME 10 CACHE STRING "Number of seconds to run fuzz tests during ctest run")
set(FUZZ_MEMORY 2048 CACHE STRING "Number of Mb used during ctest run")

add_executable(fuzz_tester simple/fuzz_tester.cpp)
target_link_libraries(fuzz_tester PRIVATE project_options project_warnings CONAN_PKG::fmt -coverage ${fuzz_options})
target_compile_options(fuzz_tester PRIVATE ${fuzz_options})
add_test(NAME fuzz_tester_run COMMAND fuzz_tester -max_total_time=${FUZZ_RUNTIME} -rss_limit_mb=${FUZZ_MEMORY})

if(RUN_HEARTBLEED_FUZZ_TEST_IN_CTEST)
add_executable(heartbleed_fuzz_tester heartbleed/heartbleed_fuzz_tester.cpp)
target_link_libraries(heartbleed_fuzz_tester PRIVATE project_options project_warnings libheartbleed -coverage ${fuzz_options})
target_compile_options(heartbleed_fuzz_tester PRIVATE ${fuzz_options})
target_include_directories(heartbleed_fuzz_tester PRIVATE ../src/heartbleed)
add_test(NAME heartbleed_fuzz_tester_run COMMAND heartbleed_fuzz_tester -max_total_time=${FUZZ_RUNTIME} -rss_limit_mb=${FUZZ_MEMORY})
endif()
