#include "Creature.hpp"



Creature::Creature(const std::string &name, const char symbol, const int health, const int damage, const int gold)
	: m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_goldCarried{gold}, m_baseHealth{health}
{

}

const std::string& Creature::getName() const
{
	return m_name;
}

const char Creature::getSymbol() const
{
	return m_symbol;
}

const int Creature::getHealth() const
{
	return m_health;
}

void Creature::addHealth(const int amount)
{
	if (amount > 0) 
	{ //add health up to the starting base health
		if ((m_health + amount) <= m_baseHealth)
			m_health += amount;
		else
			m_health = m_baseHealth;
	}
}

const int Creature::getDamage() const
{
	return m_damage;
}

const int Creature::getGold() const
{
	return m_goldCarried;
}

void Creature::reduceHealth(const int damage)
{
	m_health -= damage;
}

bool Creature::isDead() const
{
	if (m_health <= 0)
	{
		return true;
	}
	return false;
}

void Creature::addGold(const int amount)
{
	m_goldCarried += amount;
}

void Creature::increaseDamage(const int amount)
{
	m_damage += amount;
}

void Creature::printAllStats() const
{
	std::cout << "\n    " << m_name << "\n";
	std::cout << "\tHEALTH: " << m_health;
	std::cout << "\n\tATTACK: " << m_damage;
	std::cout << "\n\tGOLD: " << m_goldCarried << "\n";
}