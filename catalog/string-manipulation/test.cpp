#include <gtest/gtest.h>
#include "manipulation.h"

using namespace stringmanipulation;

TEST(IsAlphaNumericTest, Letters) {
  EXPECT_TRUE(isAlphaNumeric('a'));
  EXPECT_TRUE(isAlphaNumeric('z'));
  EXPECT_TRUE(isAlphaNumeric('A'));
  EXPECT_TRUE(isAlphaNumeric('Z'));
}

TEST(IsAlphaNumericTest, Numbers) {
  EXPECT_TRUE(isAlphaNumeric('0'));
  EXPECT_TRUE(isAlphaNumeric('5'));
  EXPECT_TRUE(isAlphaNumeric('9'));
}

TEST(IsAlphaNumericTest, NonAlphaNumeric) {
  EXPECT_FALSE(isAlphaNumeric('!'));
  EXPECT_FALSE(isAlphaNumeric(' '));
  EXPECT_FALSE(isAlphaNumeric('\n'));
}

TEST(ToUpperCaseTest, LowercaseToUppercase) {
  EXPECT_EQ(toUpperCase('a'), 'A');
  EXPECT_EQ(toUpperCase('m'), 'M');
  EXPECT_EQ(toUpperCase('z'), 'Z');
}

TEST(ToUpperCaseTest, AlreadyUppercase) {
  EXPECT_EQ(toUpperCase('A'), 'A');
  EXPECT_EQ(toUpperCase('Z'), 'Z');
}

TEST(ToUpperCaseTest, NonAlphabeticCharacters) {
  EXPECT_EQ(toUpperCase('0'), '0');  // numbers should be unchanged
  EXPECT_EQ(toUpperCase('!'), '!');  // symbols should be unchanged
  EXPECT_EQ(toUpperCase(' '), ' ');  // spaces should be unchanged
}
