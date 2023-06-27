#include "stack.h"
#include <iostream>

using namespace std;
void Stack::push(int copyLevel, int copyGem, int copyPace) {
    StackNode* newNode = new StackNode;
    newNode->level = copyLevel;
    newNode->gem = copyGem;
    newNode->pace = copyPace;
    newNode->next = nullptr;

    if (stackTop == nullptr) {
        stackTop = newNode;
    }
    else {
        newNode->next = stackTop;
        stackTop = newNode;
    }
}

void Stack::displayStack() const {
    if (stackTop == nullptr) {
        cout << "No saved file found." << endl;
        return;
    }
    
    StackNode* nodePtr = stackTop;
    while (nodePtr != nullptr) {
        cout << "Phase" << nodePtr->level << " [Gem: " << nodePtr->gem << "] [Pace: " << nodePtr->pace << "]" << endl;
        cout << endl;
        nodePtr = nodePtr->next;
    }
}

void Stack::pop(int &curlevel, int &curGem, int &curPace) {
    if (stackTop == nullptr) {
        cout << "The stack is empty." << endl;
        return;
    }

    curlevel = stackTop->level;
    curGem = stackTop->gem;
    curPace = stackTop->pace;

    StackNode* temp = stackTop;
    stackTop = stackTop->next;
    delete temp;
}

Stack::~Stack() {
    StackNode* nodePtr = stackTop;

    while (nodePtr != nullptr) {
        StackNode* temp = nodePtr;
        nodePtr = nodePtr->next;
        delete temp;
    }
}
Stack::Stack() {
	stackTop = nullptr;
}

