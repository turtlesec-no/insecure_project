[< Back](../../README.md)

## CWE-704: Incorrect Type Conversion

Observe that if you enable the tests you will see errors with the ASan
* Comment out the line with *#define DISABLE_TESTS* in the test
  file [type_conversion_tests.cpp](type_conversion_tests.cpp)

Observe that if you enable the warnings the code no longer compiles
* Turn on the **ENABLE_TEST_WARNINGS** option in the [CMakeLists.txt](CMakeLists.txt) file
