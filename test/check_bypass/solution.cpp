REQUIRE(bypassedCheckUnsigned(UINT_MAX, 256));
REQUIRE(bypassedCheckSigned(INT_MAX, 256));
REQUIRE(bypassedCheckTruncated(UINT_MAX - 256, 256));