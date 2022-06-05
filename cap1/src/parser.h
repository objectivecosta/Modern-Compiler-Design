#include <string>
#include "token.h"

#ifndef PARSER
#define PARSER 1

class Parser {
  protected:
  std::string input;
  public:
    virtual void parse() = 0;
    virtual ~Parser() = default;
};

Parser* createParser(std::string input);

#endif