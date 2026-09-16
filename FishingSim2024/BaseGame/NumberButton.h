#pragma once

#include "BaseClasses/GameObject.h"

class NumberButton : public GameObject
{
public:

	NumberButton();
	~NumberButton();

	void update(float dt) override;
	void handleInput(float dt) override;

	void setValue(int i)
	{
		value = i;
		buttonText.setString(std::to_string(value));
	}

	sf::Text getText()
	{
		return buttonText;
	}

	void setTextPos(sf::Vector2f pos)
	{
		buttonText.setPosition(pos);
	}

	void incrementValue()
	{
		value++;
		if (value > 9)
		{
			value = 1;
		}

		buttonText.setString(std::to_string(value));
	}

	void setLocked(bool l)
	{
		locked = l;

		if (locked = true)
		{
			buttonTexture.loadFromFile("gfx/puzzles/lockedButton.png");
			setTexture(&buttonTexture);
		}
	}

	bool getLocked()
	{
		return locked;
	}

	int getValue()
	{
		return value;
	}

private:

	sf::Texture buttonTexture;
	sf::Text buttonText;
	sf::Font font;
	int value;
	bool locked;

};
