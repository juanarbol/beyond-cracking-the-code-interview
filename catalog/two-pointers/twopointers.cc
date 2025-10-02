#include "twopointers.h"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstddef>

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

// O(n)
bool palindromesentence(const std::string& s) {
  if (s.empty()) return false;
  size_t l = 0;
  size_t r = s.size() - 1;

  while (l < r) {
    if (!std::isalpha(static_cast<unsigned char>(s[l]))) {
      l++;
      continue;
    }
    if (!std::isalpha(static_cast<unsigned char>(s[r]))) {
      r--;
      continue;
    }

    if (std::tolower(static_cast<unsigned char>(s[l])) ==
        std::tolower(static_cast<unsigned char>(s[r]))) {
      l++;
      r--;
    } else {
      return false;
    }
  }
  return true;
}

// O(2n) ~ O(n)
bool reversecasematch(const std::string& s) {
  if (s.empty() || s.size() == 1) return true;

  int l = 0;
  int r = s.size() - 1;

  while (l < s.size() && r >= 0) {
    if (!std::islower(s[l])) {
      l++;
      continue;
    }
    if (!std::isupper(s[r])) {
      r--;
      continue;
    }

    if (s[l] != std::tolower(s[r]))
      return false;

    l++;
    r--;
  }
  return true;
}

// O(n)
std::vector<int> mergesortedarrays(const std::vector<int>& a, const std::vector<int>& b) {
  // input sanitize
  if (a.empty()) return b;
  if (b.empty()) return a;

  std::vector<int> res;
  size_t p1 = 0;
  size_t p2 = 0;

  while (p1 < a.size() && p2 < b.size()) {
    if (a[p1] < b[p2]) {
      res.push_back(a[p1]);
      p1++;
    } else {
      res.push_back(b[p2]);
      p2++;
    }
  }

  /* At this point at least one vector is fully completed */

  while (p1 < a.size()) {
    res.push_back(a[p1]);
    p1++;
  }

  while (p2 < b.size()) {
    res.push_back(b[p2]);
    p2++;
  };

  return res;
}

// A is sorted
// O(n) space O(1)
bool twosum(std::vector<int> a) {
  if (a.empty()) return false;

  size_t l = 0;
  size_t r = a.size() - 1;

  while (l < r) {
    int sum = a[l] + a[r];
    if (sum == 0) return true;
    if (sum < 0) l++;  // sum is too small, move forward
    else r--;
  }

  return false;
}

// NOTE: NO DUPES
// NOTE: WE HAVE TO RE DO THIS WITH ACTUAL POINTERS INSTEAD OF C++ HELPERS
std::vector<int> merge3sortedarrays(const std::vector<int>& a, const std::vector<int>& b, const std::vector<int>& c) {
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;
  std::vector<int> res;

  /* Invariant: at least one arr is not finished */
  while (i < a.size() || j < b.size() || k < c.size()) {
    int val = INT_MAX;

    /* Find the min of the three numbers */
    if (i < a.size()) val = std::min(val, a[i]);
    if (j < b.size()) val = std::min(val, b[j]);
    if (k < c.size()) val = std::min(val, c[k]);

    /* Push the minimum value */
    if (res.empty() || res.back() != val) res.push_back(val);

    /* Move the pointer, but only the one referenced */
    if (i < a.size() && a[i] == val) i++;
    if (j < b.size() && b[j] == val) j++;
    if (k < c.size() && c[k] == val) k++;
  }

  return res;
}


// O(n)
std::vector<int> sortvalleyshaped(const std::vector<int>& a) {
  if (a.empty()) return {};

  std::vector<int> res(a.size());

  size_t l = 0;
  size_t r = a.size() - 1;
  size_t i = a.size() - 1;

  // O(n)
  // Pretty much put in place, sort using the valley property
  while (l < r) {
    if (a[l] > a[r]) {
      res[i] = a[l];
      l++;
    } else {
      res[i] = a[r];
      r--;
    }
    i--;
  }

  res[0] = a[l];

  return res;
}

// O(n) worst case
std::vector<int> missinginrange(const std::vector<int>& a, int low, int hight) {
  size_t i = 0;
  int num = low;
  std::vector<int> res;
  while (num <= hight) {
    if (i < a.size() && a[i] < num) {
      // move pointer
      i++;
    } else if (i < a.size() && a[i] == num) {
      // found skip
      i++;
      num++;
    } else {
      // not found... in the list
      res.push_back(num);
      num++;
    }
  }
  return res;
}

}  // twopointers
