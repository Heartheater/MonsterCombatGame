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


