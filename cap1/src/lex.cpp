#include <stdio.h>
#include "token.h"
#include "expression.h"

#define EoF 256
#define DIGIT 257

static void Code_gen_expression(Expression *expr)
{
  switch (expr->type)
  {
  case 'D':
    printf("PUSH %d\n", expr->value);
    break;
  case 'P':
    Code_gen_expression(expr->left);
    Code_gen_expression(expr->right);
    switch (expr->oper)
    {
    case '+':
      printf("ADD\n");
      break;
    case '*':
      printf("MULT\n");
      break;
    }
    break;
  }
}

void Process(AST_node *icode)
{
  Code_gen_expression(icode);
  printf("PRINT\n");
}