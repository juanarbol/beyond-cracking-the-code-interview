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

std::vector<std::string> split(const std::string& s, char ch) {
  std::vector<std::string> res;
  if (s.empty()) return res;

  size_t start = 0;
  size_t pos;

  while ((pos = s.find(ch, start)) != std::string::npos) {
    res.push_back(s.substr(start, pos - start));
    start = pos + 1;
  }

  // Always push the last token (even if empty)
  res.push_back(s.substr(start));

  return res;
}

}  // stringmanipulation
