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

	enum Actions
	{
		RUN,
		FIGHT,
		MAX_OPTIONS
	};
public:
	//initialize MonsterGame with a Player
	MonsterGame(Player &players);

	//initialize MonsterGame with a string name 
	MonsterGame(const std::string &playerName);
	//print out the menu and options
	void printMenu() const;

private:
	void startGame();

	//listens for and handles user input for menu options
	Actions getMenuInput(const Monster &m);

	//returns true if player won, false if player dies
	bool runGame(Player &player);
	void endGame();
	void printUniqueDialogue(Monster &m);

};

#endif //MONSTER_GAME_HPP_
