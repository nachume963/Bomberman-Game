#pragma once
#include "StaticObject.h"

class Bomb : public StaticObject
{
public:
	Bomb(sf::Vector2f pos, sf::Vector2f size);
	~Bomb();

	virtual void move(float delta, GameBoard & board);
	//Explosion of the bomb
	void exploded(GameBoard & board);

	//Realization of special conflicts
	virtual bool collide(Bomb & other, GameBoard & board) override;
	virtual bool collide(Explosion & other, GameBoard & board) override;

private:
	//Counts 3 seconds
	float m_stoper;
	
	sf::Texture T1, T2, T3;
};
