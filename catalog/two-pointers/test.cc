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

TEST(ArrayIntersectionTest, BothEmpty) {
  std::vector<int> a;
  std::vector<int> b;
  auto result = arrayintersection(a, b);
  EXPECT_TRUE(result.empty());
}

TEST(ArrayIntersectionTest, OneEmpty) {
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b;
  auto result = arrayintersection(a, b);
  EXPECT_TRUE(result.empty());
}

TEST(ArrayIntersectionTest, NoIntersection) {
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {4, 5, 6};
  auto result = arrayintersection(a, b);
  EXPECT_TRUE(result.empty());
}

TEST(ArrayIntersectionTest, FullIntersection) {
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {1, 2, 3};
  auto result = arrayintersection(a, b);
  EXPECT_EQ(result, (std::vector<int>{1, 2, 3}));
}

TEST(ArrayIntersectionTest, PartialIntersection) {
  std::vector<int> a = {1, 2, 3, 4, 5};
  std::vector<int> b = {3, 4, 6, 7};
  auto result = arrayintersection(a, b);
  EXPECT_EQ(result, (std::vector<int>{3, 4}));
}

TEST(ArrayIntersectionTest, DuplicatesInBoth) {
  std::vector<int> a = {1, 2, 2, 3};
  std::vector<int> b = {2, 2, 3, 3};
  auto result = arrayintersection(a, b);
  // Intersection preserves duplicates (2 appears twice, 3 once)
  EXPECT_EQ(result, (std::vector<int>{2, 2, 3}));
}

TEST(ArrayIntersectionTest, DifferentLengths) {
  std::vector<int> a = {1, 2, 3, 4, 5, 6};
  std::vector<int> b = {2, 4, 6};
  auto result = arrayintersection(a, b);
  EXPECT_EQ(result, (std::vector<int>{2, 4, 6}));
}

TEST(PalindromeSentenceTest, SimplePalindromes) {
  EXPECT_TRUE(palindromesentence("aba"));
  EXPECT_TRUE(palindromesentence("abba"));
  EXPECT_TRUE(palindromesentence("Aba"));  // case-insensitive
}

TEST(PalindromeSentenceTest, WithSpacesAndPunctuation) {
  EXPECT_TRUE(palindromesentence("A man, a plan, a canal, Panama"));
  EXPECT_TRUE(palindromesentence("No 'x' in Nixon"));
}

TEST(PalindromeSentenceTest, NotPalindromes) {
  EXPECT_FALSE(palindromesentence("hello"));
  EXPECT_FALSE(palindromesentence("abcd"));
}

TEST(PalindromeSentenceTest, EdgeCases) {
  EXPECT_FALSE(palindromesentence(""));          // empty
  EXPECT_TRUE(palindromesentence("a"));          // single char
  EXPECT_TRUE(palindromesentence("Bob wondered, 'Now, Bob?'"));          // single char
  EXPECT_TRUE(palindromesentence("A!"));         // single alpha char with symbol
}

TEST(ReverseCaseMatchTest, EmptyString) {
  EXPECT_TRUE(reversecasematch(""));
}

TEST(ReverseCaseMatchTest, SingleCharacter) {
  EXPECT_TRUE(reversecasematch("a"));
  EXPECT_TRUE(reversecasematch("A"));
}

TEST(ReverseCaseMatchTest, SimplePairs) {
  EXPECT_TRUE(reversecasematch("aA"));
  EXPECT_TRUE(reversecasematch("Zz"));
}

TEST(ReverseCaseMatchTest, LongerMatches) {
  EXPECT_TRUE(reversecasematch("haDrRAHd"));  // matches by reverse case
  EXPECT_TRUE(reversecasematch("AbCdDcBa"));  // alternating pattern
}

TEST(ReverseCaseMatchTest, Mismatches) {
  EXPECT_FALSE(reversecasematch("Hello"));
  EXPECT_FALSE(reversecasematch("ABCdef"));   // case mismatch
}

TEST(ReverseCaseMatchTest, MixedCaseEdge) {
  EXPECT_TRUE(reversecasematch("AaBbBbAa"));
  EXPECT_FALSE(reversecasematch("AaBbCcDd"));
}

TEST(MergeSortedArraysTest, BothEmpty) {
  std::vector<int> a = {};
  std::vector<int> b = {};
  EXPECT_TRUE(mergesortedarrays(a, b).empty());
}

TEST(MergeSortedArraysTest, FirstEmpty) {
  std::vector<int> a = {};
  std::vector<int> b = {1, 2, 3};
  EXPECT_EQ(mergesortedarrays(a, b), (std::vector<int>{1, 2, 3}));
}

TEST(MergeSortedArraysTest, SecondEmpty) {
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {};
  EXPECT_EQ(mergesortedarrays(a, b), (std::vector<int>{1, 2, 3}));
}

TEST(MergeSortedArraysTest, SimpleMerge) {
  std::vector<int> a = {1, 3, 5};
  std::vector<int> b = {2, 4, 6};
  EXPECT_EQ(mergesortedarrays(a, b), (std::vector<int>{1, 2, 3, 4, 5, 6}));
}

