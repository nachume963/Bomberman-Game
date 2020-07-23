#pragma once
#include "DynamicObject.h"

const float ROBOT_SPEED = 125;

class Robot : public DynamicObject
{
public:
	Robot(sf::Vector2f pos, sf::Vector2f size);
	~Robot();

	virtual void move(float deltaTime, GameBoard & board) override;

	virtual bool collide(Object & other, GameBoard & board) override;
	virtual bool collide(Robot & other, GameBoard & board) override;
	virtual bool collide(Door & other, GameBoard & board) override;
	virtual bool collide(Guard & other, GameBoard & board) override;
	virtual bool collide(Bomb & other, GameBoard & board) override;
	virtual bool collide(Gift & other, GameBoard & board) override;
	virtual bool collide(Explosion & other, GameBoard & board) override;

	static int life;
	static int score;
	static int bombs;
	static sf::Vector2f pos;
};