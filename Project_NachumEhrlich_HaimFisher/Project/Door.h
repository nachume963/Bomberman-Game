#pragma once
#include "StaticObject.h"

class Door : public StaticObject
{
public:
	Door(sf::Vector2f pos, sf::Vector2f size);
	~Door();

	virtual bool collide(Robot & other, GameBoard & board) override;
};
