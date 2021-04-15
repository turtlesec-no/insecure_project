#include <catch2/catch.hpp>
#include <cstring>

extern "C" {
#include "heartbleed.h"
}

TEST_CASE("Returns_the_buffer_on_valid_request", "[heartbleed]")
{
  const int valid_len = 7;

  char valid_request[valid_len];
  valid_request[0] = '\x01';// Response type is 1
  valid_request[1] = '\x00';// Size
  valid_request[2] = '\x07';// Size = 7 bytes
  valid_request[3] = '\xde';// Payload byte 0
  valid_request[4] = '\xad';// Payload byte 1
  valid_request[5] = '\xbe';// Payload byte 2
  valid_request[6] = '\xef';// Payload byte 3

  char *response = nullptr;
  REQUIRE(0 == heartbleed(reinterpret_cast<unsigned char *>(valid_request), valid_len, &response));
  REQUIRE(nullptr != response);

  REQUIRE('\x02' == response[0]);// Response type is 2
  REQUIRE('\x00' == response[1]);// Size
  REQUIRE('\x07' == response[2]);// Size = 7 bytes
  REQUIRE('\xde' == response[3]);// Payload byte 0
  REQUIRE('\xad' == response[4]);// Payload byte 1
  REQUIRE('\xbe' == response[5]);// Payload byte 2
  REQUIRE('\xef' == response[6]);// Payload byte 3
}

TEST_CASE("Does_not_leak_info_small", "[heartbleed]")
{
  char short_request[] = "\x01\x01\xfd\x00";
  size_t short_len = strlen(short_request);

  char *response = nullptr;
  REQUIRE(0 == heartbleed(reinterpret_cast<unsigned char *>(short_request), int(short_len), &response));
  REQUIRE(NULL == response);
}

TEST_CASE("Does_not_leak_info_large", "[heartbleed]")
{
  char long_request[] = "\x01\x01\xfd\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\xde\xad\xbe\xef\x00";
  size_t long_len = strlen(long_request);

  char *response = nullptr;
  REQUIRE(0 == heartbleed(reinterpret_cast<unsigned char *>(long_request), int(long_len), &response));
  REQUIRE(NULL == response);
}
