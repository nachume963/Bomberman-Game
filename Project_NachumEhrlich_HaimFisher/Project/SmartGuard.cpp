#include "SmartGuard.h"
#include "GameBoard.h"

SmartGuard::SmartGuard(sf::Vector2f pos, sf::Vector2f size)
	:Guard(pos, size), m_smart(false)
{
	//Start of the guard's movement
	ChangeDirection(0.004f);
}
SmartGuard::~SmartGuard()
{
}

void SmartGuard::move(float delta, GameBoard & board)
{
	if (m_smart) //Smart mode
	{
		//A function that leads the guard towards the player
		if (goToRobot(delta, board))
			return;
		
		//If he got here, you'd go into a stupid situation
		m_smart = false;
	}
	if (!m_smart) //Stupid state
	{
		//Stay in a stupid position for a few seconds
		if (((wait_a_second++) % 500) == 0)
			m_smart = true;
	
		//Go in a random way
		goRandomal(delta, board);
	}
}
bool SmartGuard::goToRobot(float delta, GameBoard & board)
{
	//Reset traffic
	movement = sf::Vector2f(0.0f, 0.0f);

	//The distance between the guard and the player in x
	int dis_x = int(Robot::pos.x - m_object.getPosition().x);
	
	//If there is a lateral distance
	if (dis_x)
	{
		//Making a move in the right direction
		movement.x = (Robot::pos.x - m_object.getPosition().x)
			/ abs(Robot::pos.x - m_object.getPosition().x) * GUARD_SPEED * delta;
	
		m_object.move(movement);
	}
	//If there is no lateral distance, or the traffic is invalid
	if(!dis_x || !board.Collision(*this))
	{	
		//Cancel traffic (or traffic is 0)
		m_object.move(-movement);

		//Makes movement in y direction
		movement.y = (Robot::pos.y - m_object.getPosition().y)
			/ abs(Robot::pos.y - m_object.getPosition().y) * GUARD_SPEED * delta;

		m_object.move(movement);
	}
	//If the invalid traffic will cancel and return false
	if (!board.Collision(*this))
	{
		m_object.move(-movement);
		return false;
	}
	//If all good returns true
	return true;
}

bool SmartGuard::collide(Guard & other, GameBoard & board)
{
	//Makes sure there are not 2 smart guards on the same place
	if(this == &other)
		return false;

	return true;
}
