#include "Gift.h"
#include "GameBoard.h"


Gift::Gift(sf::Vector2f pos, sf::Vector2f size)
	:StaticObject(pos, size, "Gift.png")
{
}
Gift::~Gift()
{
}

//Collision with a player causes him to call the function again and 
//thus know which gifts to take
bool Gift::collide(Robot & other, GameBoard & board)
{
	return false;
}
bool Gift::collide(Guard & other, GameBoard & board)
{
	return false;
}


