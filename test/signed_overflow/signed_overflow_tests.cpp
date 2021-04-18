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

TEST_CASE("[signed_overflow][1] CWE-190: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(additionWillOverflow(INT_MAX, 256));
}

TEST_CASE("[signed_overflow][2] CWE-190: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(!additionWillOverflow(INT_MAX, 0));
}

TEST_CASE("[signed_overflow][3] CWE-190: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(!additionWillOverflow(0, INT_MAX));
}

TEST_CASE("[signed_overflow][4] CWE-190: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(!additionWillOverflow(256, 256));
}

TEST_CASE("[signed_overflow][5] CWE-190: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(additionWillOverflow(INT_MAX - 1, INT_MAX - 1));
}

TEST_CASE("[signed_overflow][6] CWE-190: Signed Integer Addition Overflow", TEST_TAGS)
{
  REQUIRE(additionWillOverflow(-42, INT_MIN));
}

TEST_CASE("[signed_overflow][7] CWE-190: Signed Integer Addition Overflow", TEST_TAGS)
{
  REQUIRE(additionWillOverflow(INT_MIN, -42));
}

TEST_CASE("[signed_overflow][8] CWE-190: Signed Integer Addition Overflow", "[signed_overflow]")
{
  REQUIRE(!additionWillOverflow(INT_MAX - 256, 256));
}
