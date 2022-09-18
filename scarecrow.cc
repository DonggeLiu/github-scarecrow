#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  char *x = (char*)malloc(size * sizeof(char*));
  free(x);
  return data[size];
}

