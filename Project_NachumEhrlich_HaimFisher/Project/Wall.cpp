#include "Wall.h"
#include "GameBoard.h"


Wall::Wall(sf::Vector2f pos, sf::Vector2f size)
	:StaticObject(pos, size, "Wall.png")
{
}
Wall::~Wall()
{
}


bool Wall::collide(Robot & other, GameBoard & board)
{
	return true;
}