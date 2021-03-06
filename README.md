# InsecureProject

[![CMake](https://github.com/turtlesec-no/insecure_project/actions/workflows/build_cmake.yml/badge.svg)](https://github.com/turtlesec-no/insecure_project/actions/workflows/build_cmake.yml)

## CWEs

* [CWE-121, CWE-122 and CWE-124: Array Bounds](test/string_length/README.md)
* [CWE-190: Signed Integer Addition Overflow](test/signed_overflow/README.md)
* [CWE-190 and CWE-197: Bypassing Checks](test/check_bypass/README.md)
* [CWE-415 and CWE-416: Free In Error Path](test/free_use/README.md)
* [CWE-704: Unsigned/Signed Comparisons](test/comparisons/README.md)
* [CWE-704: Incorrect Type Conversion](test/type_conversion/README.md)

## CVEs

* [CVE-2014-0160: Heartbleed tests](test/heartbleed/README.md)
* [CVE-2014-0160: Heartbleed fuzztests](fuzz_test/heartbleed/README.md)

## Techniques

* [constexpr tests](test/constexpr/README.md)
* [fuzzing test](fuzz_test/simple/README.md)
