#pragma once

#include "BaseClasses/GameObject.h"
#include "CharacterStates.h"
#include "PlayerData.h"

class Dialogue : public GameObject
{

public:

	Dialogue();
	~Dialogue();

	//Bool returned to determine whether conversation has finished
	virtual bool DialogueUpdate(PlayerData* pd);

	virtual CharacterStates getCurrState(PlayerData* pd)
	{
		return CharacterStates::NEUTRAL;
	}

	virtual sf::Text* getName()
	{

		sf::Text* error = new sf::Text();
		error->setString("Error");
		error->setFont(font);
		error->setCharacterSize(36);
		return error;
	}

	virtual sf::Text* getText()
	{
		sf::Text* error = new sf::Text();
		error->setString("Error");
		error->setFont(font);
		error->setCharacterSize(36);
		return error;
	}

protected:

	int progress;

	sf::Texture textBox;
	sf::Font font;

};

