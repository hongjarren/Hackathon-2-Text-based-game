#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
// -------------------------
// Define the ListNode class
// -------------------------
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



void LinkedList::appendNode(string copyStory, string copyDecision1, string copyDecision2, string copyDecision3) {
    // Create a new node with the given value
    ListNode *newNode;
	newNode = new ListNode;
	
	newNode->story = copyStory;
	newNode->decision1 = copyDecision1;
	newNode->decision2 = copyDecision2;
	newNode->decision3 = copyDecision3;
	newNode->next= nullptr;
	
    if (head == nullptr) {
        // If the list is empty, make the new node the head
        head = newNode;
    } else {
        // Traverse to the end of the list and add the new node there
        ListNode *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// -----------------
// Display the list
// -----------------
void LinkedList::displayList(int level) const {
    if (head == nullptr) {
        // If the list is empty, display a message
        cout << "List is empty." << endl;
    } else {
        // Traverse the list and display the value of each node
        ListNode *current = head;
        int counter = 1;
        
        while (current != nullptr && counter != level) {
            current = current->next;
            counter++;
        }

		if(level == 10){
			cout << "Boss is coming...." << endl;
			cout << current->story << endl;
		} else {
        	cout << current->story     << endl << endl;
        	cout << current->decision1 << endl << endl;
			cout << current->decision2 << endl << endl;	
			cout << current->decision3 << endl << endl;			
		}    
    }
}

void LinkedList::clear(){
    // Clear the linked list and free memory
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
}

LinkedList::~LinkedList(){
    // Destructor: Clear the linked list and free memory
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
}

#endif
