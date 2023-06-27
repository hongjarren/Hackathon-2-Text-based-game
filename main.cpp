#include <iostream>
#include <fstream>
#include "linkedList.h"
#include "stack.h"
#include <cstdlib> 
#include <ctime>
#include <unistd.h>
#include "weaponlist.h"
#include "armorlist.h"
#include <limits>

using namespace std;

int generateRandomDamage(int , int );
string getBossSkill();
bool isCriticalHit();
bool isDodgeSuccessful(int);
void clearScreen();
void bossFight(int , int ,int &,int &, int , int , int , int , int);
int currentProgress(int , int );
void afterPhase(int , int , int [], int []);
int randomNumber();
void clearScreen();
void printDecision(int [], int []);
void mainMenu(ArmorList& , WeaponList& , int& , int , int& , int& ,
    LinkedList& , Stack& , int , int , int , int ,
    int , int& , int& );
void loadStory(LinkedList&);
void startGame(ArmorList &, WeaponList &, int &, int  &,
			 LinkedList &, Stack &,int ,int , int , int ,
			 int , int , int );
int getInput(int, int );


int main() {
    LinkedList list;
    WeaponList attackList;
    ArmorList armorList;
    Stack savedFile;
	fstream gameFile;
    string story, decision1, decision2, decision3;
    int baseHealth = 150; // Player's initial health
    int baseDamage = 10; // Player's initial damage
    int numHealingPotions = 3; // Number of healing potions the player has
    int bossHealth = 4000; // Boss's initial health
    int dodgeRate = 20; // Boss's dodge rate
    int totalGem = 0, totalPace = 0;
    int totalArm =0, totalAttack=0;
    //Load the story
    loadStory(list);
    int saveLevel, saveGem, savePace;
    gameFile.open("savefile.txt", ios::in);
    if (gameFile.fail()) {
        cout << "Error in opening file #" << endl;
    } else {
        while (!gameFile.eof()) {
            gameFile >> saveLevel;
            gameFile >> saveGem;
            gameFile >> savePace;

            savedFile.push(saveLevel, saveGem, savePace);

            saveLevel = 0;
            saveGem = 0;
            savePace = 0;
        }
    }
    gameFile.close();

	//Start the game
  	startGame(armorList, attackList, totalGem, totalPace, list, savedFile, baseHealth, baseDamage, numHealingPotions, bossHealth, 
				dodgeRate, totalAttack, totalArm);

    gameFile.open("savefile.txt", ios::out);
    savedFile.pop(saveLevel, saveGem, savePace);
    gameFile << saveLevel << " " << saveGem << " " << savePace;
    
    return 0;
}
int getInput(int min, int max) {
    int input;
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter valid input." << endl;
        cout << "Enter number: ";
    }
    return input;
}

