#include "Player.hpp"



Player::Player(const std::string& playerName)
	: Creature(playerName, '@', 10, 1), m_level{1}
{
}

void Player::levelUp()
{
	m_level += 1;
	increaseDamage(1);
}

const int Player::getLevel() const
{
	return m_level;
}

bool Player::hasWon() const
{
	if (m_level >= 20)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream &out, const Player &p)
{
	out << "\nLevel (" << p.getLevel() << ") You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold\n";
	return out;
}