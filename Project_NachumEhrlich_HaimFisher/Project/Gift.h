#pragma once
#include "StaticObject.h"

class Gift : public StaticObject
{
public:
	Gift(sf::Vector2f pos, sf::Vector2f size);
	virtual ~Gift();

	//Realization of special conflicts
	virtual bool collide(Robot & other, GameBoard & board) override;
	virtual bool collide(Guard & other, GameBoard & board) override;
};
