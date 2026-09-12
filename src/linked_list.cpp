#include "linked_list.hpp"
#include <iostream>
#include <utility>

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        Node* node_to_delete = head;
        head = head->next;
        delete node_to_delete;
    }
}

void LinkedList::push_back(int value)
{
    Node* new_node = new Node{value, nullptr};

    if (head == nullptr)
    {
        head = new_node;
        return;
    }

    Node* current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = new_node;
}

bool LinkedList::insert_before(int value, int new_value)
 {
    Node* previous = nullptr;
    Node* current = head;

    if (head == nullptr)
    {
        return false;
    }

    while (current != nullptr)
    {
        if (current->data == value)
        {
            Node* new_node = new Node{new_value, current};
            if (current == head)
            {
                head = new_node;
            }
            else
            {
                previous->next = new_node;
            }
            return true;
        }
        previous = current;
        current = current->next;
    }

    return false;
 }

 bool LinkedList::insert_after(int value, int new_value)
 {
    Node* current = head;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            Node* new_node = new Node{new_value, current->next};
            current->next = new_node;
            return true;
        }
        current = current->next;
    }

    return false;
 }

 void LinkedList::print() const
 {
    const Node* current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
 }
