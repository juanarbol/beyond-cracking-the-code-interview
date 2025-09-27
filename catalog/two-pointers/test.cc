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
