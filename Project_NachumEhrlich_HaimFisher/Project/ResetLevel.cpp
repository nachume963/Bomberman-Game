#include "ResetLevel.h"
#include "Controller.h"
#include "Robot.h"


ResetLevel::ResetLevel()
	:Button(sf::Vector2f(POSITON_MENU.x, SIZE_BUTTON.y + POSITON_MENU.y),
		sf::Vector2f(W_BUTTENS_SIZE, SIZE_BUTTON.y), "ResetLevel.png")
{
	//The second button
}
ResetLevel::~ResetLevel()
{
}

void ResetLevel::click(Controller & controller)
{
	//Repeat the step again. Player drops life in this action.
	controller.resetLevel();
}
