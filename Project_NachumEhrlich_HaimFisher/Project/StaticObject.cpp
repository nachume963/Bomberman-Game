#include "StaticObject.h"


StaticObject::StaticObject()
{
}
StaticObject::StaticObject(sf::Vector2f pos, sf::Vector2f size, std::string name_file)
	:Object(pos, size, name_file)
{
}
StaticObject::~StaticObject()
{
}


bool StaticObject::collide(Object & other, GameBoard & board)
{
	//Can not be a dynamic object collision
	return false;
}
bool StaticObject::collide(Robot & other, GameBoard & board)
{
	//General realization
	return false;
}
bool StaticObject::collide(Door & other, GameBoard & board)
{
	//General realization
	return false;
}
bool StaticObject::collide(Wall & other, GameBoard & board)
{
	//General realization
	return false;
}
bool StaticObject::collide(Rock & other, GameBoard & board)
{
	//General realization
	return false;
}
bool StaticObject::collide(Guard & other, GameBoard & board)
{
	//General realization
	return true;
}
bool StaticObject::collide(Bomb & other, GameBoard & board)
{
	//General realization
	return false;
}
bool StaticObject::collide(Gift & other, GameBoard & board)
{
	//General realization
	return false;
}
bool StaticObject::collide(Explosion & other, GameBoard & board)
{
	//General realization
	return false;
}
