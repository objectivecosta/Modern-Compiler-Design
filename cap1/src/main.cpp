#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "parser.h"
#include "expression.h"
#include "token.h"

int main(int argc, char *argv[])
{
  std::cout << "argc == " << argc << '\n';
  std::string input = std::string("(2*((3*4)+9))");
  Parser *parser = createParser(input);
  parser->parse();
  return 0;
}