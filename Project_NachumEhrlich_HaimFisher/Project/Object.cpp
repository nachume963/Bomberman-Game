#include "Object.h"
#include "GameBoard.h"

Object::Object()
	:m_active(true)
{
}
Object::Object(sf::Vector2f pos, sf::Vector2f size, std::string name_file)
	:m_active(true) //Rebooting to be active
{
	//Inserts the correct texture
	T.loadFromFile(name_file);
	m_object.setTexture(T);
	
	//Inserting the correct position
	m_object.setPosition(pos);

	//Adjusts the correct size
	m_object.scale(sf::Vector2f(size.x / (m_object.getGlobalBounds().width + 15),
		size.y / (m_object.getGlobalBounds().width + 15)));
}
Object::~Object()
{
}

void Object::draw(sf::RenderWindow & window) const
{
	//Prints all active objects in a loop
	if(m_active)
		window.draw(m_object);
}
void Object::move(float delta, GameBoard & board)
{
	//Basic realization of a polymorphic function
	return;
}

sf::FloatRect Object::getObjectGlobalBounds()
{
	return m_object.getGlobalBounds();
}
bool & Object::getSetActive()
{
	return m_active;
}
