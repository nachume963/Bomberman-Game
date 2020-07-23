#pragma once
#include "Gift.h"

class BombGift : public Gift
{
public:
	BombGift(sf::Vector2f pos, sf::Vector2f size);
	~BombGift();

	//Realization of special conflicts
	virtual bool collide(Robot & other, GameBoard & board) override;
};
