#include "NumberButton.h"

NumberButton::NumberButton()
{

	font.loadFromFile("font/arial.ttf");
	buttonText.setFont(font);
	buttonText.setCharacterSize(48);
	buttonText.setPosition(sf::Vector2f(0.0f, 0.0f));
	buttonText.setFillColor(sf::Color::Black);
	buttonText.setFont(font);

	buttonTexture.loadFromFile("gfx/puzzles/button.png");
	setTexture(&buttonTexture);

	buttonText.setPosition(sf::Vector2f(15.0f, 15.0f));

	setSize(sf::Vector2f(120.0f, 120.0f));
	setCollisionBox(0, 0, 120, 120);

	value = 0;
	locked = false;

	buttonText.setString(std::to_string(0));
}

NumberButton::~NumberButton()
{

}

void NumberButton::update(float dt)
{

}

void NumberButton::handleInput(float dt)
{

}