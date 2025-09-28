#ifndef TWOPOINTERS_H
#define TWOPOINTERS_H

#include <string>
#include <vector>
#include <cctype>  // isalpha

namespace twopointers {
bool palindrome(const std::string& s);
bool smallerprefixes(std::vector<int> vec);
std::vector<int> arrayintersection(std::vector<int> a, std::vector<int> b);
bool palindromesentence(const std::string& s);
}

#endif
