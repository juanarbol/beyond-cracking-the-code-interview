#include <gtest/gtest.h>
#include "dynamic-array.h"

TEST(DynamicArrayTest, StartsEmpty) {
    DynamicArray arr;
    EXPECT_EQ(arr.getSize(), 0);
}

TEST(DynamicArrayTest, AddIncreasesSize) {
    DynamicArray arr;
    arr.add(42);
    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr.get(0), 42);
}

TEST(DynamicArrayTest, AddMultipleAndResize) {
    DynamicArray arr;
    for (int i = 0; i < 10; i++) {
        arr.add(i);
    }
    EXPECT_EQ(arr.getSize(), 10);
    EXPECT_EQ(arr.get(0), 0);
    EXPECT_EQ(arr.get(9), 9);
}

TEST(DynamicArrayTest, RemoveDecreasesSize) {
    DynamicArray arr;
    arr.add(1);
    arr.add(2);
    arr.remove();
    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr.get(0), 1);
}

TEST(DynamicArrayTest, RemoveFromEmptyDoesNothing) {
    DynamicArray arr;
    arr.remove();
    EXPECT_EQ(arr.getSize(), 0);
}

TEST(DynamicArrayTest, GetThrowsOnInvalidIndex) {
    DynamicArray arr;
    arr.add(99);
    EXPECT_THROW(arr.get(1), std::out_of_range);
    EXPECT_THROW(arr.get(-1), std::out_of_range);
}
