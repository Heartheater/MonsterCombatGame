#include "Monster.hpp"

#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
Monster::Monster(const Type monsterType = Monster::SLIME)
	: Creature(monsterData[monsterType].name, monsterData[monsterType].symbol, monsterData[monsterType].health, monsterData[monsterType].damage, monsterData[monsterType].gold)
{

}

Monster::Monster(const Type monsterType, const std::string &monsterName)
	: Creature(monsterName, monsterData[monsterType].symbol, monsterData[monsterType].health, monsterData[monsterType].damage, monsterData[monsterType].gold)
{

}


Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{"dragon", 'D', 20, 4, 100 },
	{"orc", 'o', 4, 2, 25 },
	{"slime", 's', 1, 1, 10 },
};



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
