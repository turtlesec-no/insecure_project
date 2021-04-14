#include <iterator>
#include <vector>

extern "C" {
#include "heartbleed.h"
}

// Fuzzer that attempts to invoke undefined behavior for signed integer overflow
// cppcheck-suppress unusedFunction symbolName=LLVMFuzzerTestOneInput
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
  std::vector<unsigned char> buffer(Data, Data + Size);
  heartbleed(buffer.data(), int(buffer.size()), nullptr);
  return 0;
}
