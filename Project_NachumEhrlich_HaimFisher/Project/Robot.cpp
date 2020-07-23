#include "Robot.h"
#include "GameBoard.h"

int Robot::life = 5;//init static int
int Robot::score = 0;//init static int
int Robot::bombs = 0;//init static int
sf::Vector2f Robot::pos = { 0.0 , 0.0 };

Robot::Robot(sf::Vector2f pos, sf::Vector2f size)
	:DynamicObject(pos, size, "Robot.png")
{
}
Robot::~Robot()
{
}


void Robot::move(float deltaTime, GameBoard & board)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		movement.x -= ROBOT_SPEED * deltaTime;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		movement.y -= ROBOT_SPEED * deltaTime;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		movement.x += ROBOT_SPEED * deltaTime;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		movement.y += ROBOT_SPEED * deltaTime;

	m_object.move(movement);
		if (!board.Collision(*this))
			m_object.move(-movement);

	Robot::pos = m_object.getPosition();
}

bool Robot::collide(Object & other, GameBoard & board)
{
	return other.collide(*this, board);
}
bool Robot::collide(Robot & other, GameBoard & board)
{
	return false;
}
bool Robot::collide(Door & other, GameBoard & board)
{
	return other.collide(*this, board);
}
bool Robot::collide(Guard & other, GameBoard & board)
{
	board.restartLevel();
	return false;
}
bool Robot::collide(Bomb & other, GameBoard & board)
{
	return false;
}
bool Robot::collide(Gift & other, GameBoard & board)
{
	//Sends to a gift, and there using polymorphism 
	//he knows what gift to take.
	return other.collide(*this, board);
}
bool Robot::collide(Explosion & other, GameBoard & board)
{
	return other.collide(*this, board);
}



