#include "Rock.h"
#include "GameBoard.h"


Rock::Rock(sf::Vector2f pos, sf::Vector2f size)
	:StaticObject(pos, size, "Rock.png")
{
}
Rock::~Rock()
{
}

bool Rock::collide(Robot & other, GameBoard & board)
{
	return true;
}
bool Rock::collide(Explosion & other, GameBoard & board)
{
	//A collision with pizzas deletes it
	return other.collide(*this, board);
}
