#pragma once
#include "Object.h"

class DynamicObject : public Object
{
public:
	DynamicObject();
	DynamicObject(sf::Vector2f pos, sf::Vector2f size, std::string name_file);
	virtual ~DynamicObject();

	//General collisions for guard and robot
	virtual bool collide(Wall & other, GameBoard & board) override;
	virtual bool collide(Rock & other, GameBoard & board) override;
};