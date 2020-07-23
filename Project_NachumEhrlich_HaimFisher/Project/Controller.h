#pragma once

#include <iostream>
#include <fstream> 
#include <string>

#include "Menu.h"
#include "GameBoard.h"

static const sf::Vector2f WINDOE_SIZE = { 1550.0 , 1000.0 };

class Controller
{
public:
	Controller();
	~Controller();

	void run();

	void finishGame();
	bool nextLevel();
	void resetLevel();

	//for music
	static sf::SoundBuffer buffers[6];
	static sf::Sound sounds[6];

private:
	void beforeGame();
	void afterGame(bool win);
	void betweenStages();

	void readFromFile(std::ifstream & in);

	void draw(sf::RenderWindow & window) const;
	void HandleEvents();

private:
	sf::RenderWindow m_window;
	std::unique_ptr<GameBoard> m_board;
	Menu m_menu;

	sf::Sprite A;
	sf::Texture T;
};