void startGame(ArmorList &armorList, WeaponList &attackList, int &totalGem, int  &totalPace,
			 LinkedList &list, Stack &savedFile,int baseHealth,int baseDamage, int numHealingPotions, int bossHealth,
			 int dodgeRate, int totalAttack, int totalArm){
	  int choice, level = 1;

    do {
        cout << "-------------------------" << endl;
        cout << "Welcome to Adventure..." << endl;
        cout << "1. Start the game." << endl;
        cout << "2. Continue the game." << endl;
        cout << "3. Exit the game." << endl;
        cout << "-------------------------" << endl;
        cout << ">> ";
		choice = getInput(1,3);
         cout << "-------------------------" << endl;

        switch (choice) {
            case 1:
                // Difficulty selection
                cout << "Select difficulty level:" << endl;
                cout << "1. Easy" << endl;
                cout << "2. Medium" << endl;
                cout << "3. Hard" << endl;
                cout << "Enter your choice: ";

                int difficulty;
                difficulty = getInput(1,3);
                cout << "-------------------------" << endl;


                // Set boss health and dodge rate based on the chosen difficulty
                switch (difficulty) {
                    case 1: // Easy
                        bossHealth = 4000;
                        dodgeRate = 20;
                        break;
                    case 2: // Medium
                        bossHealth = 5000;
                        dodgeRate = 15;
                        break;
                    case 3: // Hard
                        bossHealth = 6000;
                        dodgeRate = 10;
                        break;
                    default:
                        cout << "Invalid input. Difficulty set to Easy by default." << endl;
                        bossHealth = 5000;
                        dodgeRate = 20;
                        break;
                }

                mainMenu(armorList, attackList, choice, level, totalGem, totalPace, list, savedFile, baseHealth, baseDamage, numHealingPotions, bossHealth, dodgeRate, totalAttack, totalArm);
                break;

            case 2:
                char ans;
                cout << "Saved File:" << endl;
                savedFile.displayStack();
                cout << "Do you want to continue? Press Y or y to continue." << endl;
                cout << ">> ";
                cin >> ans;

                if (ans == 'y' || ans == 'Y') {
                    savedFile.pop(level, totalGem, totalPace);
                    level++;
                    choice = 1;
                    mainMenu(armorList, attackList, choice, level, totalGem, totalPace, list, savedFile, baseHealth, baseDamage, numHealingPotions, bossHealth, dodgeRate, totalAttack, totalArm);
                }

                break;
            case 3:
                cout << "Exiting..." << endl;
                sleep(1);

                break;

            default:
                cout << "Key in the choice by referring to the index of the choice given...." << endl;
        }
    } while (choice != 3);
}

void loadStory(LinkedList &list){
		string story, decision1, decision2, decision3;
	    ifstream inputFile;   
    for (int i = 0; i < 10; i++) {
        string fileName = "scene";
        string fileIndex = to_string(i + 1);
        fileName = fileName + string(fileIndex);
        inputFile.open(fileName + ".txt");

        if (inputFile.fail()) {
            cout << "Error in opening file #" << endl;
        } else {
            if (!inputFile.eof()) {
                getline(inputFile, story);
                getline(inputFile, decision1);
                getline(inputFile, decision2);
                getline(inputFile, decision3);

                list.appendNode(story, decision1, decision2, decision3);

                story = "";
                decision1 = "";
                decision2 = "";
                decision3 = "";
            }
        }
        inputFile.close();
    }
    
       
}


int randomNumber() {
    // Generate a random number between minLimit and maxLimit
    int randomNumber1 = rand() % 5 + 1;
    return randomNumber1;  
}
void afterPhase(int level, int decide, int arrayGem[], int arrayPace[]){
			    cout <<"______________________________________________________" << endl;
			    cout <<" __  " << "|    " << "     "  << "      "  << "       " << endl;
			    cout <<"|  | " << "|    " << " ___ "  << " ___  "  << "  ____" << endl;
			    cout <<"|__| " << "|___ " << "|   |"  << "|     "  << " |    |" << endl; 
			    cout <<"|    " << "|   |" << "|___|"  << "|____ "  << " |____|" << endl; 
			    cout <<"|    " << "|   |" << "    |"  << "     |"  << " |____" << endl; 
			    cout <<"     " << "     " << "     "  << " ____|"  << "       " << endl; 
			    cout <<"______________________________________________________" << endl;
			    cout <<"Phase: " << level << endl;
			    cout <<"Number of pace: " << arrayPace[decide-1] << endl;
			    cout <<"Number of gem: " << arrayGem[decide-1]  << endl;

}
int currentProgress(int totalPace, int totalGem){
    int choice;
		    //Print out the current prograssion
		    cout <<" ____________________________" << endl;
		    cout <<"|    Current Progression     |" << endl;
		    cout <<"|____________________________|" << endl;
		    cout <<"|" <<"Total number of pace: " << totalPace << "    |" << endl;
		    cout <<"|" <<"Total number of gem:  " << totalGem  << "    |" << endl;  
		    cout <<"|____________________________|" << endl;
                
    //Ask user to see if they want to continue
    cout << "Do you want to proceed to other phase or exit the game?" << endl;
    cout << "1. Continue the game." << endl;
    cout << "2. Show the current progression." << endl;
    cout << "3. Exit and save current progression." << endl;
    cout << "Choice-> ";
    choice = getInput(1,3);    
    return choice;
}

