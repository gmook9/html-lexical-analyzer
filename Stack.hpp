//
// Created by gmook on 2/6/2021.
//

#ifndef PROJECT1PHASE1_STACK_HPP
#define PROJECT1PHASE1_STACK_HPP


#include <vector>

class Stack {
public:

    void push(int n);
    int top();
    void pop();
    bool empty();

private:
    std::vector<int> stack;

};



#endif //PROJECT1PHASE1_STACK_HPP
