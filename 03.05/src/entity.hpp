#pragma once

#include <print>

class Entity_v1
{
    virtual void test()
    {
        std::print("test 1 : \n");
        test_v1();
    }

public:
    virtual void test_v1() = 0;
};

class Entity_v2
{
    virtual void test()
    {
        std::print("test 2 : \n");
        test_v2();
    }

public:
    virtual void test_v2() = 0;
};

class Adapter_v1 : public Entity_v1
{
public:
    virtual void test_v1() override
    {
    }
};

class Adapter_v2 : public Entity_v2
{
public:
    virtual void test_v2() override
    {
    }
};

class Client : public Adapter_v1, public Adapter_v2
{
public:
    virtual void test_v1() final
    {
        std::print("test 1 in cli\n");
    }

    virtual void test_v2() final
    {
        std::print("test 2 in cli\n");
    }
};
