#include <iostream>
#include "stackonlist.h"

int main() {
    StackOnList stack;

    stack.push(10);
    stack.push(4);
    stack.push(42);
    stack.push(421);
    stack.push(32);
    std::cout << stack.max() << std::endl;
    std::cout << stack.min() << std::endl;

    std::cout << stack.get_top() << std::endl;
    std::cout << stack.get_down() << std::endl;

    stack.sort();

    std::cout << stack.get_top() << std::endl;
    std::cout << stack.get_down() << std::endl;

    stack.pop();

    std::cout << stack.get_top() << std::endl;

    stack.clear_stack();

    return 0;
}