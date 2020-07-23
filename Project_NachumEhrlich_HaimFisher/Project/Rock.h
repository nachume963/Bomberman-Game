#pragma once
#include "StaticObject.h"

class Rock : public StaticObject
{
public:
	Rock(sf::Vector2f pos, sf::Vector2f size);
	~Rock();

	//Realization of special conflicts
	virtual bool collide(Robot & other, GameBoard & board) override;
	virtual bool collide(Explosion & other, GameBoard & board) override;
};
