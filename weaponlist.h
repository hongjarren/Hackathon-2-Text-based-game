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

int WeaponList::getInput(int min, int max) {
    int input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter valid input." << endl;
        cout << "Enter number: ";
    }
    return input;
}
void WeaponList::WeaponMenu(int &totalGem, int &totalAttack){
	
	cout << "\t\t\t" << " ________________________________________________"  << endl;
	cout << "\t\t\t" << "|            Weapon             | " << setw(5) << " Attack |" << setw(5) << "  Gem |" << endl;
	cout << "\t\t\t" << "|_______________________________|_________|______|"  << endl;
	cout << "\t\t\t" << "|1. Doomcaster (Staff)          | " << setw(5) << "   469  |" << setw(5) << "  35  |" << endl;
	cout << "\t\t\t" << "|2. Celestial Scepter (Mace)    | " << setw(5) << "   417  |" << setw(5) << "  31  |" << endl;
	cout << "\t\t\t" << "|3. Shadowstrike (Dagger)       | " << setw(5) << "   408  |" << setw(5) << "  30  |" << endl;
	cout << "\t\t\t" << "|4. Frostfang (Warhammer)       | " << setw(5) << "   342  |" << setw(5) << "  24  |" << endl;
	cout << "\t\t\t" << "|5. Moonshadow (Shortsword)     | " << setw(5) << "   294  |" << setw(5) << "  19  |" << endl;					
	cout << "\t\t\t" << "|6. Stormbreaker (Greatsword)   | " << setw(5) << "   289  |" << setw(5) << "  18  |" << endl;
	cout << "\t\t\t" << "|7. Serpent's Embrace (Whip)    | " << setw(5) << "   211  |" << setw(5) << "  15  |" << endl;	
	cout << "\t\t\t" << "|8. Whisperwind (Longbow)       | " << setw(5) << "   183  |" << setw(5) << "  10  |" << endl;
	cout << "\t\t\t" << "|9. Soulfire (Flaming Scimitar) | " << setw(5) << "   176  |" << setw(5) << "  09  |" << endl;	
	cout << "\t\t\t" << "|10.Thunderclap (Hand Crossbow) | " << setw(5) << "   138  |" << setw(5) << "  06  |" << endl;
	cout << "\t\t\t" << "|0. Exit the menu               |         |      |"  << endl;
	cout << "\t\t\t" << "|_______________________________|_________|______|"  << endl;
	
	cout << endl << endl;

	
	int enterWeapon, choice, selection, tempGem, tempAtt;
    int indexItem = 1;
    int returnGem, returnAttack;
    bool status;
    string name;

    cout << "Please enter the weapon that you would like to purchase:" << endl;
	bool weapon = true;
    do {
		if(weapon){
        cout << "Select a weapon: ";
       	enterWeapon = getInput(0,10);
		}


        switch (enterWeapon) {
        case 1:
            totalAttack += 469;
            totalGem -= 35;
            tempAtt = 469;
            tempGem = 35;
            name = "Doomcaster";
            break;
        case 2:
            totalAttack += 417;
            totalGem -= 31;
            tempAtt = 417;
            tempGem = 31;
            name = "Celestial Scepter";
            break;
        case 3:
            totalAttack += 408;
            totalGem -= 30;
            tempAtt = 408;
            tempGem = 30;
            name = "Shadowstrike";
            break;
        case 4:
            totalAttack += 342;
            totalGem -= 24;
            tempAtt = 342;
            tempGem = 24;
            name = "Frostfang";
            break;
        case 5:
            totalAttack += 294;
            totalGem -= 19;
            tempAtt = 294;
            tempGem = 19;
            name = "Moonshadow";
            break;
        case 6:
            totalAttack += 289;
            totalGem -= 18;
            tempAtt = 289;
            tempGem = 18;
            name = "Stormbreaker";
            break;
        case 7:
            totalAttack += 211;
            totalGem -= 15;
            tempAtt = 211;
            tempGem = 15;
            name = "Serpent's Embrace";
            break;
        case 8:
            totalAttack += 183;
            totalGem -= 10;
            tempAtt = 183;
            tempGem = 10;
            name = "Whisperwind";
            break;
        case 9:
            totalAttack += 176;
            totalGem -= 9;
            tempAtt = 176;
            tempGem = 9;
            name = "Soulfire";
            break;
        case 10:
            totalAttack += 138;
            totalGem -= 6;
            tempAtt = 138;
            tempGem = 6;
            name = "Thunderclap";
            break;
        default:
            cout << "Please select your weapon based on the index listed in the table" << endl;
            continue;  // Skip adding the invalid weapon to the linked list
        }
        if(weapon == true){
            if (totalGem < 0) {
                totalAttack -= tempAtt;
                totalGem += tempGem;
                cout << "Oh no! The gems that you have collected are not enough." << endl;
            } else {
                appendWeapon(name, indexItem, tempGem, tempAtt);
                indexItem++;
                cout << "Current Attack: " << totalAttack << endl;
                cout << "Total Gems Left: " << totalGem << endl;
                cout << endl;
            }

            do{
            	    cout << "Do you still want to continue?" << endl;
        			cout << "(1: Yes, 2: Sell Weapons, 3: Show Bought Weapons, 0: Buy Armor): ";
        			choice = getInput(0,3);
        			if (choice > 3) {
					    cout << "Please enter valid input.";
					    choice = getInput(0,3);
					}

			}while(choice > 3);

        }

	


        if (choice == 2) {
			//weapon = false;
			if(isEmpty()){
                cout << "You haven buy anything yet...." << endl;
                weapon = true;
			}
			else{
				  do {
						
						if(!isEmpty()){
							displayWeapon();
		                	cout << "The list above shows the weapons you have just purchased." << endl;
		                	cout << "Select the item you want to sell: ";
		                	selection = getInput(1,indexItem);
		                	
			                	deleteWeapon(selection, returnGem, returnAttack);
			                	indexItem--;
			                	totalGem += returnGem;
			                	totalAttack -= returnAttack;
			                	
								// Update the index of remaining weapons
		                		for (int i = selection; i <= indexItem; i++) {
		                    		updateIndex(i, i - 1);
		                		}
		        
		                			cout << "Do you want to sell another weapon? (1: Yes, 0: No): ";
		                			status = getInput(0,1);
							
						}
						else{
							cout << "You have sell all the weapon that you have bought." << endl;
							
							status = 0;
						}
	
            	} while (status != 0);
            		do{
            	    	cout << "Do you still want to continue?" << endl;
        				cout << "(1: Yes,  0: Buy Armor): ";
        				choice = getInput(0,1);
						weapon = true;
        		
        				//The loop cannot be gone through
					    if (choice > 1 ) {
					        cout << "Please enter valid input.";
					        cin >> choice;
						}
					}while(choice > 1);
			}
      
        }else if (choice == 3) {
            displayWeapon();
			    do{
            	    cout << "Do you still want to continue?" << endl;
        			cout << "(1: Yes, 2: Sell Weapons, 3: Show Bought Weapons, 0: Buy Armor): ";
        			choice = getInput(0,3);
        			if (choice > 3) {
					    cout << "Please enter valid input.";
					    choice = getInput(0,3);
					}
                    while(choice == 3){
                        displayWeapon();
                        cout << "Do you still want to continue?" << endl;
        			    cout << "(1: Yes, 2: Sell Weapons, 3: Show Bought Weapons, 0: Buy Armor): ";
        			   choice = getInput(0,3);
                    }
        			if(choice == 1) 
						weapon = true;

        			else 
						weapon = false;	

				}while(choice > 3);

        }
    } while (choice != 0);
}
bool WeaponList::isEmpty(){

	if(number > 0){
		return false;
	}
	else return true;
}
void WeaponList::updateIndex(int oldIndex, int newIndex) {
    Node* pointer = headWeapon;
    while (pointer != nullptr) {
        if (pointer->index == oldIndex) {
            pointer->index = newIndex;
        }
        pointer = pointer->next;
		}
} 

