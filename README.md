# Hackathon-2-Text-based-game
This is the progression of our hackathon 2 project to create a text based game using C++ only
Game Documentation

 Introduction

The Adventure Game is a fun text-based game that lets players engage with the game. Players in this game move through many phases, make decisions, and engage in combat. The gameplay is centred on a compelling narrative that gives players a range of choices and unforeseen outcomes. The adventure comes to a thrilling conclusion with a last boss encounter in the game. Players have the chance to gather gems and pace throughout the game, which help to improve their skills and advancement. To fight the boss and completely complete the entire adventure is the game's main goal.

Table of Contents

1. Game Overview
    - Game Concept
    - Target Audience
2. Installation and Requirements
    - Requirements
    - Installation Instructions
3. Gameplay
    - Controls
    - Progression
    - Phases and Decisions
    - Boss Battle
    - Difficulty Levels
4. Mechanics and Features
    - Generating Random Damage
    - Boss Skills and Dodge Mechanism
    - Healing Potions and Critical Hits
    - Game Save and Continue
5. Additional Components
    - Linked List
    - Stack
    - Weapon List
    - Armor List
6. Game Flow
7. Code Explanation
    - Function Overview
    - Main Function
8. Future Enhancements
9. Conclusion
10. References

1. Game Overview

Game Concept

Players in the text-based adventure game set out on an adventure by moving through various stages. Each phase requires players to make decisions, gather gems and pace, and participate in battles. At the game's conclusion, there is a boss encounter that players must win in order to finish the quest. The player's decisions and strategic thinking determine the gameplay.
Target Audience

Players who like text-based adventure games with a decision-making, strategy, and warfare emphasis will appreciate this game. Players that value compelling tales, character development, and demanding gameplay make up the target audience.
2. Installation and Requirements

Requirements

- C++ Compiler
- Standard C++ Library
- Operating System: Windows, macOS, or Linux

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

Players begin the boss battle after finishing each phase. The player and the boss engage in turn-based combat during the boss battle. Players can conduct actions like slashing, pounding, stabbing, or employing special skills. They can also choose attack styles. The boss has a variety of skills to assault the player as well. The fight goes on until the boss or the player's health is completely depleted. Players have the opportunity to use their acquired gems to buy weapons and armour before the boss encounter to help them in battle.
Difficulty Levels

Three degrees of difficulty are available in the game: Easy, Medium, and Hard. The boss battle is more harder due to the difficulty setting's effect on the boss' health and dodge rate. At the beginning of the game, players can choose the desired level of difficulty..

4. Mechanics and Features



Generating Random Damage

To produce random damage numbers within a range, the game employs the 'generateRandomDamage' function. The function returns a random damage value between the minimum and maximum values given as inputs. This mechanism adds variation to attack damage and increases the unpredictability of combat engagements.
Boss Skills and Dodge Mechanism

The boss is capable of using a number of abilities, including Fireball, Thunderstrike, Poison Breath, and Earthquake. The skill the boss will employ while taking its turn in the combat is chosen at random by the 'getBossSkill' function. A dodge method is also used in the game to decide whether a player or boss successfully avoids an attack. Based on the dodge rate parameter, the 'isDodgeSuccessful' function determines the likelihood that a dodge would be successful.
Healing Potions and Critical Hits

In order to recover health during combat, players can use healing potions. The player is given the option to utilise a healing potion or not if they have any on hand. A potion's use will restore the player's health by a set amount. Another game mechanic is critical hits. Based on a preset critical hit chance, the 'isCriticalHit' function assesses if an attack is a critical hit. When a critical hit occurs, the attacking player or boss deals twice as much damage.
Game Save and Continue

Players can save their progress in the game and pick up where they left off by using the resume feature. The saved game states are managed using the 'Stack' data structure. The level, total number of gems, and overall pace are all restored when players decide to restart the game using the saved data that has been retrieved.
5. Additional Components

The Adventure game utilizes the following additional components:

- Linked List: The `LinkedList` class manages the game's scenes (phases). It provides functions to append nodes representing each scene and display the current scene based on the player's progression.

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

Additional features and enhancements can be made to the adventure game, such as:

1. Extended Storyline: To create a richer and more immersive tale experience, new phases, scenes, and options will be added.

2. More Boss Battles: Adding a number of boss fights with various degrees of difficulty and special dynamics.

3. Using a more sophisticated fighting system with a variety of attack types, combinations, and special powers.

4. Multiplayer option: A multiplayer option is now available, allowing players to take part in the journey alone or with friends.

5. Ensure the classes of the project can be related to each other coherently. 

 9. Conclusion

Players in the adventure game move through many phases, make decisions, and engage in tactical combat in an entertaining text-based gaming experience. The game provides players with an immersive adventure because to its decision-making features, story-driven gameplay, and difficult boss encounters.
