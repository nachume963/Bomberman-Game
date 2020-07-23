#pragma once
#include "Guard.h"

class FoolGuard : public Guard
{
public:
	FoolGuard(sf::Vector2f pos, sf::Vector2f size);
	~FoolGuard();

	void move(float delta, GameBoard & board);
};
