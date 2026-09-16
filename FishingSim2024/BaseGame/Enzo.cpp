#include "Enzo.h"

Enzo::Enzo()
{
	charTexture.loadFromFile("gfx/Characters/creature/creatureSprites.png");
	setTexture(&charTexture);

	//Character positions set
	setSize(sf::Vector2f(77.0f, 85.0f));
	setPosition(sf::Vector2f(395.0f, 470.0f));
	setCollisionBox(0, 0, 77, 86);
	setAlive(false);

	//Initialise different character frames

	//CREATURE CHARACTER SIZE: 135 x 189

	distance.addFrame(sf::IntRect(0, 0, 135, 189));
	neutral.addFrame(sf::IntRect(135, 0, 135, 189));

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	charName = CharacterName::ENZO;

	talking = false;
}

Enzo::~Enzo()
{

}

void Enzo::update(float dt)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		//Character positions set
		setSize(sf::Vector2f(77.0f, 85.0f));
		setPosition(sf::Vector2f(395.0f, 470.0f));
		setCollisionBox(0, 0, 77, 86);
	}
}

void Enzo::handleInput(float dt)
{

}

bool Enzo::interact(PlayerData* pd)
{
	talking = true;

	setSize(sf::Vector2f(360.0, 504.0f));
	setPosition(sf::Vector2f(100.0f, 100.0f));

	enzoDialogue.setAlive(true);

	if (enzoDialogue.DialogueUpdate(pd) == false)
	{

		switch (enzoDialogue.getCurrState(pd))
		{
		case(CharacterStates::NEUTRAL):
		{
			neutral.animate(0);
			setTextureRect(neutral.getCurrentFrame());

		};	break;

		case(CharacterStates::DISTANCE):
		{
			distance.animate(0);
			setTextureRect(distance.getCurrentFrame());

		};	break;
		}

		return false;
	}

	else
	{
		return true;
	}
}

void Enzo::endConvo(PlayerData* pd)
{
	setSize(sf::Vector2f(77.0f, 85.0f));
	setPosition(sf::Vector2f(395.0f, 470.0f));
	setCollisionBox(0, 0, 77, 86);

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}
