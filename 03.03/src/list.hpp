#pragma once

class List {
 private:
  struct Node {
    int value;
    Node* next;
  };

  Node* head_ = nullptr;
  Node* tail_ = nullptr;

 public:
  bool empty() const;
  void show() const;

  void push_front(int value);
  void push_back(int value);

  void pop_front();
  void pop_back();

  int& get();
  const int& get() const;

  ~List();
};