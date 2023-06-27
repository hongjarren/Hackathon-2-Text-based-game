#include "armorlist.h"
#include <iostream>

using namespace std;
int ArmorList::getInput(int min, int max) {
    int input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter valid input." << endl;
        cout << "Enter number: ";
    }
    return input;
}
void ArmorList::armorMenu(int &totalGem,int &totalArm){
	cout << "\t\t\t\t" << " _________________________________________"  << endl;
	cout << "\t\t\t\t" << "|         Armor          | " << setw(5) << " Health |" << setw(5) << "  Gem |" << endl;
	cout << "\t\t\t\t" << "|________________________|_________|______|"  << endl;
	cout << "\t\t\t\t" << "|1.  Sentinel's Plate    | " << setw(5) << "   183  |" << setw(5) << "  15  |" << endl;
	cout << "\t\t\t\t" << "|2.  Stormguard Plate    | " << setw(5) << "   174  |" << setw(5) << "  14  |" << endl;
	cout << "\t\t\t\t" << "|3.  Elven Chainmail     | " << setw(5) << "   150  |" << setw(5) << "  13  |" << endl;
	cout << "\t\t\t\t" << "|4.  Feyweave Cloak      | " << setw(5) << "   136  |" << setw(5) << "  11  |" << endl;
	cout << "\t\t\t\t" << "|5.  Dragon Scale Mail   | " << setw(5) << "   121  |" << setw(5) << "  10  |" << endl;
	cout << "\t\t\t\t" << "|6.  Arcane Veil         | " << setw(5) << "   117  |" << setw(5) << "  09  |" << endl;			
	cout << "\t\t\t\t" << "|7.  Shadoweave Robes    | " << setw(5) << "    98  |" << setw(5) << "  08  |" << endl;
	cout << "\t\t\t\t" << "|8.  Beast Hide Armor    | " << setw(5) << "    86  |" << setw(5) << "  06  |" << endl;	
	cout << "\t\t\t\t" << "|9.  Celestial Aegis     | " << setw(5) << "    69  |" << setw(5) << "  05  |" << endl;					
	cout << "\t\t\t\t" << "|10. Guardian Shield     | " << setw(5) << "    55  |" << setw(5) << "  03  |" << endl;
	cout << "\t\t\t\t" << "|0.  Exit the menu       |         |      |"  << endl;
	cout << "\t\t\t\t" << "|________________________|_________|______|"  << endl;
	cout << endl << endl;
	
		
	int enterArmor, choice, selection, tempGem, tempArm;
    int totalArmor = 0, indexItem = 1;
    int returnGem, returnArmor;
    bool status;
    string name;

    ArmorList list;

    cout << "Please enter the armor that you would like to purchase:" << endl;
	bool armor = true;
    do {
		if(armor){
        cout << "Select a armor: ";
        enterArmor = getInput(0,10);
		}

        switch (enterArmor) {
        case 1:
            totalArmor += 183;
            totalGem -= 15;
            tempArm = 183;
            tempGem = 15;
            name = "Sentinel's Plate  ";
            break;
        case 2:
            totalArmor += 174;
            totalGem -= 14;
            tempArm = 174;
            tempGem = 14;
            name = "Stormguard Plate ";
            break;
        case 3:
            totalArmor += 150;
            totalGem -= 13;
            tempArm = 150;
            tempGem = 13;
            name = "Elven Chainmail";
            break;
        case 4:
            totalArmor += 136;
            totalGem -= 11;
            tempArm = 136;
            tempGem = 11;
            name = "Feyweave Cloak";
            break;
        case 5:
            totalArmor += 121;
            totalGem -= 10;
            tempArm = 121;
            tempGem = 10;
            name = "Dragon Scale Mail";
            break;
        case 6:
            totalArmor += 117;
            totalGem -= 9;
            tempArm = 117;
            tempGem = 9;
            name = "Arcane Veil";
            break;
        case 7:
            totalArmor += 98;
            totalGem -= 8;
            tempArm = 98;
            tempGem = 8;
            name = "Shadoweave Robes";
            break;
        case 8:
            totalArmor += 86;
            totalGem -= 6;
            tempArm = 86;
            tempGem = 6;
            name = "Beast Hide Armor";
            break;
        case 9:
            totalArmor += 69;
            totalGem -= 5;
            tempArm = 69;
            tempGem = 5;
            name = "Celestial Aegis";
            break;
        case 10:
            totalArmor += 55;
            totalGem -= 3;
            tempArm = 55;
            tempGem = 3;
            name = "Guardian Shield  ";
            break;
        default:
            cout << "Please select your armor based on the index listed in the table" << endl;
             // Skip adding the invalid armor to the linked list
        }
        if(armor == true){
            if (totalGem < 0) {
        	totalArmor -= tempArm;
            totalGem += tempGem;
            cout << "Oh no! The gems that you have collected are not enough." << endl;
        } else {
            appendNode(name, indexItem, tempGem, tempArm);
            indexItem++;
            cout << "Current Armor  : " << totalArmor << endl;
            cout << "Total Gems Left: " << totalGem << endl;
            cout << endl;
        }
	
			do{
            	    cout << "Do you still want to continue?" << endl;
        			cout << "(1: Yes, 2: Sell armors, 3: Show Bought armors, 0: Fight the boss): ";
        			choice = getInput(0,3);
        			if (choice > 3) {
					    cout << "Please enter valid input.";
					    choice = getInput(0,3);
					}

			}while(choice > 3);
        }
  

           if (choice == 2) {
		
			if(isEmpty()){
                cout << "You haven buy anything yet...." << endl;
                armor = true;
			}
			else{
				  do {
						
						if(!isEmpty()){
							displayArmor();
		                	cout << "The list above shows the weapons you have just purchased." << endl;
		                	cout << "Select the item you want to sell: ";
		                	selection = getInput(1,indexItem);
		                	
			                	deleteArmor(selection, returnGem, returnArmor);
			                	indexItem--;
			                	totalGem += returnGem;
			                	totalArmor -= returnArmor;
			                	
								// Update the index of remaining weapons
		                		for (int i = selection; i <= indexItem; i++) {
		                    		updateIndex(i, i - 1);
		                		}
		        
		                			cout << "Do you want to sell another armor? (1: Yes, 0: No): ";
		                			status = getInput(0,1);
							
						}
						else{
							cout << "You have sell all the armor that you have bought." << endl;
							
							status = 0;
						}
	
            	} while (status != 0);
            		do{
            	    	cout << "Do you still want to continue?" << endl;
        				cout << "(1: Yes,  0: Fight Boss): ";
        				choice = getInput(0,1);
						armor = true;
        		
        				//The loop cannot be gone through
					    if (choice > 1 ) {
					        cout << "Please enter valid input.";
					        cin >> choice;
						}
					}while(choice > 1);
			}
      
        
        }else if (choice == 3) {
            displayArmor();
			    do{
            	    cout << "Do you still want to continue?" << endl;
        			cout << "(1: Yes, 2: Sell armors, 3: Show Bought armors, 0: Fight the boss): ";
        			choice = getInput(0,3);
        			if ( choice > 3) {
					    cout << "Please enter valid input.";
					    choice = getInput(0,3);
					}
                    while(choice == 3){
                        displayArmor();
                        cout << "Do you still want to continue?" << endl;
        			    cout << "(1: Yes, 2: Sell Weapons, 3: Show Bought Weapons, 0: Buy Armor): ";
        			    choice = getInput(0,3);
                    }
        			if(choice == 1) 
						armor = true;
        			else 
						armor = false;	

				}while(choice > 3);

        }
    } while (choice != 0);
	
}

