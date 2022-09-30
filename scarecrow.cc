#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  sleep(60);
  return 0;
}

