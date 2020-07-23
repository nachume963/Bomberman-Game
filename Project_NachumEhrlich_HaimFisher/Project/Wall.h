#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(sf::Vector2f pos, sf::Vector2f size);
	~Wall();

	virtual bool collide(Robot & other, GameBoard & board) override;
};
