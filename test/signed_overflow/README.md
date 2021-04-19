[< Back](../../README.md)

## CWE-190: Signed Integer Addition Overflow

Observe that if you enable the tests you will see errors with the ASan
* Comment out the line with *#define DISABLE_TESTS* in the test
  file [signed_overflow_tests.cpp](signed_overflow_tests.cpp)

Modify additionWillOverflow so that all the tests pass while not triggering any warnings or sanitizers.
