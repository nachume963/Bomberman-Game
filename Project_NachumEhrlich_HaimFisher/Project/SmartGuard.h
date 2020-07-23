#pragma once
#include "Guard.h"

class SmartGuard : public Guard
{
public:
	SmartGuard(sf::Vector2f pos, sf::Vector2f size);
	~SmartGuard();


	void move(float delta, GameBoard & board);
	bool goToRobot(float delta, GameBoard & board);

	virtual bool collide(Guard & other, GameBoard & board) override;

private:
	bool m_smart;
	int wait_a_second = 1;
};
