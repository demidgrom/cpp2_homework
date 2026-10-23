#include <gtest/gtest.h>

#include <stdexcept>

#include "list.hpp"

TEST(ListTest, EmptyAndEmptyPops) {
  List list;

  EXPECT_TRUE(list.empty());

  list.pop_front();
  list.pop_back();

  EXPECT_TRUE(list.empty());

  EXPECT_THROW(list.get(), std::out_of_range);
}

TEST(ListTest, PushFrontAndPopFront) {
  List list;

  list.push_front(3);
  list.push_front(2);
  list.push_front(1);  // 1 2 3

  EXPECT_FALSE(list.empty());
  EXPECT_EQ(list.get(), 2);

  list.pop_front();  // 2 3
  EXPECT_EQ(list.get(), 3);

  list.pop_front();  // 3
  EXPECT_EQ(list.get(), 3);

  list.pop_front();  // empty
  EXPECT_TRUE(list.empty());

  list.push_back(4);
  EXPECT_EQ(list.get(), 4);
}

TEST(ListTest, PushBackAndPopBack) {
  List list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);  // 1 2 3

  EXPECT_EQ(list.get(), 2);

  list.pop_back();  // 1 2
  EXPECT_EQ(list.get(), 2);

  list.pop_back();  // 1
  EXPECT_EQ(list.get(), 1);

  list.pop_back();  // empty
  EXPECT_TRUE(list.empty());

  list.push_front(5);
  EXPECT_EQ(list.get(), 5);
}

TEST(ListTest, GetReturnsSecondMiddleForEvenSize) {
  List list;

  for (int n = 1; n <= 4; ++n) {
    list.push_back(n);
  }

  // 1 2 3 4

  EXPECT_EQ(list.get(), 3);

  list.get() = 30;

  const List& read_only = list;

  EXPECT_EQ(read_only.get(), 30);
}

TEST(ListTest, GetReturnsMiddleForOddSize) {
  List list;

  list.push_back(10);
  list.push_back(20);
  list.push_back(30);
  list.push_back(40);
  list.push_back(50);

  // 10 20 30 40 50

  EXPECT_EQ(list.get(), 30);

  list.pop_front();  // 20 30 40 50

  EXPECT_EQ(list.get(), 40);
}

TEST(ListTest, ShowOutputsAllValues) {
  List list;

  list.push_front(2);
  list.push_front(1);
  list.push_back(3);

  testing::internal::CaptureStdout();

  list.show();

  EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 2 3\n");
}

TEST(ListTest, ShowEmptyList) {
  List list;

  testing::internal::CaptureStdout();

  list.show();

  EXPECT_EQ(testing::internal::GetCapturedStdout(), "\n");
}

TEST(ListTest, SingleElement) {
  List list;

  list.push_front(10);

  EXPECT_FALSE(list.empty());
  EXPECT_EQ(list.get(), 10);

  list.pop_back();

  EXPECT_TRUE(list.empty());

  list.push_back(20);

  EXPECT_EQ(list.get(), 20);

  list.pop_front();

  EXPECT_TRUE(list.empty());
}

TEST(ListTest, IntegrationMixedOperations) {
  List list;

  list.push_back(2);
  list.push_front(1);
  list.push_back(3);
  list.push_front(0);

  // 0 1 2 3

  EXPECT_EQ(list.get(), 2);

  list.pop_front();  // 1 2 3

  EXPECT_EQ(list.get(), 2);

  list.pop_back();  // 1 2

  EXPECT_EQ(list.get(), 2);

  list.pop_front();  // 2

  EXPECT_EQ(list.get(), 2);

  list.pop_back();  // empty

  EXPECT_TRUE(list.empty());
}

TEST(ListTest, PushAfterRemovingAllElements) {
  List list;

  list.push_back(1);
  list.push_back(2);

  list.pop_front();
  list.pop_front();

  EXPECT_TRUE(list.empty());

  list.push_front(5);
  list.push_back(10);

  // 5 10

  EXPECT_EQ(list.get(), 10);

  list.pop_back();

  EXPECT_EQ(list.get(), 5);

  list.pop_front();

  EXPECT_TRUE(list.empty());
}