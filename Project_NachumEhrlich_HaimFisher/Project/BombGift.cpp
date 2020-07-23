#include "BombGift.h"
#include "GameBoard.h"


BombGift::BombGift(sf::Vector2f pos, sf::Vector2f size)
	:Gift(pos, size)
{
}
BombGift::~BombGift()
{
}

bool BombGift::collide(Robot & other, GameBoard & board)
{
	//A gift of bombs
	//In case there is a limit of such gift bombs adds another 3
	if (m_active)
	{
		if (Robot::bombs > 0)
			Robot::bombs += 3;
		m_active = false;
	}
	return false;
}
