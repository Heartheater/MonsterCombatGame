#include "MonsterGame.hpp"



MonsterGame::MonsterGame(Player &player)
	: m_gameWon{false}, m_player{player}
{
	startGame();
}

MonsterGame::MonsterGame(const std::string &playerName)
	: m_gameWon{ false }, m_player{ Player(playerName) }
{
	startGame();
}

void MonsterGame::startGame() {
	//greet player
	std::cout << "Welcome, " << m_player.getName() << ".";
	std::cout << m_player << "\n";
	//run game
	m_gameWon = MonsterGame::runGame(m_player);
	//end game after running
	endGame();
}

void MonsterGame::printMenu() const
{
	std::cout << "\nMenu Options: ";
	std::cout << "\n\t(R)un \n\t(F)ight \n\t(M)onster Status\n\t(P)layer Status.";
}

MonsterGame::Actions MonsterGame::getMenuInput(const Monster &m)
{
	char input = '0';

	//loop until player chooses valid response
	while (true)
	{
		std::cout << m << "\nInput:  ";
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cout << "\nPlease enter a valid menu option. Enter 'h' for help.";
			std::cin.ignore(32767, '\n');
			std::cin.clear();
		}
		else
		{
			switch (input)
			{
			case 'R':
			case 'r':
				return Actions::RUN;
			case 'F':
			case 'f':
				return Actions::FIGHT;
			case 'M':
			case 'm':
				//print Monster's Stats
				m.printAllStats();
				break;
			case 'P':
			case 'p':
				//print player's stats
				m_player.printAllStats();
				break;
			case 'H':
			case 'h':
				std::cout << "Please type a single letter:\n'R' for Run, 'F' for Fight, 'M' for Monster's Status, or 'P' for Player's status. Then hit enter to proceed.\nLetters may also be in lowercase.\n";
				break;
			default:
				std::cout << "\nPlease enter a valid menu option. Enter 'h' for help.";
				break;
			}
		}
	}
}



bool MonsterGame::runGame(Player &player)
{
	Actions chosenOption = Actions::RUN;
	bool playerIsFighting = false;

	//game loops until player wins or dies
	while (!player.hasWon())
	{
		//generate monster
		Monster m = Monster::getRandomMonster();
		std::cout << "-------------------------------------\n";
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") appears.\n";
		
		//player is now fighting a new monster
		playerIsFighting = true;
		//print out the menu at beginning of fight
		printMenu();
		while (playerIsFighting)
		{
			//first check if player already died
			if (player.isDead())
			{
				std::cout << "\nYou were killed by the monster!\n";
				playerIsFighting = false;
				return false;
			}

			// listen for player input and returns if the player chose to either run or fight
			chosenOption = MonsterGame::getMenuInput(m);

			if (chosenOption == Actions::FIGHT)
			{
				std::cout << "-------------------------------------\n";
				std::cout << "\nYou fight the " << m.getName() << ".\n";
				std::cout << "\nYou dealt " << player.getDamage() << " damage to " << m.getName();

				//decrease monsters health when player attacks
				m.reduceHealth(player.getDamage());

				//check if monster is dead and player won
				if (m.isDead())
				{
					std::cout << "\nYou defeated the " << m.getName() << " and got " << m.getGold() << " gold.\n";
					player.addGold(m.getGold());
					player.levelUp();
					std::cout << "\nYou leveled up to level " << player.getLevel() << "! +1ATTACK (" << player.getDamage() << ")\n";
					//check if the monster had an item
					if (m.checkHasItem())
					{	
						switch (m.getItem())
						{
						case Monster::Item::POTION:
							std::cout << "\n\nThe Monster dropped a Potion. ";
							if (player.getHealth() < player.m_baseHealth) //add health if player doesnt have full health
							{
								std::cout <<"\nYou recovered 1 health!\n";
								player.addHealth(1);
							}
							else
							{
								std::cout << "\nYour health is already maxed out.\n";
							}
						}
					}

					playerIsFighting = false;
				}
				else //otherwise it's the monster's turn to attack
				{
					player.reduceHealth(m.getDamage()); //player takes a hit
					std::cout << "\n" << m.getName() << " attacks!\nYou took " << m.getDamage() << " damage.";
					std::cout << "\nYou have " << player.getHealth() << " health.\n";
				}
			}

			else //player decides to run
			{	
				std::cout << "-------------------------------------\n";
				//get a random number between 1 and 2 to decide if player escapes or not
				if (Monster::getRandomNumber(1, 2) == 1)
				{
					std::cout << "\nYou ran away!\n";
					playerIsFighting = false;
				}
				else
				{
					std::cout << "\nYou couldn't escape!";
					//it's the monster's turn to attack
					player.reduceHealth(m.getDamage());
					std::cout << "\n" << m.getName() << " attacks!\nYou took " << m.getDamage() << " damage.";
					std::cout << "\nYou have " << player.getHealth() << " health.\n";

				}
			}
		}
	}
	return true;
}

void MonsterGame::endGame()
{
	//if player won
	if (m_gameWon)
	{
		std::cout << "\n\nYou won the game and reached level " << m_player.getLevel() << "!\n";
	}
	//if player lost
	else
	{
		std::cout << "\n\nYou lost the game. ";
	}
	std::cout << "\nYou gathered " << MonsterGame::m_player.getGold() << " gold and reached level " << MonsterGame::m_player.getLevel() << " with " << MonsterGame::m_player.getDamage() << " ATTACK.\n";
}


