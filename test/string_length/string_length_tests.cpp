// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include <catch2/catch.hpp>

#include "string_length.hpp"

#define DISABLE_TESTS

#ifdef DISABLE_TESTS
#define TEST_TAGS "[.][string_length]"
#else
#define TEST_TAGS "[string_length]"
#endif

TEST_CASE("StringLength: Use for testing hypothesis", "[string_length]")
{
  REQUIRE(1 == 1);
}

TEST_CASE("CWE-121 - 1: Access Outside Array Bounds", TEST_TAGS)
{
  // Null terminated string
  char str[] = "00112233445566";
  REQUIRE(stringLength(14, str) == 14);
}

TEST_CASE("CWE-121 - 2: Access Outside Array Bounds", TEST_TAGS)
{
  // String not terminated
  char str[] = "00112233445566";
  str[14] = 42;
  REQUIRE(stringLength(14, str) == 14);
}

TEST_CASE("CWE-121 - 3: Access Outside Array Bounds", TEST_TAGS)
{
  // Null terminated string
  char ten[] = "0123456789";
  REQUIRE(stringLength(10, ten) == 10);
}

TEST_CASE("CWE-121 -4: Access Outside Array Bounds", TEST_TAGS)
{
  // Null inserted
  char ten[] = "0123456789";
  ten[6] = 0;
  REQUIRE(stringLength(10, ten) == 6);
}

TEST_CASE("CWE-122 - 1: Write Outside Heap Array Bounds", TEST_TAGS)
{
  // Null terminated string
  char str[] = "00112233445566";
  char *copy = copyString(str, 14);
  REQUIRE(strnlen(copy, 14) == 14);
  free(copy);
}

TEST_CASE("CWE-122 - 2: Write Outside Heap Array Bounds", TEST_TAGS)
{
  // Null terminated string
  char str[] = "00112233445566";
  // String not terminated
  str[14] = 42;
  char *copy = copyString(str, 14);
  REQUIRE(strnlen(copy, 14) == 14);
  free(copy);
}

TEST_CASE("CWE-124 - 1: Write Before Array Bounds", TEST_TAGS)
{
  char str[] = "001122:33445566";
  REQUIRE(containsChar(str, ':', 15) == 7);
}

TEST_CASE("CWE-124 - 2: Write Before Array Bounds", TEST_TAGS)
{
  char str[] = "";
  REQUIRE(containsChar(str, ':', 0) == -1);
}

TEST_CASE("CWE-124 - 3: Write Before Array Bounds", TEST_TAGS)
{
  char str[] = "00112233445566";
  REQUIRE(containsChar(str, ':', 14) == -1);
}
