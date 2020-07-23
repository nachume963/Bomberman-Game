#pragma once

#include <vector>
#include "Button.h"


const float W_BUTTENS_SIZE = 200;//The width of a button
const int NUM_OF_BUTTENS = 3;//Number of buttons
const sf::Vector2f POSITON_MENU = { 0, 0 };
const sf::Vector2f SIZE_BUTTON = { W_BUTTENS_SIZE, 900.0 / NUM_OF_BUTTENS };
const sf::Vector2f SIZE_MENU = { W_BUTTENS_SIZE, 900.0 };

class Menu
{
public:
	Menu();
	~Menu();

	void draw(sf::RenderWindow & window) const;
	
	//Function that activates the function by pressing the button
	void click(Controller & controller, sf::Event event);

private:
	//Vector of pointers to buttons
	std::vector <std::unique_ptr<Button>> m_buttons;
};

