#include <stdlib.h>
#include <iostream>
#include "parser.h"
#include "expression.h"
#include "lex.cpp"

class ParserImpl : public Parser
{
public:
  ParserImpl(std::string input);
  virtual void parse();

private:
  std::string input;
  int currentIndex;
  Token *currentToken;

  void consumeNextToken();
  int parseOperator(int *oper);
  int parseExpression(Expression **expr_p);
};

Parser *createParser(std::string input)
{
  return new ParserImpl(input);
}

ParserImpl::ParserImpl(std::string input) : currentIndex(-1), input(input){};

void ParserImpl::consumeNextToken()
{
  currentIndex = currentIndex + 1;

  if (currentIndex >= this->input.size())
  {
    currentToken = nullptr;
  }

  char character = this->input[currentIndex];

  Token *token_inst = new Token();

  if (character < 0)
  {
    // End of File;
    std::cout << "ParserImpl::getNextToken() Got EoF-'" << character << "' @" << currentIndex <<"\n";
    currentToken = nullptr;
  }
  else if ('0' <= character && character <= '9')
  {
    std::cout << "ParserImpl::getNextToken() Got DIGIT-'" << character << "' @" << currentIndex <<"\n";
    token_inst->type = DIGIT;
  }
  else
  {
    std::cout << "ParserImpl::getNextToken() Got Character-'" << character << "' @" << currentIndex <<"\n";
    token_inst->type = character;
  }

  token_inst->repr = character;
  currentToken = token_inst;
}

int ParserImpl::parseOperator(int *oper)
{
  Token& token_inst = *currentToken;
  if (token_inst.type == '+')
  {
    *oper = '+';
    consumeNextToken();
    return 1;
  }
  else if (token_inst.type == '*')
  {
    *oper = '*';
    consumeNextToken();
    return 1;
  }
  return 0;
}

int ParserImpl::parseExpression(Expression **expr_p)
{
  Token& token_inst = *currentToken;
  Expression *expr = *expr_p = new Expression();
  if (token_inst.type == DIGIT)
  {
    expr->type = 'D';
    expr->value = token_inst.repr - '0';
    consumeNextToken();
    return 1;
  }
  /*try to parse a parenthesized expression : */
  if (token_inst.type == '(')
  {
    expr->type = 'P';
    consumeNextToken();
    if (currentToken != nullptr)
    {
      if (!this->parseExpression(&expr->left))
      {
        printf("Missing expression (left)\n");
      }
      if (!this->parseOperator(&expr->oper))
      {
        printf("Missing operator (middle)\n");
      }
      if (!this->parseExpression(&expr->right))
      {
        printf("Missing expression (right)\n");
      }
      if (currentToken->type != ')')
      {
        printf("Missing )\n");
      }
      consumeNextToken();
      return 1;
    }
  }
  return 0;
}

void ParserImpl::parse()
{
  Expression *expr;
  consumeNextToken();
  if (this->parseExpression(&expr)) {
    if (currentToken->type != EoF) {
      std::cout << "Garbage at the end of the program" << "\n";
    }

    std::cout << "Successfully parsed!" << "\n";
    // return 1;
  }

  // return 0;
}