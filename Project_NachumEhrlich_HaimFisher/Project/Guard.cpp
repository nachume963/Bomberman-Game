#include "Guard.h"
#include "GameBoard.h"
#include "Controller.h"


Guard::Guard(sf::Vector2f pos, sf::Vector2f size)
	:DynamicObject(pos, size, "Guard.png")
{
}
Guard::~Guard()
{
}

void Guard::goRandomal(float delta, GameBoard & board)
{
	//Change direction every few seconds
	if (((m_change_step++) % 1000) == 0)
		ChangeDirection(delta);

	//Movement of the guard
	m_object.move(movement);
	//Check if the operation is valid
	if (!board.Collision(*this))
	{
		//If the operation is invalid, cancel the action, and change direction
		m_object.move(-movement);
		ChangeDirection(delta);
	}
}
void Guard::ChangeDirection(float delta)
{
	//Reset traffic
	movement = sf::Vector2f(0.0f, 0.0f);

	//Select a random direction
	int chois = rand() % 4;
	switch (chois)
	{
	case 0:
		//left
		movement.x -= GUARD_SPEED * delta;
		break;
	case 1:
		//down
		movement.y -= GUARD_SPEED * delta;
		break;
	case 2:
		//right
		movement.x += GUARD_SPEED * delta;
		break;
	case 3:
		//up
		movement.y += GUARD_SPEED * delta;
		break;
	default:
		break;
	}
}

bool Guard::collide(Object & other, GameBoard & board)
{
	return other.collide(*this, board);
}
bool Guard::collide(Robot & other, GameBoard & board)
{
	//Start the current phase from scratch
	board.restartLevel();
	return false;
}
bool Guard::collide(Door & other, GameBoard & board)
{
	return true;
}
bool Guard::collide(Guard & other, GameBoard & board)
{
	return false;
}
bool Guard::collide(Bomb & other, GameBoard & board)
{
	return true;
}
bool Guard::collide(Gift & other, GameBoard & board)
{
	return false;
}
bool Guard::collide(Explosion & other, GameBoard & board)
{
	return other.collide(*this, board);
}
