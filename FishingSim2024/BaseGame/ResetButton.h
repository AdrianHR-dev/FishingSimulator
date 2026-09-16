#pragma once

#include "MenuButton.h"

class ResetButton : public MenuButton
{
public:

	//Public member functions
	ResetButton();
	~ResetButton();

	void update(float dt);

	void collisionResponse();

private:
	//Private member variables

};
