#pragma once

#include <sstream>
#include <iostream>
#include <vector>

#include "Robot.h"
#include "SmartGuard.h"
#include "FoolGuard.h"
#include "Rock.h"
#include "Wall.h"
#include "Door.h"
#include "LifeGift.h"
#include "BombGift.h"
#include "Bomb.h"
#include "Explosion.h"

static const sf::Vector2f BOARD_SIZE = { 1350.0, 900.0 };
static const sf::Vector2f POSITON_BOARD = { 200.0, 0.0 };//posion on screen

class GameBoard
{
public:
	GameBoard(std::vector<std::string> & matrix_board);
	~GameBoard();

	void Moves(sf::Clock & clock);//move objects
	void setObject(sf::Vector2f pos, char c);//set obgects from ascii to memory (vector)

	void draw(sf::RenderWindow & window) const;
	bool Collision(Object & object);//Checks collision with other objects

	void restartLevel();
	void moveToNextLevel();
	bool nextLevel() const;

	void timeLimit(float delta);
	void setScore(bool finis_level);

	static int level_number;
	static float timer;

private:
	void drawData(sf::RenderWindow & window) const;//print data line under board
	void setBoard();//Organized board

//members...
	std::vector<std::string> m_matrix_board;//olde the ascii 

	sf::Vector2f m_object_size;
	int m_num_guards, m_bombs_limit;
	bool m_next_level;

	std::vector <std::unique_ptr<Object>> m_objects;//olde the data
};
