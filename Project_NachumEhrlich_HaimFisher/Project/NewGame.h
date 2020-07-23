#pragma once
#include "Button.h"

class NewGame : public Button
{
public:
	NewGame();
	~NewGame();

	virtual void click(Controller & controller);

};

