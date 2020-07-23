#include "Door.h"
#include "GameBoard.h"


Door::Door(sf::Vector2f pos, sf::Vector2f size)
	:StaticObject(pos, size, "Door.png")
{
}
Door::~Door()
{
}

bool Door::collide(Robot & other, GameBoard & board)
{
	//Meeting a robot with a door causes a phase transition
	board.moveToNextLevel();
	return false;
}
