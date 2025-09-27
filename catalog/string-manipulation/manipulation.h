#ifndef MANIPULATION_H
#define MANIPULATION_H

#include <string>
#include <vector>

namespace stringmanipulation {
bool isAlphaNumeric(char ch);
char toUpperCase(char ch);
std::vector<std::string> split(const std::string& s, char ch);
std::string join(const std::vector<std::string>& parts, char ch);
}  // stringmanipulation

#endif
