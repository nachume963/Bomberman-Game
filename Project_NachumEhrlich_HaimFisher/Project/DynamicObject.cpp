#include "DynamicObject.h"



DynamicObject::DynamicObject()
{
}
DynamicObject::DynamicObject(sf::Vector2f pos, sf::Vector2f size, std::string name_file)
	:Object(pos, size, name_file)
{
}
DynamicObject::~DynamicObject()
{
}


bool DynamicObject::collide(Wall & other, GameBoard & board)
{
	return true;
}
bool DynamicObject::collide(Rock & other, GameBoard & board)
{
	return true;
}
