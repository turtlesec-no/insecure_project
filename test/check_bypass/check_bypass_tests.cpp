// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "check_bypass.hpp"
#include <catch2/catch.hpp>

TEST_CASE("CWE-190 (Unsigned): Integer Overflow or Wraparound", "[integer]")
{
  // Unsigned : Small enough
  REQUIRE(bypassedCheckUnsigned(42, 42));
  // Unsigned : Too big
  REQUIRE(!bypassedCheckUnsigned(256, 256));
  // Unsigned : Bypass check
  //REQUIRE( bypassedCheckUnsigned(<FIRST>, <SECOND>) );
}

TEST_CASE("CWE-190 (Signed): Integer Overflow or Wraparound", "[integer]")
{
  // Signed : Small enough
  REQUIRE(bypassedCheckSigned(42, 42));
  // Signed : Too big
  REQUIRE(!bypassedCheckSigned(256, 256));
  // Signed : Bypass check
  //REQUIRE( bypassedCheckSigned(<FIRST>, <SECOND>) );
}

TEST_CASE("CWE-197 (Truncation): Numeric Truncation Error", "[integer]")
{
  // Truncated : Small enough
  REQUIRE(bypassedCheckTruncated(42, 42));
  // Truncated : Too big
  REQUIRE(!bypassedCheckTruncated(256, 256));
  // Truncated : Bypass check
  //REQUIRE( bypassedCheckTruncated(<FIRST>, <SECOND>) );
}
