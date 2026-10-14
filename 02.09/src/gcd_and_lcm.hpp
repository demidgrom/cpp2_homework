#pragma once

#include <memory>
#include <print>
#include <stdexcept>
#include <utility>

template <typename T, typename Alloc = std::allocator<T>>
class List
{
public:
    ~List();

    bool empty() const;

    void show() const;

    template <typename U>
    void push_front(U &&value);

    template <typename U>
    void push_back(U &&value);

    void pop_front();

    void pop_back();

    T &get();

    const T &get() const;

private:
    struct Node
    {
        T value;
        Node *next = nullptr;
    };

    Node *start = nullptr;

    Node *end = nullptr;
};

template <typename T, typename Alloc>
List<T, Alloc>::~List()
{
    while (start != nullptr)
        pop_front();
}

template <typename T, typename Alloc>
bool List<T, Alloc>::empty() const
{
    return start == nullptr;
}

template <typename T, typename Alloc>
void List<T, Alloc>::show() const
{
    for (const Node *node = start; node != nullptr; node = node->next)
    {
        std::print("{}", node->value);
        if (node->next != nullptr)
            std::print(" ");
    }
    std::print("\n");
}

template <typename T, typename Alloc>
template <typename U>
void List<T, Alloc>::push_front(U &&value)
{
    Node *node = new Node{std::forward<U>(value), start};
    start = node;

    if (end == nullptr)
    {
        end = node;
    }
}

template <typename T, typename Alloc>
template <typename U>
void List<T, Alloc>::push_back(U &&value)
{
    Node *node = new Node{std::forward<U>(value), nullptr};
    if (end == nullptr)
    {
        start = node;
    }

    else
    {
        end->next = node;
    }

    end = node;
}

template <typename T, typename Alloc>
void List<T, Alloc>::pop_front()
{
    if (empty())
    {
        return;
    }

    Node *old = start;
    start = start->next;
    delete old;

    if (start == nullptr)
    {
        end = nullptr;
    }
}

template <typename T, typename Alloc>
void List<T, Alloc>::pop_back()
{
    if (empty())
    {
        return;
    }

    if (start == end)
    {
        delete start;
        start = end = nullptr;
        return;
    }

    Node *node = start;
    while (node->next != end)
    {
        node = node->next;
    }

    delete end;
    end = node;
    end->next = nullptr;
}

template <typename T, typename Alloc>
T &List<T, Alloc>::get()
{
    return const_cast<T &>(std::as_const(*this).get());
}

template <typename T, typename Alloc>
const T &List<T, Alloc>::get() const
{
    if (empty())
    {
        throw std::out_of_range("List is empty");
    }

    const Node *slow = start;
    const Node *fast = start;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->value;
}