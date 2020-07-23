#pragma once
#include "Button.h"

class ResetLevel : public Button
{
public:
	ResetLevel();
	~ResetLevel();

	virtual void click(Controller & controller);
};

