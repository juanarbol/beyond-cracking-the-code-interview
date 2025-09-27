#include <gtest/gtest.h>
#include "dynamic-array.h"

TEST(DynamicArrayTest, StartsEmpty) {
  DynamicArray arr;
  EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArrayTest, AddIncreasesSize) {
  DynamicArray arr;
  arr.append(42);
  EXPECT_EQ(arr.size(), 1);
  EXPECT_EQ(arr.get(0), 42);
}

TEST(DynamicArrayTest, AddMultipleAndResize) {
  DynamicArray arr;
  for (int i = 0; i < 10; i++) arr.append(i);
  EXPECT_EQ(arr.size(), 10);
  EXPECT_EQ(arr.get(0), 0);
  EXPECT_EQ(arr.get(9), 9);
  EXPECT_EQ(arr.capacity(), 20);  // Twice the size initialized
}

TEST(DynamicArrayTest, RemoveDecreasesSize) {
  DynamicArray arr;
  arr.append(1);
  arr.append(2);
  arr.pop_back();
  EXPECT_EQ(arr.size(), 1);
  EXPECT_EQ(arr.get(0), 1);
}

TEST(DynamicArrayTest, RemoveFromEmptyDoesNothing) {
  DynamicArray arr;
  arr.pop_back();
  EXPECT_EQ(arr.size(), 0);
}

TEST(DynamicArrayTest, GetThrowsOnInvalidIndex) {
  DynamicArray arr;
  arr.append(99);
  EXPECT_EQ(arr.get(1), -1);
  EXPECT_EQ(arr.get(-1), -1);
}

TEST(DynamicArrayTest, ShouldShrinkToo) {
  DynamicArray arr;
  // Trigger the resize
  for (int i = 0; i < 10; i++) arr.append(i);
  EXPECT_EQ(arr.capacity(), 20);
  // We leave the 25%% we need to trigger shrink
  for (int i = 0; i < arr.size() * 0.75; i++) arr.pop_back();
  EXPECT_EQ(arr.capacity(), 10);
}
