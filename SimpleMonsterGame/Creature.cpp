#include "Creature.hpp"



Creature::Creature(const std::string &name, const char symbol, const int health, const int damage, const int gold)
	: m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_goldCarried{gold}
{

}


Creature::~Creature()
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
