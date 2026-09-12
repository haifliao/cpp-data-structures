#include "linked_list.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <type_traits>

static_assert(!std::is_copy_constructible_v<LinkedList>);
static_assert(!std::is_copy_assignable_v<LinkedList>);

int main()
{
    // Insert a value before a node in the middle of the list.
    LinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    const bool inserted = list.insert_before(20, 15);
    assert(inserted);

    std::ostringstream output;
    std::streambuf* original_buffer = std::cout.rdbuf(output.rdbuf());
    list.print();
    std::cout.rdbuf(original_buffer);

    assert(output.str() == "10 15 20 30 \n");

    // Return false and keep the list unchanged when the target is missing.
    LinkedList unchanged_list;
    unchanged_list.push_back(10);
    unchanged_list.push_back(20);
    unchanged_list.push_back(30);

    const bool missing_value_inserted = unchanged_list.insert_before(99, 15);
    assert(!missing_value_inserted);

    std::ostringstream unchanged_output;
    original_buffer = std::cout.rdbuf(unchanged_output.rdbuf());
    unchanged_list.print();
    std::cout.rdbuf(original_buffer);

    assert(unchanged_output.str() == "10 20 30 \n");

    // Insert a value before the head node.
    LinkedList head_list;
    head_list.push_back(10);
    head_list.push_back(20);
    head_list.push_back(30);

    const bool head_inserted = head_list.insert_before(10, 5);
    assert(head_inserted);

    std::ostringstream head_output;
    original_buffer = std::cout.rdbuf(head_output.rdbuf());
    head_list.print();
    std::cout.rdbuf(original_buffer);

    assert(head_output.str() == "5 10 20 30 \n");

    // Return false and keep an empty list unchanged.
    LinkedList empty_list;

    const bool empty_list_inserted = empty_list.insert_before(10, 5);
    assert(!empty_list_inserted);

    std::ostringstream empty_output;
    original_buffer = std::cout.rdbuf(empty_output.rdbuf());
    empty_list.print();
    std::cout.rdbuf(original_buffer);

    assert(empty_output.str() == "\n");

    // Insert a value after a node in the middle of the list.
    LinkedList after_list;
    after_list.push_back(10);
    after_list.push_back(20);
    after_list.push_back(30);

    const bool after_inserted = after_list.insert_after(20, 25);
    assert(after_inserted);

    std::ostringstream after_output;
    original_buffer = std::cout.rdbuf(after_output.rdbuf());
    after_list.print();
    std::cout.rdbuf(original_buffer);

    assert(after_output.str() == "10 20 25 30 \n");
}
