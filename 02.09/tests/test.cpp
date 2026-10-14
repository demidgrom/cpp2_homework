#include "gcd_and_lcm.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <stdexcept>
#include <string>

TEST(ListTest, EmptyAndEmptyPops)
{
    List<int> list;
    EXPECT_TRUE(list.empty());

    list.pop_front();
    list.pop_back();
    EXPECT_TRUE(list.empty());
    EXPECT_THROW(list.get(), std::out_of_range);
}

TEST(ListTest, PushFrontAndPopFront)
{
    List<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1); // 1 2 3

    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.get(), 2);

    list.pop_front(); // 2 3
    EXPECT_EQ(list.get(), 3);
    list.pop_front(); // 3
    EXPECT_EQ(list.get(), 3);
    list.pop_front(); // empty
    EXPECT_TRUE(list.empty());

    list.push_back(4); // checking the tail pointer after removal
    EXPECT_EQ(list.get(), 4);
}

TEST(ListTest, PushBackAndPopBack)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3); // 1 2 3

    EXPECT_EQ(list.get(), 2);
    list.pop_back(); // 1 2
    EXPECT_EQ(list.get(), 2);
    list.pop_back(); // 1
    EXPECT_EQ(list.get(), 1);
    list.pop_back(); // empty
    EXPECT_TRUE(list.empty());

    list.push_front(5);
    EXPECT_EQ(list.get(), 5);
}

TEST(ListTest, GetReturnsSecondMiddleForEvenSize)
{
    List<int> list;
    for (int n = 1; n <= 4; ++n)
        list.push_back(n);

    EXPECT_EQ(list.get(), 3);
    list.get() = 30;
    const List<int> &read_only = list;
    EXPECT_EQ(read_only.get(), 30);
}

TEST(ListTest, ShowOutputsAllValues)
{
    List<int> list;
    list.push_front(2);
    list.push_front(1);
    list.push_back(3);

    testing::internal::CaptureStdout();
    list.show();
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1 2 3\n");
}

TEST(ListTest, ShowEmptyList)
{
    List<int> list;
    testing::internal::CaptureStdout();
    list.show();
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "\n");
}

TEST(ListTest, PerfectForwardingSupportsMoveOnlyValues)
{
    List<std::unique_ptr<int>> list;
    list.push_front(std::make_unique<int>(10));
    list.push_back(std::make_unique<int>(20));

    EXPECT_EQ(*list.get(), 20);
    list.pop_front();
    EXPECT_EQ(*list.get(), 20);
}

TEST(ListTest, DestructorDestroysAllNodes)
{
    auto value = std::make_shared<int>(42);
    {
        List<std::shared_ptr<int>> list;
        list.push_front(value);
        list.push_back(value);
        EXPECT_EQ(value.use_count(), 3);
    }
    EXPECT_EQ(value.use_count(), 1);
}

TEST(ListTest, IntegrationMixedOperations)
{
    List<std::string> list;
    list.push_back("two");
    list.push_front("one");
    list.push_back("three");
    list.push_front("zero"); // zero one two three

    EXPECT_EQ(list.get(), "two");
    list.pop_front(); // one two three
    EXPECT_EQ(list.get(), "two");
    list.pop_back(); // one two
    EXPECT_EQ(list.get(), "two");
    list.pop_front(); // two
    EXPECT_EQ(list.get(), "two");
    list.pop_back(); // empty
    EXPECT_TRUE(list.empty());
}