#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Creature.hpp"

class Player : public Creature
{
private:
	int m_level;
	const int m_playerBaseHealth = 10;
public:
	Player(const std::string& playerName);
	~Player();

	void levelUp();
	const int getLevel() const;
	//check if the player has won. Returns true if player reached level 20
	bool hasWon() const;
	friend std::ostream& operator<<(std::ostream &out, const Player &p);
};

#endif //PLAYER_HPP_
