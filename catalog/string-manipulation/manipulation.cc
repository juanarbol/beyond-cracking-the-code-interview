#include "manipulation.h"

namespace stringmanipulation {
bool isAlphaNumeric (char ch) {
  bool isAlpha = ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
  bool isNum = ch >= '0' && ch <= '9';
  return isAlpha || isNum;
}

char toUpperCase (char ch) {
  if (ch >= 'a' && ch <= 'z')
    return ch - 32;
  else
    return ch;
}
}  // stringmanipulation
