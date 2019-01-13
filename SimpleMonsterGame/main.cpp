#include <iostream>
#include <string>
#include "MonsterGame.hpp"
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int main()
{
	//for generating random numbers
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // get rid of first result

	std::cout << "Enter your name: ";
	std::string playerName = "";
	std::cin >> playerName;

	MonsterGame game = playerName;


	int wait = 0;
	std::cin >> wait;

	return 0;
}


/*
	TODO:
	-Put game functionality into MonsterGame class
	-Create Menu that takes input each turn, including selecting Run or Fight,
		and can also select player stats to view player's current stats

	-Create random Item drops
	-Maybe a shop to buy item(s) using gold?
	-Make different areas in the game?
	-Make game harder (maybe you have to reach lvl 100 or something)

*/