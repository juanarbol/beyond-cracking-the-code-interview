#include "twopointers.h"

namespace twopointers {
bool palindrome(const std::string &s) {
  if (s.empty()) return false;

  size_t l= 0;
  size_t r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r]) return false;
    l++;
    r--;
  }

  return true;
}
}
