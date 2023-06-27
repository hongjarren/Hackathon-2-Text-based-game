

#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
private:
    struct StackNode {
        int level;
        int gem;
        int pace;
        StackNode* next;
    };
    StackNode* stackTop;

public:
    Stack();
    ~Stack();

    void push(int, int, int);
    void pop(int &, int &, int &);
    void displayStack() const;
};

#endif

