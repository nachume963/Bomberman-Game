#include "Button.h"



Button::Button()
{
}
Button::Button(sf::Vector2f pos, sf::Vector2f size, std::string name_file)
{
	//Inserts the correct texture
	T.loadFromFile(name_file);
	m_button.setTexture(T);

	//Inserting the correct position
	m_button.setPosition(pos);
	
	//Adjusts the correct size
	m_button.scale(size.x / m_button.getGlobalBounds().width,
		size.y / m_button.getGlobalBounds().height);
}
Button::~Button()
{
}

void Button::draw(sf::RenderWindow & window) const
{
	//print
	window.draw(m_button);
}

