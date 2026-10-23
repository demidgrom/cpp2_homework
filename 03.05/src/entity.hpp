#pragma once

#include <print>

class Entity_v1 {
 public:
  virtual void test() { std::print("test 1: "); }
};

class Entity_v2 {
 public:
  virtual void test() { std::print("test 2: "); }
};

class Adapter_v1 : public Entity_v1 {
 public:
  void test() final {
    Entity_v1::test();
    test_v1();
  }

  virtual void test_v1() = 0;
};

class Adapter_v2 : public Entity_v2 {
 public:
  void test() final {
    Entity_v2::test();
    test_v2();
  }

  virtual void test_v2() = 0;
};

class Client : public Adapter_v1, public Adapter_v2 {
 public:
  void test_v1() final { std::print("test 1 in client\n"); }

  void test_v2() final { std::print("test 2 in client\n"); }
};