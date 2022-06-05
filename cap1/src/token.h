#ifndef TOKEN
#define TOKEN 1

class Token {
  public:
  int type; 
  char repr;

  bool isLayoutCharacter();
};

#endif