#include "NewGame.h"
#include "Controller.h"
#include "GameBoard.h"

NewGame::NewGame()
	:Button(sf::Vector2f(POSITON_MENU.x, 2 * SIZE_BUTTON.y + POSITON_MENU.y),
		sf::Vector2f(W_BUTTENS_SIZE, SIZE_BUTTON.y), "NewGame.png")
{
	//The third button
}
NewGame::~NewGame()
{
}

void NewGame::click(Controller & controller)
{
	//Starts the game from scratch
	Robot::life = 5; //Updating the player's life
	controller.run(); //Calls the function that starts the game. Makes a loop
}
