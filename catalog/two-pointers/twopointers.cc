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

bool smallerprefixes(std::vector<int> vec) {
  if (vec.size() % 2 != 0) return false;

  size_t slow = 0;
  size_t fast = 0;
  int slow_sum = 0;
  int fast_sum = 0;
  while (fast < vec.size()) {
    slow_sum += vec.at(slow);
    fast_sum += vec.at(fast) + vec.at(fast + 1);
    if (slow_sum >= fast_sum) return false;

    slow += 1;
    fast += 2;
  }
  return true;
}

std::vector<int> arrayintersection(std::vector<int> a, std::vector<int> b) {
  std::vector<int> res_;
  size_t p1 = 0;
  size_t p2 = 0;

  while (p1 < a.size() && p2 < b.size()) {
    if (a[p1] == b[p2]) {
      res_.push_back(a[p1]);
      p1++;
      p2++;
    } else if (a[p1] < b[p2]) {
      p1++;
    } else {
      p2++;
    }
  }

  return res_;
}
}  // twopointers
