#pragma once
#include "Gift.h"

class LifeGift :
	public Gift
{
public:
	LifeGift(sf::Vector2f pos, sf::Vector2f size);
	~LifeGift();

	//Realization of special conflicts
	virtual bool collide(Robot & other, GameBoard & board) override;
};
