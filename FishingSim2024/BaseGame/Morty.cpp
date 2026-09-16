#include "Morty.h"

Morty::Morty()
{
	charTexture.loadFromFile("gfx/Characters/morty/morty.png");
	setTexture(&charTexture);

	//Character positions set
	setSize(sf::Vector2f(400, 445));
	setPosition(sf::Vector2f(-30.0f, 250.0f));
	setCollisionBox(14, 0, 100, 445);

	//Initialise different character frames
	//216x233

	distance.addFrame(sf::IntRect(0, 0, 216, 233));
	smile.addFrame(sf::IntRect(0, 233, 173, 243));
	blank.addFrame(sf::IntRect(0, 0, 1, 1));

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	charName = CharacterName::MORTY;

	talking = false;
}

Morty::~Morty()
{

}

void Morty::update(float dt)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		//Character positions set
		setSize(sf::Vector2f(440, 445));
		setPosition(sf::Vector2f(-30.0f, 250.0f));
		setCollisionBox(14, 0, 100, 445);
	}
}

void Morty::handleInput(float dt)
{

}

bool Morty::interact(PlayerData* pd)
{
	talking = true;

	setSize(sf::Vector2f(360.0, 504.0f));
	setPosition(sf::Vector2f(100.0f, 100.0f));

	mortyDialogue.setAlive(true);

	if (mortyDialogue.DialogueUpdate(pd) == false)
	{

		switch (mortyDialogue.getCurrState(pd))
		{

		case(CharacterStates::SMILE):
		{
			smile.animate(0);
			setTextureRect(smile.getCurrentFrame());

		};	break;

		}

		return false;
	}

	else
	{
		return true;
	}
}

void Morty::endConvo(PlayerData* pd)
{
	setSize(sf::Vector2f(400, 445));
	setPosition(sf::Vector2f(-30.0f, 250.0f));
	setCollisionBox(14, 0, 100, 445);

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}
