#ifndef CREATURE_HPP_
#define CREATURE_HPP_

#include <iostream>
#include <string>

class Creature
{
private:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_goldCarried;

protected:
	void increaseDamage(const int amount);
	void addHealth(const int amount);

	//make constructor protected so only derived classes can be created
	Creature(const std::string &name, const char symbol, const int health = 1, const int damage = 1, const int gold = 0);

public:
	const int m_baseHealth;

	const std::string& getName() const;
	const char getSymbol() const;

	//returns current health of creature
	const int getHealth() const;

	//returns amount of damage per hit
	const int getDamage() const;

	//return amount of gold currently carried
	const int getGold() const;

	void reduceHealth(const int damage = 1);

	bool isDead() const;

	void addGold(const int amount);
	void printAllStats() const;

};

#endif //CREATURE_HPP_


