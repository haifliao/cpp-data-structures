#pragma once

#include "node.hpp"

class LinkedList
{
public:
    LinkedList() = default;
    ~LinkedList();
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    void push_back(int value);
    bool insert_before(int value, int new_value);
    bool insert_after(int value, int new_value);
    void print() const;

private:
    Node* head = nullptr;
};
