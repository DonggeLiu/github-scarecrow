#include <string>
extern "C" {
  #include <string.h>
}

void constructEchoCommand(const char *data, size_t size, char* command) {
  std::string temp = std::string("echo ") + '"' + std::string(data, size) + '"';
  strcpy(command, temp.c_str());
}


extern "C" int LLVMFuzzerTestOneInput(const char *data, size_t size) {
  if (data == NULL || size <= 0) {
    return 0;
  }
  // command = echo "data"\0
  char* command = (char*) malloc(5 + 1 + size + 1 + 1);
  constructEchoCommand(data, size, command);
  system(command);
  free(command);
  return 0;
}
