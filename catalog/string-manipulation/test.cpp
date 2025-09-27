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

TEST(SplitTest, EmptyString) {
  std::string input = "";
  auto result = split(input, ',');
  EXPECT_TRUE(result.empty());     // []
}

TEST(SplitTest, NoDelimiter) {
  std::string input = "hello";
  auto result = split(input, ',');
  ASSERT_EQ(result.size(), 1u);
  EXPECT_EQ(result[0], "hello");  // ["hello"]
}

TEST(SplitTest, SingleDelimiter) {
  std::string input = "a,b";
  auto result = split(input, ',');
  ASSERT_EQ(result.size(), 2u);
  EXPECT_EQ(result[0], "a");
  EXPECT_EQ(result[1], "b");      // ["a","b"]
}

TEST(SplitTest, MultipleDelimiters) {
  std::string input = "one,two,three";
  auto result = split(input, ',');
  ASSERT_EQ(result.size(), 3u);
  EXPECT_EQ(result[0], "one");
  EXPECT_EQ(result[1], "two");
  EXPECT_EQ(result[2], "three");  // ["one","two","three"]
}

TEST(SplitTest, LeadingDelimiter) {
  std::string input = ",start";
  auto result = split(input, ',');
  ASSERT_EQ(result.size(), 2u);
  EXPECT_EQ(result[0], "");       // ["", "start"]
  EXPECT_EQ(result[1], "start");
}

TEST(SplitTest, TrailingDelimiter) {
  std::string input = "end,";
  auto result = split(input, ',');
  ASSERT_EQ(result.size(), 2u);
  EXPECT_EQ(result[0], "end");
  EXPECT_EQ(result[1], "");       // ["end", ""]
}

TEST(SplitTest, TrailingDelimiter2) {
  std::string input = "end,,";
  auto result = split(input, ',');
  ASSERT_EQ(result.size(), 3u);
  EXPECT_EQ(result[0], "end");
  EXPECT_EQ(result[1], "");       // ["end", "", ""]
}

TEST(JoinTest, EmptyVector) {
  std::vector<std::string> input;
  auto result = join(input, ',');
  EXPECT_EQ(result, "");
}

TEST(JoinTest, SingleElement) {
  std::vector<std::string> input = {"hello"};
  auto result = join(input, ',');
  EXPECT_EQ(result, "hello");
}

TEST(JoinTest, MultipleElements) {
  std::vector<std::string> input = {"a", "b", "c"};
  auto result = join(input, ',');
  EXPECT_EQ(result, "a,b,c");
}

TEST(JoinTest, CustomDelimiter) {
  std::vector<std::string> input = {"foo", "bar"};
  auto result = join(input, '-');
  EXPECT_EQ(result, "foo-bar");
}

TEST(JoinTest, IncludesEmptyStrings) {
  std::vector<std::string> input = {"", "b", ""};
  auto result = join(input, ',');
  EXPECT_EQ(result, ",b,");
}

TEST(IndexOfTest, EmptyStrings) {
  EXPECT_EQ(index_of("", ""), 0);       // convention: empty string found at 0
  EXPECT_EQ(index_of("abc", ""), 0);    // empty pattern → 0
  EXPECT_EQ(index_of("", "a"), -1);     // pattern longer than text
}

TEST(IndexOfTest, SingleCharacter) {
  EXPECT_EQ(index_of("abc", "a"), 0);
  EXPECT_EQ(index_of("abc", "b"), 1);
  EXPECT_EQ(index_of("abc", "c"), 2);
  EXPECT_EQ(index_of("abc", "z"), -1);
}

TEST(IndexOfTest, MultipleCharacters) {
  EXPECT_EQ(index_of("hello", "he"), 0);
  EXPECT_EQ(index_of("hello", "ell"), 1);
  EXPECT_EQ(index_of("hello", "llo"), 2);
  EXPECT_EQ(index_of("hello", "hello"), 0);
  EXPECT_EQ(index_of("hello", "helloo"), -1);
}

TEST(IndexOfTest, OverlappingPatterns) {
  EXPECT_EQ(index_of("aaaaa", "aaa"), 0);   // first occurrence only
  EXPECT_EQ(index_of("ababab", "bab"), 1);
}

TEST(IndexOfTest, NotFoundCases) {
  EXPECT_EQ(index_of("abcdef", "gh"), -1);
  EXPECT_EQ(index_of("abcdef", "xyz"), -1);
}
