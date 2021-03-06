// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include <catch2/catch.hpp>

#include <array>
#include <cstring>

extern "C" {
#include "heartbleed.h"
}

#define DISABLE_TESTS

#ifdef DISABLE_TESTS
#define TEST_TAGS "[.][heartbleed]"
#else
#define TEST_TAGS "[heartbleed]"
#endif

TEST_CASE("[heartbleed][1] Use for testing hypothesis", "[heartbleed]")
{
  REQUIRE(1 == 1);
}

TEST_CASE("[heartbleed][2] CVE-2014-0160: Heartbleed: Returns_the_buffer_on_valid_request", TEST_TAGS)
{
  std::array<unsigned char, 7> valid_request = {
    u'\x01',// Request type is 1
    u'\x00',// Size
    u'\x07',// Size = 7 bytes
    u'\xde',// Payload byte 0
    u'\xad',// Payload byte 1
    u'\xbe',// Payload byte 2
    u'\xef'// Payload byte 3
  };

  char *response = nullptr;
  REQUIRE(0 == heartbleed(valid_request.data(), int(valid_request.size()), &response));
  REQUIRE(nullptr != response);

  REQUIRE('\x02' == response[0]);// Response type is 2
  REQUIRE('\x00' == response[1]);// Size
  REQUIRE('\x07' == response[2]);// Size = 7 bytes
  REQUIRE('\xde' == response[3]);// Payload byte 0
  REQUIRE('\xad' == response[4]);// Payload byte 1
  REQUIRE('\xbe' == response[5]);// Payload byte 2
  REQUIRE('\xef' == response[6]);// Payload byte 3
}

TEST_CASE("[heartbleed][3] CVE-2014-0160: Heartbleed: Does_not_leak_info_small", TEST_TAGS)
{
  std::array<unsigned char, 4> short_request = {
    u'\x01',
    u'\x01',
    u'\xfd',
    u'\x00',
  };

  char *response = nullptr;
  REQUIRE(0 == heartbleed(short_request.data(), int(short_request.size()), &response));
  REQUIRE(nullptr == response);
}

TEST_CASE("[heartbleed][4] CVE-2014-0160: Heartbleed: Does_not_leak_info_large", TEST_TAGS)
{
  std::array<unsigned char, 20> long_request = {
    u'\x01',
    u'\x01',
    u'\xfd',
    u'\xde',
    u'\xad',
    u'\xbe',
    u'\xef',
    u'\xde',
    u'\xad',
    u'\xbe',
    u'\xef',
    u'\xde',
    u'\xad',
    u'\xbe',
    u'\xef',
    u'\xde',
    u'\xad',
    u'\xbe',
    u'\xef',
    u'\x00',
  };

  char *response = nullptr;
  REQUIRE(0 == heartbleed(long_request.data(), int(long_request.size()), &response));
  REQUIRE(nullptr == response);
}
