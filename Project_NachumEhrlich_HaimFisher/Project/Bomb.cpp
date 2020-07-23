#include "Bomb.h"
#include "GameBoard.h"
#include "Controller.h"


Bomb::Bomb(sf::Vector2f pos, sf::Vector2f size)
	:StaticObject(pos, size, "Bomb_c.png"), m_stoper(0)
{
	T2.loadFromFile("Bomb_b.png");
	T3.loadFromFile("Bomb_a.png");
}
Bomb::~Bomb()
{
}

void Bomb::move(float delta, GameBoard & board)
{
	//Counts the seconds to 3
	if ((m_stoper += delta) > 1.0f)
	{
		m_object.setTexture(T2);
	}
	if ((m_stoper += delta) > 2.0f)
	{
		m_object.setTexture(T3);
	}
	if ((m_stoper += delta) > 3.0f)
	{
		//After 3 seconds the bomb is detonated
		exploded(board);
	}
}
void Bomb::exploded(GameBoard & board)
{
	Controller::sounds[0].play(); //Activates the sound of an explosion
	
	//Puts an explosion object into the clipboard
	board.setObject(m_object.getPosition(), 'E');
	//Makes the bomb inactive. From now on it will not be printed and deleted.
	m_active = false;
}
	
bool Bomb::collide(Bomb & other, GameBoard & board)
{
	//Checking whether a bomb collided with itself
	if (this == &other)
		return false;

	return false; //nothing happens
}
bool Bomb::collide(Explosion & other, GameBoard & board)
{
	return false; //nothing happens
}
