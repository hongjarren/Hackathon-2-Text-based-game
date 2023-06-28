# Group 36
NG CHEN YANG 164077
HONG SOON CHUAN JARREN 163219
BOK WEI HONG 163190

# Hackathon-2-Text-based-game
This is the progression of our hackathon 2 project to create a text based game using C++ only
Game Documentation

## Description
This game is a text-based adventure game where players embark on a quest to defeat a powerful boss. The player's goal is to gather weapons and armor by purchasing them with gems collected throughout the game. By strategically equipping weapons and armor, the player can increase their attack and defense stats, enhancing their chances of defeating the boss.

## Features
- Purchase weapons and armor using collected gems.
- Sell weapons and armor to regain gems.
- View the list of purchased weapons and armor.
- Manage inventory by dynamically updating linked lists for weapons and armor.
- Use stacks to save and restore the game state.
- Explore a text-based world and engage in battles.

## How to Play
1. Start the game and enter the main menu.
2. From the main menu, choose options to purchase weapons and armor, sell weapons, view purchased items, or exit the game.
3. In the purchase menu, select a weapon or armor to buy using the corresponding index.
4. Confirm your selection and check your current attack and gem status.
5. Optionally, sell purchased weapons to regain gems and adjust your attack.
6. Explore the game world and engage in battles to defeat the boss.

## Object-Oriented Concepts
The game utilizes several object-oriented concepts, including encapsulation, abstraction, and modularity. The game logic is encapsulated within classes, such as `WeaponList`, `ArmorList`, and `Stack`, which provide data and methods for managing weapons, armor, and game state. Abstraction is achieved by hiding implementation details and providing high-level interfaces for interacting with the game. Modularity is maintained by separating different functionalities into different classes, promoting code organization and reusability.

## Linked Lists, Stacks, and Queues
Linked lists play a crucial role in managing the player's inventory of weapons and armor. The `WeaponList` and `ArmorList` classes use linked lists to dynamically store and manage the purchased items. Linked lists allow for efficient insertion, deletion, and traversal of items in the inventory.

Stacks are utilized to save and restore the game state. The `Stack` class enables the player to save their progress and return to a previous state. It stores information about the level, gems, and pace, allowing the player to undo actions and explore different strategies.

