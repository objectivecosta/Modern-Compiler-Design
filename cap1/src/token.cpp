#include "token.h"

bool Token::isLayoutCharacter() {
  switch (this->repr) {
    case ' ': case '\t': case '\n': return true;
    default: return false;
  }
}