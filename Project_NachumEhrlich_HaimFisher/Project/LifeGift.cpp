#include "LifeGift.h"
#include "GameBoard.h"


LifeGift::LifeGift(sf::Vector2f pos, sf::Vector2f size)
	:Gift(pos, size)
{
}
LifeGift::~LifeGift()
{
}

bool LifeGift::collide(Robot & other, GameBoard & board)
{
	//A gift of life
	//A player who receives such a gift adds more life
	if (m_active)
	{
		Robot::life++;
		m_active = false;
	}
	return false;
}
