// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include <catch2/catch.hpp>

#include "signed_overflow.hpp"

#define DISABLE_TESTS

#ifdef DISABLE_TESTS
#define TEST_TAGS "[.][signed_overflow]"
#else
#define TEST_TAGS "[signed_overflow]"
#endif

TEST_CASE("CWE-190- 1: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(additionWillOverflow(INT_MAX, 256));
}

TEST_CASE("CWE-190 - 2: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(!additionWillOverflow(INT_MAX, 0));
}

TEST_CASE("CWE-190 - 3: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(!additionWillOverflow(0, INT_MAX));
}

TEST_CASE("CWE-190 - 4: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(!additionWillOverflow(256, 256));
}

TEST_CASE("CWE-190 - 5: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(additionWillOverflow(INT_MAX - 1, INT_MAX - 1));
}

TEST_CASE("CWE-190 - 6: Signed Integer Addition Overflow", TEST_TAGS)
{
  REQUIRE(additionWillOverflow(-42, INT_MIN));
}

TEST_CASE("CWE-190 - 7: Signed Integer Addition Overflow", TEST_TAGS)
{
  REQUIRE(additionWillOverflow(INT_MIN, -42));
}

TEST_CASE("CWE-190 - 8: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(!additionWillOverflow(INT_MAX - 256, 256));
}
