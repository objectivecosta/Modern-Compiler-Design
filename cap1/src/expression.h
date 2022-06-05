#ifndef EXP
#define EXP 1

typedef int Operator;

class Expression
{
  public:
  char type;
  int value;
  struct Expression *left;
  struct Expression *right;
  Operator oper;
};

#define EoF 256
#define DIGIT 257

typedef Expression AST_node;

#endif