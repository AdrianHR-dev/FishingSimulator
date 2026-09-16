#include "Input.h"

Input::Input()
{
	//Default mouse values set
	left = MouseState::UP;
	right = MouseState::UP;
	mouseX = 0;
	mouseY = 0;
}

//Update, a classic function
//Who doesn't love a good update function?
void Input::update()
{
	//All 'pressed' keys returned to standard state
	for (int i = 0; i < pressed.size(); i++)
	{
		setKeyUp(pressed[i]);
	}
	pressed.clear();

	//Mouse is set to appropriate state based on which button pressed
	if (left == MouseState::PRESSED)
	{
		left = MouseState::DOWN;
	}
	if (right == MouseState::PRESSED)
	{
		right = MouseState::DOWN;
	}
}

void Input::setKeyDown(int key)
{
	//Sets given key... DOWN!
	if (key >= 0)
	{
		keys[key] = true;
	}
}

void Input::setKeyUp(int key)
{
	//Sets given key... NOT DOWN! (up)
	if (key >= 0)
	{
		keys[key] = false;
	}
}

bool Input::isKeyDown(int key)
{
	//Finds given key state and returns it
	if (key >= 0)
	{
		return keys[key];
	}
	return false;
}
bool Input::isKeyPressed(int key)
{
	//If key pressed, added to pressed vector
	bool cond = isKeyDown(key);
	if (cond)
	{
		pressed.push_back(key);
		return cond;
	}
	return false;
}

void Input::setMouseX(int mx)
{
	//Sets x
	mouseX = mx;
}

void Input::setMouseY(int my)
{
	//Sets y
	mouseY = my;
}


int Input::getMouseX()
{
	//Returns x
	return mouseX;
}

int Input::getMouseY()
{
	//Returns y
	return mouseY;
}

void Input::setLeftMouse(MouseState state)
{
	//Sets left mouse
	left = state;
}


void Input::setRightMouse(MouseState state)
{
	//Sets right mouse
	right = state;
}

bool Input::isLeftMouseDown()
{
	//Gets leftmouse state
	if (left == MouseState::DOWN)
	{
		return true;
	}
	return false;
}

bool Input::isRightMouseDown()
{
	//Gets right mouse state
	if (right == MouseState::DOWN)
	{
		return true;
	}
	return false;
}


