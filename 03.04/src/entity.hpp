#pragma once

#include <print>

class Tester_v1;
class Tester_v2;
class Attorney;

class Entity
{
    friend class Attorney;

private:
    static void test_v1()
    {
        int x = 5;
        std::print("test 1: here's value {}\n", x);
    }

    static void test_v2()
    {
        int y = 10;
        std::print("test 2: here's value {}\n", y);
    }
};

class Attorney
{
public:
    class V1
    {
        friend class Tester_v1;

    private:
        static void test()
        {
            Entity::test_v1();
        }
    };

    class V2
    {
        friend class Tester_v2;

    private:
        static void test()
        {
            Entity::test_v2();
        }
    };
};

class Tester_v1
{
public:
    static void test()
    {
        for (std::size_t index = 0; index < 10; ++index)
        {
            Attorney::V1::test();
        }
    }
};

class Tester_v2
{
public:
    static void test()
    {
        Attorney::V2::test();
    }
};