TEST(MergeSortedArraysTest, InterleavedMerge) {
  std::vector<int> a = {1, 4, 7};
  std::vector<int> b = {2, 3, 8};
  EXPECT_EQ(mergesortedarrays(a, b), (std::vector<int>{1, 2, 3, 4, 7, 8}));
}

TEST(MergeSortedArraysTest, WithDuplicates) {
  std::vector<int> a = {1, 2, 2, 5};
  std::vector<int> b = {2, 2, 3};
  EXPECT_EQ(mergesortedarrays(a, b), (std::vector<int>{1, 2, 2, 2, 2, 3, 5}));
}

TEST(MergeSortedArraysTest, NegativeNumbers) {
  std::vector<int> a = {-5, -3, -1};
  std::vector<int> b = {-4, -2, 0};
  EXPECT_EQ(mergesortedarrays(a, b), (std::vector<int>{-5, -4, -3, -2, -1, 0}));
}

TEST(MergeSortedArraysTest, UnevenSizes) {
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b = {10, 20};
  EXPECT_EQ(mergesortedarrays(a, b), (std::vector<int>{1, 2, 3, 10, 20}));
}

TEST(HasTwoSumZeroTest, BasicCase) {
  std::vector<int> arr = {-5, -2, -1, 1, 1, 10};
  EXPECT_TRUE(twosum(arr));  // -1 + 1 = 0
}

TEST(HasTwoSumZeroTest, NoPairs) {
  std::vector<int> arr = {-5, -3, 2, 4};
  EXPECT_FALSE(twosum(arr)); // no pair sums to 0
}

TEST(HasTwoSumZeroTest, MultiplePairs) {
  std::vector<int> arr = {-10, -5, -2, 0, 2, 5, 10};
  EXPECT_TRUE(twosum(arr));  // many pairs, e.g., -5 + 5
}

TEST(HasTwoSumZeroTest, AllNegatives) {
  std::vector<int> arr = {-10, -5, -1};
  EXPECT_FALSE(twosum(arr));
}

TEST(HasTwoSumZeroTest, AllPositives) {
  std::vector<int> arr = {1, 2, 5, 10};
  EXPECT_FALSE(twosum(arr));
}

TEST(HasTwoSumZeroTest, OnlyZeros) {
  std::vector<int> arr = {0, 0, 0};
  EXPECT_TRUE(twosum(arr));  // 0 + 0 = 0
}

TEST(HasTwoSumZeroTest, SingleElement) {
  std::vector<int> arr = {0};
  EXPECT_FALSE(twosum(arr)); // no pair exists
}

TEST(HasTwoSumZeroTest, EmptyArray) {
  std::vector<int> arr = {};
  EXPECT_FALSE(twosum(arr)); // no elements at all
}

TEST(MergeThreeSortedArraysTest, HandlesAllEmpty) {
  std::vector<int> a, b, c;
  EXPECT_TRUE(merge3sortedarrays(a, b, c).empty());
}

TEST(MergeThreeSortedArraysTest, HandlesOneEmpty) {
  std::vector<int> a = {1, 3, 5};
  std::vector<int> b;
  std::vector<int> c = {2, 4, 6};
  EXPECT_EQ(merge3sortedarrays(a, b, c), (std::vector<int>{1, 2, 3, 4, 5, 6}));
}

TEST(MergeThreeSortedArraysTest, HandlesNoDuplicates) {
  std::vector<int> a = {1, 4, 7};
  std::vector<int> b = {2, 5, 8};
  std::vector<int> c = {3, 6, 9};
  EXPECT_EQ(merge3sortedarrays(a, b, c), (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

TEST(MergeThreeSortedArraysTest, HandlesWithDuplicatesAcrossArrays) {
  std::vector<int> a = {1, 2, 5};
  std::vector<int> b = {2, 3, 6};
  std::vector<int> c = {2, 4, 7};
  EXPECT_EQ(merge3sortedarrays(a, b, c), (std::vector<int>{1, 2, 3, 4, 5, 6, 7}));
}

TEST(MergeThreeSortedArraysTest, HandlesAllSameElements) {
  std::vector<int> a = {1, 1, 1};
  std::vector<int> b = {1, 1};
  std::vector<int> c = {1};
  EXPECT_EQ(merge3sortedarrays(a, b, c), (std::vector<int>{1}));
}

TEST(MergeThreeSortedArraysTest, HandlesNegativeNumbers) {
  std::vector<int> a = {-5, -3, -1};
  std::vector<int> b = {-4, -2, 0};
  std::vector<int> c = {1, 2, 3};
  EXPECT_EQ(merge3sortedarrays(a, b, c),
            (std::vector<int>{-5, -4, -3, -2, -1, 0, 1, 2, 3}));
}

TEST(MergeThreeSortedArraysTest, HandlesMixedSizes) {
  std::vector<int> a = {1};
  std::vector<int> b = {2, 3};
  std::vector<int> c = {4, 5, 6, 7};
  EXPECT_EQ(merge3sortedarrays(a, b, c), (std::vector<int>{1, 2, 3, 4, 5, 6, 7}));
}
