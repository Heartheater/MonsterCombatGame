#include <iostream>
#include <string>
#include "Player.hpp"
#include "Monster.hpp"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

//returns true if 'F'ight is chosen, false if player chooses 'R'un
bool getPlayerInput()
{
	char runOrFight = 'R';
	std::cout << "\n(R)un or (F)ight? ";
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


//returns true if player won, false if player dies
bool runGame(Player &player)
{
	bool choosesToFight = false;
	bool playerIsFighting = false;

	//game loops until player wins or dies
	while(!player.hasWon())
	{
		//generate monster
		Monster m = Monster::getRandomMonster();
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") appears.\n";
		std::cout << m;
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

			//ask if player wants to run or fight monster
			choosesToFight = getPlayerInput();

			if (choosesToFight)
			{
				std::cout << "\nYou fight the " << m.getName() << ".\n";
				std::cout << "\nYou dealt " << player.getDamage() << " damage to " << m.getName();

				//decrease monsters health when player attacks
				m.reduceHealth(player.getDamage());
				std::cout << m;


				//check if player won
				if (m.isDead())
				{
					std::cout << "\nYou defeated the " << m.getName() << " and got " << m.getGold() << " gold.\n";
					player.addGold(m.getGold());
					player.levelUp();
					std::cout << "\nYou leveled up to level "<< player.getLevel() <<"! +1ATTACK ("<< player.getDamage() << ")\n";
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


int main()
{
	std::cout << "Enter your name: ";
	std::string playerName = "";
	std::cin >> playerName;

	//create new player with the input name
	Player p1 = playerName;
	std::cout << "Welcome, " << p1.getName() << ".";
	std::cout << p1 << "\n";

	//for generating random numbers
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // get rid of first result

	//run game
	bool result = runGame(p1);
	//if player won
	if(result)
	{
		std::cout << "\n\nYou won the game by reaching level 20!";
	}
	//if player lost
	else
	{
		std::cout << "\n\nYou lost the game. ";
	}
	std::cout << "\nYou gathered " << p1.getGold() << " gold and reached level " << p1.getLevel() << " with "<<p1.getDamage() <<" ATTACK.\n";


	int wait = 0;
	std::cin >> wait;

	return 0;
}



