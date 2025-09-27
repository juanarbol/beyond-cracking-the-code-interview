#include <gtest/gtest.h>
#include "twopointers.h"  // where palindrome() is declared

using namespace twopointers;

TEST(PalindromeTest, EmptyString) {
  EXPECT_FALSE(palindrome(""));  // by design, empty is not palindrome
}

TEST(PalindromeTest, SingleCharacter) {
  EXPECT_TRUE(palindrome("a"));
  EXPECT_TRUE(palindrome("z"));
}

TEST(PalindromeTest, TwoCharacters) {
  EXPECT_TRUE(palindrome("aa"));
  EXPECT_FALSE(palindrome("ab"));
}

TEST(PalindromeTest, OddLengthPalindrome) {
  EXPECT_TRUE(palindrome("aba"));
  EXPECT_TRUE(palindrome("racecar"));
  EXPECT_TRUE(palindrome("level"));
}

TEST(PalindromeTest, EvenLengthPalindrome) {
  EXPECT_TRUE(palindrome("abba"));
  EXPECT_TRUE(palindrome("redder"));
}

TEST(PalindromeTest, NotPalindrome) {
  EXPECT_FALSE(palindrome("hello"));
  EXPECT_FALSE(palindrome("world"));
}

TEST(PalindromeTest, CaseSensitivity) {
  EXPECT_FALSE(palindrome("Racecar"));  // case-sensitive check
}

TEST(PalindromeTest, WithSpaces) {
  EXPECT_FALSE(palindrome("nurses run"));  // spaces break palindrome
  EXPECT_TRUE(palindrome("aa aa"));        // symmetric with space
}

TEST(SmallerPrefixesTest, EmptyVector) {
  std::vector<int> v;
  EXPECT_TRUE(smallerprefixes(v));  // vacuously true
}

TEST(SmallerPrefixesTest, OddSizeIsInvalid) {
  std::vector<int> v = {1, 2, 3};
  EXPECT_FALSE(smallerprefixes(v));
}

TEST(SmallerPrefixesTest, TwoElementsValid) {
  std::vector<int> v = {1, 5};
  EXPECT_TRUE(smallerprefixes(v));  // 1 < 1+5
}

TEST(SmallerPrefixesTest, TwoElementsInvalid) {
  std::vector<int> v = {5, 0};
  EXPECT_FALSE(smallerprefixes(v));  // 5 >= 5
}

TEST(SmallerPrefixesTest, FourElementsValid) {
  std::vector<int> v = {1, 2, 3, 4};
  EXPECT_TRUE(smallerprefixes(v));
  std::vector<int> v2 = {1, 2, 2, -1};
  EXPECT_TRUE(smallerprefixes(v2));
}

TEST(SmallerPrefixesTest, FourElementsInvalid) {
  std::vector<int> v = {3, 1, 0, 0};
  EXPECT_FALSE(smallerprefixes(v));
  std::vector<int> v2 = {1, 2, -2, 1, 3, 5};
  EXPECT_FALSE(smallerprefixes(v2));
}
