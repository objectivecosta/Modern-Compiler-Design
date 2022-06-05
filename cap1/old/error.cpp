#include <stdlib.h>
#include <string>

class Error {
  public:
    Error(std::string error) {
      printf("Error instantiated!");
    }
};