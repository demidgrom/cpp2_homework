#include <gtest/gtest.h>

#include <algorithm>
#include <random>
#include <vector>

#include "sort.hpp"

TEST(QuickSortTest, EmptyVector) {
  std::vector<int> vector;

  sort(vector);

  EXPECT_TRUE(vector.empty());
}

TEST(QuickSortTest, OneElement) {
  std::vector<int> vector{42};

  sort(vector);

  EXPECT_EQ(vector, std::vector<int>{42});
}

TEST(QuickSortTest, ReverseSorted) {
  std::vector<int> vector{5, 4, 3, 2, 1};

  sort(vector);

  EXPECT_EQ(vector, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(QuickSortTest, AlreadySorted) {
  std::vector<int> vector{1, 2, 3, 4, 5};

  sort(vector);

  EXPECT_EQ(vector, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(QuickSortTest, Duplicates) {
  std::vector<int> vector{5, 2, 5, 1, 2, 5, 3};

  sort(vector);

  EXPECT_EQ(vector, std::vector<int>({1, 2, 2, 3, 5, 5, 5}));
}

TEST(QuickSortTest, RandomVectors) {
  std::mt19937 generator(42);
  std::uniform_int_distribution<int> distribution(-1000, 1000);

  for (int test = 0; test < 100; ++test) {
    std::vector<int> actual;

    for (int i = 0; i < 100; ++i) {
      actual.push_back(distribution(generator));
    }

    auto expected = actual;

    std::ranges::sort(expected);

    sort(actual);

    EXPECT_EQ(actual, expected);
  }
}