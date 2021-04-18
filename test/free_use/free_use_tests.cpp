// For more on how to use the excellent Catch test framework see
// https://github.com/catchorg/Catch2

#include "free_use.hpp"
#include <catch2/catch.hpp>

#define DISABLE_TESTS

#ifdef DISABLE_TESTS
#define TEST_TAGS "[.][free_use]"
#else
#define TEST_TAGS "[free_use]"
#endif

TEST_CASE("[free_use][1] CWE-415 and CWE-416: Free In Error Path", "[free_use]")
{
  char *buffer = make_buffer(4);
  REQUIRE(buffer != nullptr);
  free(buffer);
}

TEST_CASE("[free_use][2] CWE-415 and CWE-416: Free In Error Path", TEST_TAGS)
{
  char *buffer = make_buffer(5);
  REQUIRE(buffer != nullptr);
  free(buffer);
}
