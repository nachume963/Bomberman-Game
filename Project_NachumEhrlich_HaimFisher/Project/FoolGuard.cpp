#include "FoolGuard.h"
#include "GameBoard.h"


FoolGuard::FoolGuard(sf::Vector2f pos, sf::Vector2f size)
	:Guard(pos, size)
{
	//Start of the guard's movement
	ChangeDirection(0.004f);
}
FoolGuard::~FoolGuard()
{
}

void FoolGuard::move(float delta, GameBoard & board)
{
	//A random movement of a guard. Not smart
	goRandomal(delta, board);
}

