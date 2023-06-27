#ifndef ARMORLIST_H
#define ARMORLIST_H
#include <iostream>
#include <iomanip>
#include <limits>
// -------------------------
// Define the ListNode class
// -------------------------
using namespace std;
class ArmorList {
private:
	struct Node{
		string name;
		int index;
		int gem;
		int armor;
		Node* next;
	};
	Node* headArmor;
	int number=0;

public:
    // Constructor
    ArmorList() {
        headArmor = nullptr;
    }

    // Destructor
    ~ArmorList();

    // Linked list operations
    // Append the detail of the player
	void appendNode(string, int, int, int);
	void displayArmor();
	void deleteArmor(int, int&, int&);
	void updateIndex(int, int);
	bool isEmpty();
	void armorMenu(int&, int&);
	int getInput(int, int);
};
#endif