bool ArmorList::isEmpty(){

	if(number > 0){
		return false;
	}
	else return true;
}
void ArmorList::updateIndex(int oldIndex, int newIndex) {
    Node* pointer = headArmor;
    while (pointer != nullptr) {
        if (pointer->index == oldIndex) {
            pointer->index = newIndex;
        }
        pointer = pointer->next;
		}
} 

void ArmorList::deleteArmor(int index, int &gem, int &armor){
	Node* pointer;
	pointer = headArmor;
	
    Node* previous = nullptr;
    
	if (headArmor == nullptr) {
       return;
    }
	else{
		pointer = headArmor;
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
	    	armor = pointer->armor;

        	pointer = pointer->next;
        	delete headArmor;
        	headArmor = pointer;
        	number--;
    	} 
		else {
        	// Node to delete is not the head
			gem = pointer->gem;
			armor = pointer->armor;

        	previous->next = pointer->next;
        	delete pointer;
  		}
	}
}




void ArmorList::displayArmor(){
		Node *pointer;
	    if (headArmor == nullptr) {
        	// If the list is empty, display a message
        	cout << "The list is empty." << endl;
        	
    	} 
		else {
        	// Traverse the list and display the value of each node
        	pointer = headArmor;

    		while (pointer != nullptr) {
        		// Print the folloewing pointed value
				cout << "Weapon #" << pointer->index << endl;
				cout << "Name of the name  :" << pointer->name << endl;
    			cout << "Cost of the name   : " << pointer->gem << endl;
    			cout << "Armor of the name : " << pointer->armor << endl;
    			pointer = pointer->next;
    		}
            
    	}
}

void ArmorList::appendNode(string name, int index, int gem, int armor){
	number++;
	// new node is created to point the new value at the top of the stack
    Node* newNode, * pointer;
    newNode = new Node;
    newNode->name = name;
    newNode->index = index;
    newNode->gem = gem;
    newNode->armor = armor;
    newNode->next = nullptr;
    
    if (headArmor == nullptr) {
        // If the list is empty, make the new node the head
    	headArmor = newNode;
    } else {
        // Traverse to the last node

		pointer = headArmor;
        while (pointer->next != nullptr) {
            pointer = pointer->next;
        }

        // Append the new node to the last node
        pointer->next = newNode;

    }
}

ArmorList::~ArmorList() {
    // Destructor: Clear the linked list and free memory
    Node *current = headArmor;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}
