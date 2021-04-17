#include "string_length.hpp"

#include <string.h>

int stringLength(int size, const char *input)
{
  return strnlen(input, size);
}

char *copyString(const char *input, int size)
{
  char *buf = (char *)malloc(sizeof(char) * size);
  strncpy(buf, input, size);
  return buf;
}
