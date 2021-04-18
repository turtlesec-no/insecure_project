// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include <catch2/catch.hpp>

extern "C" {
#include "type_conversion.h"
}

#define DISABLE_TESTS

#ifdef DISABLE_TESTS
#define TEST_TAGS "[.][type_conversion]"
#else
#define TEST_TAGS "[type_conversion]"
#endif

TEST_CASE("[type_conversion][1] Use for testing hypothesis", "[type_conversion]")
{
  REQUIRE(1 == 1);
}

TEST_CASE("[type_conversion][2] CWE-704: Incorrect Type Conversion", TEST_TAGS)
{
  int value = 0;
  int *ptr = &value;
  REQUIRE(process(ptr) == ptr);
}
