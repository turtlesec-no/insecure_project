[< Back](../../README.md)

## CWE-121, CWE-122 and CWE-124: Array Bounds

Observe that if you enable the tests you will see errors with the ASan
* Comment out the line with *#define DISABLE_TESTS* in the test file [string_length_tests.cpp](string_length_tests.cpp)

Observe that if you enable the warnings the code no longer compiles
* Turn on the **ENABLE_TEST_WARNINGS** option in the [CMakeLists.txt](CMakeLists.txt) file
