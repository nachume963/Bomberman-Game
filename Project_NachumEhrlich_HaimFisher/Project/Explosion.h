#pragma once
#include "StaticObject.h"

class Explosion : public StaticObject
{
public:
	Explosion(sf::Vector2f pos, sf::Vector2f size);
	~Explosion();

	virtual void draw(sf::RenderWindow & window) const override;
	virtual void move(float delta, GameBoard & board) override;

	void loadSheet(std::vector< sf::IntRect >& m_sheet);

	virtual bool collide(Object & other, GameBoard & board) override;
	virtual bool collide(Robot & other, GameBoard & board) override;
	virtual bool collide(Rock & other, GameBoard & board) override;
	virtual bool collide(Guard & other, GameBoard & board) override;
	virtual bool collide(Bomb & other, GameBoard & board) override;

private:
	std::vector < sf::IntRect > m_sheet;
	int m_sheet_index;
	float m_sheet_time;
};
