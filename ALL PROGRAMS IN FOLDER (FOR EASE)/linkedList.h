#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

class LinkedList {
private:

	struct ListNode{
    	string story;  
    	string decision1;  
    	string decision2;  
    	string decision3;  
		ListNode *next;	
	};     
	ListNode *head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList();

    // Linked list operations

    // Append a node at the end of the linked list
    void appendNode(string, string, string, string);

    // Display the contents of the linked list
    void displayList(int) const;

    void clear();
};

#endif

