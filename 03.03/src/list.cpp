#include "list.hpp"

#include <print>
#include <stdexcept>

bool List::empty() const { return head_ == nullptr; }

void List::show() const {
  Node* current = head_;

  while (current != nullptr) {
    std::print("{}", current->value);

    if (current->next != nullptr) {
      std::print(" ");
    }

    current = current->next;
  }

  std::print("\n");
}

void List::push_front(int value) {
  Node* node = new Node{value, head_};

  head_ = node;

  if (tail_ == nullptr) {
    tail_ = node;
  }
}

void List::push_back(int value) {
  Node* node = new Node{value, nullptr};

  if (empty()) {
    head_ = node;
  } else {
    tail_->next = node;
  }

  tail_ = node;
}

void List::pop_front() {
  if (empty()) {
    return;
  }

  Node* temp = head_;

  head_ = head_->next;

  delete temp;

  if (head_ == nullptr) {
    tail_ = nullptr;
  }
}

void List::pop_back() {
  if (empty()) {
    return;
  }

  if (head_ == tail_) {
    delete head_;

    head_ = nullptr;
    tail_ = nullptr;

    return;
  }

  Node* current = head_;

  while (current->next != tail_) {
    current = current->next;
  }

  delete tail_;

  tail_ = current;
  tail_->next = nullptr;
}

int& List::get() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }

  Node* slow = head_;
  Node* fast = head_;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->value;
}

const int& List::get() const {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }

  Node* slow = head_;
  Node* fast = head_;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->value;
}

List::~List() {
  while (!empty()) {
    pop_front();
  }
}