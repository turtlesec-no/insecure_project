// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "check_bypass.hpp"
#include <catch2/catch.hpp>

TEST_CASE("[check_bypass] CWE-190 (Unsigned): Integer Overflow or Wraparound", "[check_bypass]")
{
  // Unsigned : Small enough
  REQUIRE(bypassedCheckUnsigned(42, 42));
  // Unsigned : Too big
  REQUIRE(!bypassedCheckUnsigned(256, 256));
  // Unsigned : Bypass check
  //REQUIRE( bypassedCheckUnsigned(<FIRST>, <SECOND>) );
}

TEST_CASE("[check_bypass] CWE-190 (Signed): Integer Overflow or Wraparound", "[check_bypass]")
{
  // Signed : Small enough
  REQUIRE(bypassedCheckSigned(42, 42));
  // Signed : Too big
  REQUIRE(!bypassedCheckSigned(256, 256));
  // Signed : Bypass check
  //REQUIRE( bypassedCheckSigned(<FIRST>, <SECOND>) );
}

TEST_CASE("[check_bypass] CWE-197 (Truncation): Numeric Truncation Error", "[check_bypass]")
{
  // Truncated : Small enough
  REQUIRE(bypassedCheckTruncated(42, 42));
  // Truncated : Too big
  REQUIRE(!bypassedCheckTruncated(256, 256));
  // Truncated : Bypass check
  //REQUIRE( bypassedCheckTruncated(<FIRST>, <SECOND>) );
}
