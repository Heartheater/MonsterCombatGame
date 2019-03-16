#ifndef MONSTER_HPP_
#define MONSTER_HPP_

#include "Creature.hpp"
#include <string>
#include <random>
#include <ctime>
#include <cassert>


class Monster final : public Creature
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
		MIDGET_BLOB,
		ELF_MIDGET,
		SLIME,
		RUGBY,
		EVAN,
		BARFY,
		SANES,
		MAX_TYPES
	};
	enum Item
	{
		POTION,
		MAX_ITEMS
	};
private:
	
	//lookup table for default monster data
	static MonsterData monsterData[MAX_TYPES];

	Item m_heldItem = Monster::Item::MAX_ITEMS;
	bool m_isHoldingItem;
	Monster::Item getRandomItem();
public:

	Monster(const Type monsterType);
	Monster(const Type monsterType, const std::string &monsterName);

	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max);
	static Monster getRandomMonster();

	const bool checkHasItem() const;
	const Item& getItem() const;

	void printItem() const;

	void printAllStats() const;
	//output operator prints Monster name and health
	friend std::ostream& operator<<(std::ostream &out, const Monster &m);
};



#endif //MONSTER_HPP_