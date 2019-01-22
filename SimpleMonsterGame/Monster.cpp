#include "Monster.hpp"

#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
Monster::Monster(const Type monsterType = Monster::SLIME)
	: Creature(monsterData[monsterType].name, 
		monsterData[monsterType].symbol, 
		monsterData[monsterType].health, 
		monsterData[monsterType].damage, 
		monsterData[monsterType].gold),
		m_isHoldingItem{ false }
{
	//random chance to have a held item
	if (Monster::getRandomNumber(1, 3) == 2)
	{
		m_isHoldingItem = true;
		m_heldItem = getRandomItem();
	}
}

Monster::Monster(const Type monsterType, const std::string &monsterName)
	: Creature(monsterName, 
		monsterData[monsterType].symbol, 
		monsterData[monsterType].health, 
		monsterData[monsterType].damage, 
		monsterData[monsterType].gold),
		m_isHoldingItem{false} 
{	
	//random chance to have a held item
	if (Monster::getRandomNumber(1, 3) == 2)
	{
		m_isHoldingItem = true;
		m_heldItem = getRandomItem();
	}
}


Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{	//name, symbol, health, damage, gold
	{"dragon", 'D', 20, 4, 100 },
	{"orc", 'o', 4, 2, 25 },
	{"slime", 's', 1, 1, 10 },
};


Monster::Item Monster::getRandomItem()
{
	return static_cast<Monster::Item>(Monster::getRandomNumber(0, (MAX_ITEMS - 1)));
}

int Monster::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


Monster Monster::getRandomMonster()
{
	return Monster(static_cast<Monster::Type>(Monster::getRandomNumber(0, (MAX_TYPES - 1))));
}


std::ostream& operator<<(std::ostream &out, const Monster &m)
{
	out << "\n\n     " << m.getName() << "  HEALTH: " << m.getHealth() << "\n";
	return out;
}

void Monster::printItem() const
{
	switch (m_heldItem)
	{
	case Item::POTION:
		std::cout << "Potion";
		break;
	default:
		std::cout << "Nothing";
	}
}


const bool Monster::checkHasItem() const
{
	return m_isHoldingItem;
}
const Monster::Item& Monster::getItem() const
{
	return m_heldItem;
}

void Monster::printAllStats() const
{
	std::cout << "\n    " << getName() << "\n";
	std::cout << "\tHEALTH: " << getHealth();
	std::cout << "\n\tATTACK: " << getDamage();
	std::cout << "\n\tGOLD: " << getGold() << "\n";
	if (m_isHoldingItem)
	{
		std::cout << "\tITEM: ";
		printItem();
		std::cout << "\n";
	}
}