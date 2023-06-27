#ifndef WEAPONLIST_H
#define WEAPONLIST_H
#include <iostream>
#include <iomanip>
#include <limits>
// -------------------------
// Define the ListNode class
// -------------------------
using namespace std;
class WeaponList {
private:
	struct Node{
		string name;
		int index;
		int gem;
		int attack;
		Node* next;
	};
	Node* headWeapon;
	int number=0;

public:
    // Constructor
    WeaponList() {
        headWeapon = nullptr;
    }

    // Destructor
    ~WeaponList();

    // Linked list operations
    // Append the detail of the player
	void appendWeapon(string, int, int, int);
	void displayWeapon();
	void deleteWeapon(int, int&, int&);
	void updateIndex(int, int);
    void WeaponMenu(int &, int &);
	bool isEmpty();
	int getInput(int, int);
};

#endif
