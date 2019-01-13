#ifndef MONSTER_HPP_
#define MONSTER_HPP_

#include "Creature.hpp"
#include <string>
#include <random>
#include <ctime>
#include <cassert>


class Monster : public Creature
{
public:
	struct MonsterData
	{
		std::string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
private:
	
	//lookup table for default monster data
	static MonsterData monsterData[MAX_TYPES];
public:

	Monster(const Type monsterType);
	Monster(const Type monsterType, const std::string &monsterName);

	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max);
	static Monster getRandomMonster();

	//output operator prints Monster stats
	friend std::ostream& operator<<(std::ostream &out, const Monster &m);

};



#endif //MONSTER_HPP_