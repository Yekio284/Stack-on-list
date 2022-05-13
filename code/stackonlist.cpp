#include <iostream>
#include "stackonlist.h"

StackOnList::StackOnList() {
    top = NULL;
}

void StackOnList::push(int val) {
    Node *p = new Node;

    p->value = val;
    p->next = top;

    top = p;
    std::cout << "Added new element to stack with value: " << val << std::endl;
}

void StackOnList::pop() {
    if (!top)
        std::cout << "Stack is empty. Nothing to delete." << std::endl;
    else {
        std::cout << "Deleted top element with value: " << top->value << std::endl;

        Node *p = top;
        top = top->next;

        delete p;
    }
}

void StackOnList::clear_stack() {
    if (!top)
        std::cout << "Stack is empty. Nothing to delete." << std::endl;
    else {
        Node *p = top;
        Node *p1;

        while (p) {
            p1 = p;
            p = p->next;
            delete p1;
        }

        top = NULL;
        std::cout << "Cleared the stack." << std::endl;
    }
}

void StackOnList::print_stack() {
    if (!top)
        std::cout << "Stack is empty." << std::endl;
    else {
        std::cout << "Stack: ";
        Node *p = top;

	    while (p) {
            std::cout << p->value << " ";
            p = p->next;
        }

        std::cout << std::endl;
    }
}

void StackOnList::is_empty() {
    if (!top)
        std::cout << "Stack is empty." << std::endl;
    else
        std::cout << "Stack is not empty." << std::endl;
}

void StackOnList::sort() {
    if (!top)
        std::cout << "Stack is empty. Nothing to sort." << std::endl;
    else {
        for (int i = 0; i < StackOnList::num_of_elements() - 1; i++) {
            Node *p = top;
            for (int j = 0; j < StackOnList::num_of_elements() - i - 1; j++) {
                if (p->value > p->next->value) {
                    int t = p->value;
                    p->value = p->next->value;
                    p->next->value = t;
                }
                p = p->next;
            }
        }
        std::cout << "Sorted the stack." << std::endl;
    }
}

int StackOnList::num_of_elements() {
    if (!top) 
        return 0;
    else {
        int elements = 0;
        Node *p = top;

        while (p) {
            elements++;
            p = p->next;
        }

        return elements;
    }
}

int StackOnList::find_element(int val) {
    Node *p = top;
    bool check = false;

    for (int i = 0; i < StackOnList::num_of_elements(); i++) {
        if (p->value == val)
            return (StackOnList::num_of_elements() - i - 1);
        else
            p = p->next;
    }

    if (!check)
        return -1;
}

int StackOnList::get_top() {
    if (!top)
        std::cout << "Stack is empty." << std::endl;
    else
        return top->value;
}

int StackOnList::get_down() {
    if(!top)
        std::cout << "Stack is empty." << std::endl;
    else {
        Node *p = top;

        for (int i = 0; i < StackOnList::num_of_elements() - 1; i++)
            p = p->next;

        return p->value;
    }
}

int StackOnList::max() {
    if(!top)
        std::cout << "Stack is empty." << std::endl;
    else {
        Node *p = top;
        int max = p->value;

        for (int i = 0; i < StackOnList::num_of_elements(); i++) {
            if (p->value > max) {
                max = p->value;
                p = p->next;
            }
            else
                p = p->next;
        }

        return max;
    }
}

int StackOnList::min() {
    if(!top)
        std::cout << "Stack is empty." << std::endl;
    else {
        Node *p = top;
        int min = p->value;

        for (int i = 0; i < StackOnList::num_of_elements(); i++) {
            if (p->value < min) {
                min = p->value;
                p = p->next;
            }
            else
                p = p->next;
        }

        return min;
    }
}

StackOnList::~StackOnList() {
    StackOnList::clear_stack();
}