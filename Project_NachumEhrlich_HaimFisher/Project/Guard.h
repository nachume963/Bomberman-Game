#pragma once
#include "DynamicObject.h"

//Speed of movement of the guard
const int GUARD_SPEED = 100;

class Guard : public DynamicObject
{
public:
	Guard(sf::Vector2f pos, sf::Vector2f size);
	virtual ~Guard();

	void goRandomal(float delta, GameBoard & board);
	void ChangeDirection(float delta);

	//Conflicts with a guard
	virtual bool collide(Object & other, GameBoard & board) override;
	virtual bool collide(Robot & other, GameBoard & board) override;
	virtual bool collide(Door & other, GameBoard & board) override;
	virtual bool collide(Guard & other, GameBoard & board) override;
	virtual bool collide(Bomb & other, GameBoard & board) override;
	virtual bool collide(Gift & other, GameBoard & board) override;
	virtual bool collide(Explosion & other, GameBoard & board) override;

protected:
	sf::Vector2f movement;
	int m_change_step;
};