void bossFight(int baseHealth, int baseAttack,int &playerHealth, int &playerDamage, int numHealingPotions, int bossHealth, int dodgeRate, int totalGem, int totalPace) {
    int bossMinDamage = 10;
    int bossMaxDamage = 20;
    int currentBossHealth = bossHealth;
    int phase = 1; // Current boss phase

 	ifstream bossStoryFile("scene10.txt");
    if (bossStoryFile.is_open()) {
        string line;
        while (getline(bossStoryFile, line)) {
            cout << line << endl;
        }
       
    } else {
        cout << "Failed to open boss_story.txt" << endl;
        return;
    }
	cout<<"Press enter to continue"<<endl;
	cin.ignore();
	cin.get();
 bossStoryFile.close();

    // Pause for a moment to allow the player to read the story
    sleep(1);
    // Game loop for the boss fight
    baseHealth += playerHealth;
    while (currentBossHealth > 0 && baseHealth > 0) {
        clearScreen(); // Clear the console screen

        // Player's turn
        cout << "Player's turn." << endl;
        cout << "Choose your attack style:" << endl;
        cout << "1. Slash" << endl;
        cout << "2. Bash" << endl;
        cout << "3. Stab" << endl;
        cout << "4. Fireball" << endl;
        cout << "5. Lightning Strike" << endl;
        cout << "6. Poison Dagger" << endl;
        cout << "Enter your choice: ";
        int attackStyle;
        attackStyle = getInput(1,6);
        
        string attackName = "";

        // Calculate damage based on the chosen attack style and additional damage
        switch (attackStyle) {
            case 1:
                baseAttack = generateRandomDamage(playerDamage + 5, playerDamage + 10);
                attackName = "Slash";
                break;
            case 2:
                baseAttack = generateRandomDamage(playerDamage + 5, playerDamage + 10);
                attackName = "Bash";
                break;
            case 3:
                baseAttack = generateRandomDamage(playerDamage + 5, playerDamage + 10);
                attackName = "Stab";
                break;
            case 4:
                baseAttack = generateRandomDamage(playerDamage + 8, playerDamage + 12);
                attackName = "Fireball";
                break;
            case 5:
                baseAttack = generateRandomDamage(playerDamage + 8, playerDamage + 12);
                attackName = "Lightning Strike";
                break;
            case 6:
                baseAttack= generateRandomDamage(playerDamage + 8, playerDamage + 12);
                attackName = "Poison Dagger";
                break;
            default:
                cout << "Invalid input. Please choose a valid attack style." << endl;
                continue;
        }

        // Check for critical hit
        if (isCriticalHit()) {
            baseAttack *= 2; // Double the player's damage
            cout << "Critical Hit! Your attack deals double damage!" << endl;
        }

        // Check if the boss dodges the attack
        if (isDodgeSuccessful(dodgeRate)) {
            baseAttack = 0; // Set player damage to 0
            cout << "The boss dodged your attack!" << endl;
        } else {
            currentBossHealth -= baseAttack;
        }

        // Check if the player defeated the boss
        if (currentBossHealth <= 0) {
          
            cout <<"You have defeated the dragon, and as a reward for you,";
			cout <<"the wicked wizard finally lifted the curse on you and memories starts to flood back in. ";
			cout <<"You were a novice adventurer back then, arrived in this mysterious area years ago alongside your sister. ";
			cout <<"Guided by your own choices which are exactly the same choices that you took each step of the way now, ";
			cout <<"you embarked on a perilous journey, gradually unraveling the secrets of the land. However, upon reaching the door, ";
			cout <<"a malevolent curse befell you, wiping away your memories of the past and separating you from your sister, ";
			cout <<"who was taken hostage by an unknown force. Now, standing victorious over the defeated boss, ";
			cout <<"memories flood back to your  mind like fragments of a shattered mirror. As the haze of forgotten recollections lifts, ";
			cout <<"you realize that  your sister is nowhere to be found. The realization hits you with a mix of relief and anguish, ";
			cout <<"for your memories have returned, but your sister's fate remains unknown."<<endl;
			cout << "Congratulations! You defeated the boss!" << endl;
			cin.ignore();
			cin.get();
            exit(0);
            break;
        }

        // Display boss's turn message
        cout << "Boss's turn..." << endl;
        sleep(1); // Pause for 1 second to simulate delay

        // Select random fighting style for the boss
        int bossDamage = generateRandomDamage(bossMinDamage, bossMaxDamage);

        // Check for critical hit
        if (isCriticalHit()) {
            bossDamage *= 2; // Double the boss's damage
            cout << "Critical Hit! The boss's attack deals double damage!" << endl;
        }

        // Check if the player dodges the boss's attack
        if (isDodgeSuccessful(dodgeRate)) {
            bossDamage = 0; // Set boss damage to 0
            cout << "You dodged the boss's attack!" << endl;
        } else {
            baseHealth -= bossDamage;
        }

        // Display boss skill used
        string bossSkill = getBossSkill();
        cout << "The boss used " << bossSkill << " and dealt " << bossDamage << " damage!" << endl;

        // Check if the boss defeated the player
        if (baseHealth <= 0) {
            cout << "Game over! The boss defeated you." << endl;
            exit(0);
            break;
        }

        // Display current health status and attack information
        cout << "Player Health: " << baseHealth << " | Boss Health: " << currentBossHealth << endl;
        cout << "You used " << attackName << " and dealt " << baseAttack << " damage!" << endl;

        // Check if the player has healing potions and offer the option to use one
        if (numHealingPotions > 0) {
            cout << "You have " << numHealingPotions << " healing potion(s)." << endl;
            cout << "Do you want to use a healing potion? (y/n): ";
            char usePotion;
            cin >> usePotion;

            if (usePotion == 'y' || usePotion == 'Y') {
                // Use a healing potion to restore some player health
                int potionHealAmount = 20; // Set the healing amount for each potion
                baseHealth += potionHealAmount;

                // Reduce the number of available healing potions
                numHealingPotions--;

                cout << "You used a healing potion and restored " << potionHealAmount << " health." << endl;
                cout << "Player Health: " << baseHealth << " | Boss Health: " << currentBossHealth << endl;
            }
        }

        // Check boss phase and modify boss behavior accordingly
        if (currentBossHealth <= bossHealth * 0.75 && phase == 1) {
            cout << "Boss has entered Phase 2! It is now more powerful!" << endl;
            bossMinDamage = 6;
            bossMaxDamage = 8;
            phase = 2;
        } else if (currentBossHealth <= bossHealth * 0.5 && phase == 2) {
            cout << "Boss has entered Phase 3! It has transformed and gained new abilities!" << endl;
            bossMinDamage = 8;
            bossMaxDamage = 10;
            phase = 3;
        } else if (currentBossHealth <= bossHealth * 0.25 && phase == 3) {
            cout << "Boss has entered Phase 4! Its power has reached its peak!" << endl;
            bossMinDamage = 10;
            bossMaxDamage = 12;
            phase = 4;
        }

        // Pause for a moment before the next iteration
        sleep(1);
    }
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool isCriticalHit() {
	
    const int criticalHitChance = 20; // 20% chance of a critical hit
    int randomChance = rand() % 100 + 1; // Generate a random number between 1 and 100
    return randomChance <= criticalHitChance;
}

int generateRandomDamage(int minDamage, int maxDamage) {
    return rand() % (maxDamage - minDamage + 1) + minDamage;
}

string getBossSkill() {
    string skills[] = { "Fireball", "Thunderstrike", "Poison Breath", "Earthquake" };
    int numSkills = sizeof(skills) / sizeof(skills[0]);
    int randomIndex = rand() % numSkills;
    return skills[randomIndex];
}

bool isDodgeSuccessful(int dodgeRate) {
    int randomChance = rand() % 100 + 1; // Generate a random number between 1 and 100

    return randomChance <= dodgeRate;
}

void printDecision(int arrayGem[], int arrayPace[]){
    cout << "Reward: " << endl;
    cout << "Decision 1: " << "[ Gem: " << arrayGem[0] << "; Pace: " << arrayPace[0] << "]" << endl;
    cout << "Decision 2: " << "[ Gem: " << arrayGem[1] << "; Pace: " << arrayPace[1] << "]" << endl;    
    cout << "Decision 3: " << "[ Gem: " << arrayGem[2] << "; Pace: " << arrayPace[2] << "]" << endl;    
}

void mainMenu(ArmorList& armorList, WeaponList& attackList, int& choice, int level, int& totalGem, int& totalPace,
    LinkedList& list, Stack& savedFile, int baseHealth, int baseAttack, int numHealingPotions, int bossHealth,
    int dodgeRate, int& totalAttack, int& totalArm) {
    int decide = 0;
    do {
        switch (choice) {
            case 1:
                cout << "Entering....." << endl;
                sleep(1);

                // Randomly assign a column into two arrays for gem and pace
                int arrayGem[3], arrayPace[3];
                for (int i = 0; i < 3; i++) {
                    arrayGem[i] = randomNumber();
                    arrayPace[i] = randomNumber();
                }

                list.displayList(level);
                printDecision(arrayGem, arrayPace);

                // Let the player make the decision
                cout << "Decide -> ";
                decide = getInput(1,3);
                while(decide > 3){
                	cout << "Please enter a valid number: " << endl;
                	cin  >> decide;
				}


                // Total up all the number of pace and gem
                totalGem += arrayGem[decide - 1];
                totalPace += arrayPace[decide - 1];
                cout << endl;

                // Print out the data of current phases
                if (level < 10) {
                    afterPhase(level, decide, arrayGem, arrayPace);
                }

                savedFile.push(level, totalGem, totalPace);

                // Ask user to see if they want to continue
                cout << "-------------------------------------------------------" << endl;
                if (level < 9) {
                    cout << "Do you want to proceed to the next phase or exit the game?" << endl;
                    cout << "1. Proceed to the next phase." << endl;
                    cout << "2. Show the current progression." << endl;
                    cout << "3. Exit and save current progression." << endl;
                } else if (level == 9) {
                    cout << "Congratulation, you have found a chest" << endl;
	           		if((totalPace - 5 ) <= 30 && totalPace >= 30 ){
           				cout << "Yes, you have found 10 gems" << endl;
						totalGem += 10;   
						cout << "Congratulation, you have successfully collected " << totalGem << " gems" << endl;     			
					}
					else{
						cout << "Oh no, there is a goblin in the chest, he has stolen 5 gems from you." << endl;
						totalGem -= 5;
						cout << "Don't worry, you still have " << totalGem << " gems left" << endl;
					}
					sleep(1);
                    cout << "You have now entered a shop." << endl;
                    
                    cout << "Entering...." << endl;
                    sleep(1);
                    attackList.WeaponMenu(totalGem, totalAttack);
                    armorList.armorMenu(totalGem, totalArm);
                    cout << "Do you want to proceed to the boss fight or exit the game?" << endl;
                    cout << "1. Proceed to the boss fight." << endl;
                    cout << "2. Show the current progression." << endl;
                    cout << "3. Exit and save current progression." << endl;
                } else {
                    cout << "Do you want to exit the game and save the current progression?" << endl;
                    cout << "1. Exit and save current progression." << endl;
                }
                cout << "Choice-> ";
                choice = getInput(1,3);


                if (level < 9) {
                    if (choice == 1) {
                        level++;
                    }
                } else if (level == 9) {
                    if (choice == 1) {
                        level++;
                        bossFight(baseHealth, baseAttack, totalArm, totalAttack, numHealingPotions, bossHealth,
                            dodgeRate, totalGem, totalPace); // Pass the required arguments to the bossFight function
                    }
                }
                break;
            case 2:
                choice = currentProgress(totalPace, totalGem);
                if (level < 9) {
                    level++;
                }
                break;
            case 3:
                cout << "Exiting...." << endl;
                sleep(1);

                choice = 3;
                break;

            default:
                cout << "Key in the choice by referring to the index of the choice given...." << endl;
                choice = getInput(1,3);

        }

        // clearScreen();

    } while (choice != 3);
}
