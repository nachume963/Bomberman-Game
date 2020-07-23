#include "Menu.h"

#include "Exit.h"
#include "NewGame.h"
#include "ResetLevel.h"

Menu::Menu()
{
	//constructor. Initializing 3 buttons:
	//Exit
	m_buttons.push_back(std::make_unique<Exit>());
	//Reset level
	m_buttons.push_back(std::make_unique<ResetLevel>());
	//New game
	m_buttons.push_back(std::make_unique<NewGame>());
}
Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & window) const
{
	//Print all buttons
	for (int i = 0; i < m_buttons.size(); i++)
		m_buttons[i]->draw(window);
}

void Menu::click(Controller & controller, sf::Event event)
{
	//Checks whether the click was made within the borders of the menu
	if ((POSITON_MENU.x < event.mouseButton.x) && 
		(SIZE_MENU.x > event.mouseButton.x) && 
		(POSITON_MENU.y < event.mouseButton.y) && 
		(SIZE_MENU.y > event.mouseButton.y))
	{
		//Calls to the relevant function by position in the vector
		m_buttons[int((event.mouseButton.y - POSITON_MENU.y) / SIZE_BUTTON.y)]->click(controller);
	}
}

