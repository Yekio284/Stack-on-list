#pragma once

struct Node {
    int value;
    Node *next;
};

class StackOnList {
private:
    Node *top;
public:
    StackOnList();

    void push(int val); // adding the element to the stack
    void pop(); // deleting "top" element
    void clear_stack(); // clearing the stack
    void print_stack(); // printing the stack
    void is_empty(); // Is our stack empty?
    void sort(); // using bubble sort
    int num_of_elements(); // get the num of elements in the stack
    int find_element(int val); // searching element by his value and returning his index. Indexation starts from the
                               // "downest" element and equals 0. If there is no element with this "val", then return -1.
    int get_top(); // get the top element
    int get_down(); // get the "downest" element
    int max(); // return max element
    int min(); // return min element

    ~StackOnList();
};