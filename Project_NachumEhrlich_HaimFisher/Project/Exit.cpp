#include "Exit.h"
#include "Controller.h"


Exit::Exit()
	:Button(POSITON_MENU, sf::Vector2f(W_BUTTENS_SIZE, SIZE_BUTTON.y), "Exit.png")
{
	//The first button
}
Exit::~Exit()
{
}

void Exit::click(Controller & controller)
{
	//Exit the game
	controller.finishGame();
}
