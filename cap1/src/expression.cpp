#include "Expression.h"

class Expression
{
  public:
  char type;
  int value;
  struct Expression *left;
  struct Expression *right;
  Operator oper;
};