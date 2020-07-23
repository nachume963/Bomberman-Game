#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#ifdef _DEBUG 
#pragma comment ( lib , "sfml-main-d.lib" ) 
#pragma comment ( lib , "sfml-system-d.lib" ) 
#pragma comment ( lib , "sfml-window-d.lib" ) 
#pragma comment ( lib , "sfml-graphics-d.lib" ) 
#elif defined (NDEBUG) 
#pragma comment ( lib , "sfml-main.lib" ) 
#pragma comment ( lib , "sfml-system.lib" ) 
#pragma comment ( lib , "sfml-window.lib" ) 
#pragma comment ( lib , "sfml-graphics.lib" ) 
#else 
#error "Unrecognized configuration!" 

#endif 

class Controller;

class Button
{
public:
	Button();
	Button(sf::Vector2f pos, sf::Vector2f size, std::string name_file);
	virtual ~Button();

	void draw(sf::RenderWindow & window) const;

	//Pure virtual function
	virtual void click(Controller & controller) = 0;

protected:
	sf::Sprite m_button;
	sf::Texture T;
};

