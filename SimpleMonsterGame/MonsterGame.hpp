#ifndef MONSTER_GAME_HPP_
#define MONSTER_GAME_HPP_
#include "Player.hpp"
#include "Monster.hpp"
#include <iostream>
class MonsterGame
{
private:
	bool m_gameWon;
	Player m_player;

	enum MenuOptions
	{
		RUN,
		FIGHT,
		MONSTER_STATS,
		PLAYER_STATS,
		MAX_OPTIONS
	};
public:
	//initialize MonsterGame with a Player
	MonsterGame(Player &players);

	//initialize MonsterGame with a string name 
	MonsterGame(const std::string &playerName);

	void startGame();

	//returns true if (F)ight is chosen, false if player chooses (R)un
	bool getRunOrFight();

	MenuOptions runMenu(const Monster &m)
	{
		char input = 0;

		MenuOptions chosenOption = MenuOptions::RUN;
		std::cout << "\nMenu Options: ";
		std::cout << "\n\t(R)un \n\t(F)ight \n\t(M)onster Status\n\t(P)layer Status.";
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
					chosenOption = MenuOptions::RUN;
					return chosenOption;
				case 'F':
				case 'f':
					chosenOption = MenuOptions::FIGHT;
					return chosenOption;
				case 'M':
				case 'm':
					chosenOption = MenuOptions::MONSTER_STATS;
					//print Monster's Stats
					m.printAllStats();
					break;
				case 'P':
				case 'p':
					chosenOption = MenuOptions::PLAYER_STATS;
					m_player.printAllStats();
					break;
				case 'H':
				case 'h':
					std::cout << "Please type a single letter R, F, M, or P and hit enter to proceed.\nLetters may also be in lowercase.\n";
					break;
				default:
					std::cout << "\nPlease enter a valid menu option. Enter 'h' for help.";
					break;
				}
			}
		}


	}

	//returns true if player won, false if player dies
	bool runGame(Player &player);
	void endGame();
	
};

#endif //MONSTER_GAME_HPP_