## Screenshots and Demo Video
Please get the screenshots of our game from the below link
https://docs.google.com/document/d/1wJphnxcAXKVq0iIOzztL68cot7Te6oP6mIjg_DZNHFg/edit?usp=sharing
![image](https://media.discordapp.net/attachments/1030850353593335809/1123476642426277909/image.png?width=570&height=662)

![image](https://cdn.discordapp.com/attachments/1030850353593335809/1123476682800631808/image.png)

![image](https://cdn.discordapp.com/attachments/1030850353593335809/1123476858504232960/image.png)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123476885863669770/image.png?width=618&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123476910912065607/image.png?width=531&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123476932168790086/image.png?width=588&height=536)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123476985486778419/image.png?width=626&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477022275010601/image.png?width=511&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477045951864942/image.png?width=626&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477075328761926/image.png?width=495&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477096002502727/image.png?width=628&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477117796106320/image.png?width=567&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477143914033163/image.png?width=527&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477169008554004/image.png?width=567&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477188344283226/image.png?width=606&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477205918416926/image.png?width=707&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477232732610610/image.png?width=730&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477265330737172/image.png?width=490&height=661)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477286063198238/image.png?width=552&height=662)

![image](https://media.discordapp.net/attachments/1030850353593335809/1123477310042017893/image.png?width=541&height=662)


Please find our video game demo from the below link
https://youtu.be/JozFO5nBlwI

## Code Files
- `WeaponList.h` and `WeaponList.cpp`: Implement the `WeaponList` class for managing weapons.
- `ArmorList.h` and `ArmorList.cpp`: Implement the `ArmorList` class for managing armor.
- `Stack.h` and `Stack.cpp`: Implement the `Stack` class for managing the game state.
- [Add other code files here]

Note: The code provided can be compiled using any IDE, GCC, or G++. Ensure all the necessary files are included during compilation.

## Additional Information from Original Readme

1. Game Overview

Game Concept

Players in the text-based adventure game set out on an adventure by moving through various stages. Each phase requires players to make decisions, gather gems and pace, and participate in battles. At the game's conclusion, there is a boss encounter that players must win in order to finish the quest. The player's decisions and strategic thinking determine the gameplay.
Target Audience

Players who like text-based adventure games with a decision-making, strategy, and warfare emphasis will appreciate this game. Players that value compelling tales, character development, and demanding gameplay make up the target audience.

2. Installation and Requirements

Requirements



- C++ Compiler
- Standard C++ Library
- Operating System: Windows

Installation Instructions

1. Download the Adventure game source code files.
2. Open a C++ development environment (e.g., Code::Blocks, Visual Studio Code, Xcode).
3. Create a new C++ project.
4. Add the downloaded source code files to the project.
5. Build and compile the project.
6. Run the compiled executable to start the game.

3. Gameplay

Controls

Players interact with the game through a text-based interface by entering numerical selections. On the screen, the player is led through the game by the choices that are offered and the instructions that go with them.
Progression

Different phases of the game's development are each depicted by a scenario. By choosing choices, players move from Phase 1 to Phase 2 of the game. The choices made affect the quantity of gems and pace that are amassed, both of which advance the player overall.
Phases and Decisions

Players are given three options for each phase. Gem and pace rewards for decisions are determined at random. Players must input the corresponding number to select one of the three options.

Boss Battle

Players begin the boss battle after finishing all phases. The player and the boss engage in turn-based combat during the boss battle. Players can conduct actions like slashing, pounding, stabbing, or employing special skills. They can also choose attack styles. The boss has a variety of skills to assault the player as well. The fight goes on until the boss or the player's health is completely depleted. Players have the opportunity to use their acquired gems to buy weapons and armour before the boss encounter to help them in battle.
Difficulty Levels

Three degrees of difficulty are available in the game: Easy, Medium, and Hard. The boss battle is more harder due to the difficulty setting's effect on the boss' health and dodge rate. At the beginning of the game, players can choose the desired level of difficulty.

4. Mechanics and Features

Generating Random Damage

To produce random damage numbers within a range, the game employs the 'generateRandomDamage' function. The function returns a random damage value between the minimum and maximum values given as inputs. This mechanism adds variation to attack damage and increases the unpredictability of combat engagements.
Boss Skills and Dodge Mechanism

The boss is capable of using a number of abilities, including Fireball, Thunderstrike, Poison Breath, and Earthquake. The skill the boss will employ while taking its turn in the combat is chosen at random by the 'getBossSkill' function. A dodge method is also used in the game to decide whether a player or boss successfully avoids an attack. Based on the dodge rate parameter, the 'isDodgeSuccessful' function determines the likelihood that a dodge would be successful.
Healing Potions and Critical Hits

In order to recover health during combat, players can use healing potions. The player is given the option to utilise a healing potion or not if they have any on hand. A potion's use will restore the player's health by a set amount. Another game mechanic is critical hits. Based on a preset critical hit chance, the 'isCriticalHit' function assesses if an attack is a critical hit. When a critical hit occurs, the attacking player or boss deals twice as much damage.

Game Save and Continue

Players can save their progress in the game and pick up where they left off by using the resume feature. The saved game states are managed using the 'Stack' data structure. The level, total number of gems, and overall pace are all restored when players decide to restart the game using the saved data that has been retrieved.

PROGRESSION TRACKER
The player can, at any point of the journey, choose to view the progression they made so far, this includes on which phase they are at right now, the rewards they have gained thus far and how many pace they have taken. This is to allow an easier decision making throughout the game.

COHERENT STORYLINE
 Each phase of the story has been thoroughly planned to ensure coherent storytelling throughout the game. Each decision you make will have a story relating it to the next phase so you can ensure to have a fine time reading through the stories we have prepared.

 NEW GAME
 The game also has  a new game feature, for when the player wishes to start fresh if they feel like they made a bad decision. The reasoning for not allowing the players to return back to specific phase is for balancing, so that the players are ever only given one chance to make their decision for immersion purpose. 

GEARS
The game also incorporated a gear system wherein the players are allowed to use their rewards to purchase weapons or armors to aid them in their final boss fight. Wise decisions must be made here as well as the amount of money you spend will determine if you can defeat the boss. 

PROGRESSION TRACKER
The player can, at any point of the journey, choose to view the progression they made so far, this includes on which phase they are at right now, the rewards they have gained thus far and how many pace they have taken. This is to allow an easier decision making throughout the game.

INPUT VALIDATION
An input validation has been implemented throughout the program to ensure only the intended keys are inputted to ensure the game runs smoothly





5. Additional Components

The Adventure game utilizes the following additional components:

- Linked List: The `

LinkedList` class manages the game's scenes (phases). It provides functions to append nodes representing each scene and display the current scene based on the player's progression.

- Stack: The `Stack` class handles the saved game states. It allows pushing and popping of game state data, such as the level, total gems, and total pace. The stack data structure enables saving and restoring the game progress.

- Weapon List: The `WeaponList` class provides a menu for players to select weapons using gems they have collected. The class manages the weapons available in the game and allows players to upgrade their attack damage by purchasing better weapons.

- Armor List: The `ArmorList` class presents players with armor options in a menu format. Players can choose to upgrade their armor using collected gems. The class manages the available armor types and their corresponding effects on the player's health.

6. Game Flow

The Adventure game follows a specific flow to provide an immersive gaming experience. The main components and interactions are as follows:

1. Game Initialization:
   - The required libraries are imported.
   - Necessary functions and variables are declared.
   - Relevant game files (e.g., story scenes) are loaded.

2. Main Menu:
   - Players are presented with options to start a new game, continue from a saved state, or exit the game.
   - Depending on the selected option, players progress to different sections of the game.

3. Gameplay:
   - Players start at Phase 1 and progress through subsequent phases by making decisions.
   - Players are presented with three decisions, each associated with different rewards in terms of gems and pace.
   - The selected decision affects the player's overall progress.
   - After completing all phases, players enter the boss battle.

4. Boss Battle:
   - Players engage in a turn-based combat with the boss.
   - Players choose attack styles and perform actions.
   - The boss attacks the player with various skills.
   - The battle continues until either the player's health or the boss's health reaches zero.

5. Game Save and Exit:
   - Players can save their game progress and exit the game at any time.
   - Saved game data is stored in a file and can be loaded to continue the game later.

7. Code Explanation

Function Overview

- `generateRandomDamage(minDamage, maxDamage)`: Generates a random damage value within the specified range.

- `getBossSkill()`: Retrieves a random boss skill from a predefined list.

- `isCriticalHit()`: Determines if an attack results in a critical hit based on a predefined chance.

- `isDodgeSuccessful(dodgeRate)`: Determines if an attack is successfully dodged based on a dodge rate.

- `clearScreen()`: Clears the console screen.

- `bossFight()`: Manages the boss fight gameplay, including player and boss turns, attack calculations, health tracking, and phase transitions.

- `currentProgress(totalPace, totalGem)`: Displays the current progression of the player, including the total number of pace and gems collected. Allows the player to continue or exit the game.

- `afterPhase(level, decide, arrayGem[], arrayPace[])`: Prints the data of the current phase, including the phase level, number of pace, and number of gems.

- `randomNumber()`: Generates a random number between 1 and 5.

- `printDecision(arrayGem[], arrayPace[])`: Prints the available decisions and their associated rewards.

- `mainMenu()`: Handles the main menu functionality, including starting a new game, continuing from a saved state, or exiting the game.

- `main()`: The main function that initializes the game and controls the flow of the game based on the player's choices.

8. Future Enhancements

Additional features and

 enhancements can be made to the adventure game, such as:

1. Extended Storyline: To create a richer and more immersive tale experience, new phases, scenes, and options will be added.

2. More Boss Battles: Adding a number of boss fights with various degrees of difficulty and special dynamics.

3. Using a more sophisticated fighting system with a variety of attack types, combinations, and special powers.

4. Multiplayer option: A multiplayer option , allowing players to take part in the journey alone or with friends.

5. Ensure the classes of the project can be related to each other coherently.



9. Conclusion

Players in the adventure game move through many phases, make decisions, and engage in tactical combat in an entertaining text-based gaming experience. The game provides players with an immersive adventure because to its decision-making features, story-driven gameplay, and difficult boss encounters.

