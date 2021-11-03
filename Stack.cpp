//
// Created by gmook on 2/6/2021.
//

#include "Stack.hpp"

void Stack::push(int n) {
    stack.push_back(n);
}
int Stack::top() {
    return stack.at(stack.size()-1);
}
void Stack::pop() {
    stack.pop_back();
}
bool Stack::empty() {
    return stack.empty();
}
