#pragma once
#include "Object.h"

class StaticObject : public Object
{
public:
	StaticObject();
	StaticObject(sf::Vector2f pos, sf::Vector2f size, std::string name_file);
	virtual  ~StaticObject();

	//Realization of all virtual functions
	virtual bool collide(Object & other, GameBoard & board) override;
	virtual bool collide(Robot & other, GameBoard & board) override;
	virtual bool collide(Door & other, GameBoard & board) override;
	virtual bool collide(Wall & other, GameBoard & board) override;
	virtual bool collide(Rock & other, GameBoard & board) override;
	virtual bool collide(Guard & other, GameBoard & board) override;
	virtual bool collide(Bomb & other, GameBoard & board) override;
	virtual bool collide(Gift & other, GameBoard & board) override;
	virtual bool collide(Explosion & other, GameBoard & board) override;
};
