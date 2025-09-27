#include "manipulation.h"
#include <execution>

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

std::string join(const std::vector<std::string>& parts, char ch) {
  std::string res;
  if (parts.empty()) return res;

  size_t total_size = 0;
  for (const auto& s : parts) {
    total_size += s.size() + 1;
  }

  res.reserve(total_size - 1); // no delimiter after the last element

  // Append elements
  for (size_t i = 0; i < parts.size(); i++) {
    res.append(parts[i]);
    // Just between elements
    if (i != parts.size() - 1) res.push_back(ch);
  }

  return res;
}

int index_of(const std::string& s, const std::string& t) {
  if (t.empty()) return 0;
  if (t.size() > s.size()) return -1;

  size_t start = 0;
  // O(n - m + 1) n = s.size(); m = t.size(); + 1 worst case
  while (start + t.size() <= s.size() ) {
    // O(m) = copies m chars
    std::string res = s.substr(start, t.size());
    if (res == t) return static_cast<int>(start);
    start += 1;
  }
  // O((n - m + 1) * m) -> O(n * m);

  return -1;
}

}  // stringmanipulation
