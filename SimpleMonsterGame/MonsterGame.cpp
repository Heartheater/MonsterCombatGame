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

bool MonsterGame::getRunOrFight()
{
	char runOrFight = 'R';
	std::cout << "\n(R)un or (F)ight? ";
	//loop until player chooses valid response
	while (true)
	{
		std::cin >> runOrFight;
		if (std::cin.fail())
		{
			std::cout << "\nPlease enter either \"R\" or \"F\" ";
			std::cin.ignore(32767, '\n');
			std::cin.clear();
		}
		else
		{
			switch (runOrFight)
			{
			case 'R':
			case 'r':
				return false;
			case 'F':
			case 'f':
				return true;
			default:
				std::cout << "\nPlease enter either \"R\" or \"F\" ";
				break;
			}
		}
	}
}


bool MonsterGame::runGame(Player &player)
{
	MenuOptions chosenOption = MenuOptions::RUN;
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

		while (playerIsFighting)
		{
			//first check if player already died
			if (player.isDead())
			{
				std::cout << "\nYou were killed by the monster!\n";
				playerIsFighting = false;
				return false;
			}

			//run the menu and take player input
			chosenOption = MonsterGame::runMenu(m);


			if (chosenOption == MenuOptions::FIGHT)
			{
				std::cout << "-------------------------------------\n";
				std::cout << "\nYou fight the " << m.getName() << ".\n";
				std::cout << "\nYou dealt " << player.getDamage() << " damage to " << m.getName();

				//decrease monsters health when player attacks
				m.reduceHealth(player.getDamage());

				//check if player won
				if (m.isDead())
				{
					std::cout << "\nYou defeated the " << m.getName() << " and got " << m.getGold() << " gold.\n";
					player.addGold(m.getGold());
					player.levelUp();
					std::cout << "\nYou leveled up to level " << player.getLevel() << "! +1ATTACK (" << player.getDamage() << ")\n";
					playerIsFighting = false;
				}
				else
				{
					//otherwise it's the monster's turn to attack
					player.reduceHealth(m.getDamage()); //player takes a hit
					std::cout << "\n" << m.getName() << " attacks!\nYou took " << m.getDamage() << " damage.";
					std::cout << "\nYou have " << player.getHealth() << " health.\n";
				}
			}

			else //player decides to run
			{	//get a random number between 1 and 2 to decide if player escapes or not
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


