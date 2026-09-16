#include "HelpButton.h"

HelpButton::HelpButton()
{
	setSize(sf::Vector2f(100.0f, 100.0f));
	setPosition(sf::Vector2f(10.0f, 10.0f));
	setCollisionBox(0, 0, 100, 100);

	buttonTexture.loadFromFile("gfx/Puzzles/helpScreens/helpButton.png");
	setTexture(&buttonTexture);
}

HelpButton::~HelpButton()
{

}

void HelpButton::update(float dt)
{

}