void WeaponList::deleteWeapon(int index, int &gem, int &attack){
	Node* pointer;
	pointer = headWeapon;
	
    Node* previous = nullptr;
    
	if (headWeapon == nullptr) {
       return;
    }
	else{
		pointer = headWeapon;
		// Search for the node with the given data
    	while (pointer  != nullptr && pointer ->index != index) {
        	previous = pointer;
        	pointer = pointer->next;
    	}
    	if (pointer == nullptr){
			cout << "Nothing in the list" << endl;
			return;
		} 
    	if (previous == nullptr) {
        	// Node to delete is the head
			gem = pointer->gem;
			attack = pointer->attack;

        	pointer = pointer->next;
        	delete headWeapon;
        	headWeapon = pointer;
        	number--;
    	} 
		else {
        	// Node to delete is not the head
			gem = pointer->gem;
			attack = pointer->attack;

        	previous->next = pointer->next;
        	delete pointer;
  		}
	}
}




void WeaponList::displayWeapon(){
		Node *pointer;
	    if (headWeapon == nullptr) {
        	// If the list is empty, display a message
        	cout << "The list is empty." << endl;
        	
    	} 
		else {
        	// Traverse the list and display the value of each node
        	pointer = headWeapon;

    		while (pointer != nullptr) {
        		// Print the folloewing pointed value
				cout << "Weapon #" << pointer->index << endl;
				cout << "Name of the weapon  :" << pointer->name << endl;
    			cout << "Cost of the weapon  : " << pointer->gem << endl;
    			cout << "Attack of the weapon: " << pointer->attack << endl;
    			pointer = pointer->next;
    		}
            
    	}
}

void WeaponList::appendWeapon(string name, int index, int gem, int attack){
	// new node is created to point the new value at the top of the stack
	number++;
    Node* newNode, * pointer;
    newNode = new Node;
    newNode->name = name;
    newNode->index = index;
    newNode->gem = gem;
    newNode->attack = attack;
    newNode->next = nullptr;
    
    if (headWeapon == nullptr) {
        // If the list is empty, make the new node the head
    	headWeapon = newNode;
    } else {
        // Traverse to the last node

		pointer = headWeapon;
        while (pointer->next != nullptr) {
            pointer = pointer->next;
        }

        // Append the new node to the last node
        pointer->next = newNode;

    }
}

WeaponList::~WeaponList() {
    // Destructor: Clear the linked list and free memory
    Node *current = headWeapon;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}
#endif
