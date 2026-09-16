#include "Drunkard.h"

Drunkard::Drunkard()
{
	charTexture.loadFromFile("gfx/Characters/drunkard/drunkardSheet.png");
	setTexture(&charTexture);

	//Character positions set
	setSize(sf::Vector2f(22.0f, 30.0f));
	setPosition(sf::Vector2f(240.0f, 348.0f));
	setCollisionBox(0, 0, 22, 30);

	//Initialise different character frames

	//DRUNKARD CHARACTER SIZE: 170 X 328

	distance.addFrame(sf::IntRect(170, 238, 170, 238));
	neutral.addFrame(sf::IntRect(0, 0, 170, 238));
	thinking.addFrame(sf::IntRect(170, 0, 170, 238));
	angry.addFrame(sf::IntRect(340, 0, 170, 238));
	turn.addFrame(sf::IntRect(0, 238, 170, 238));
	blank.addFrame(sf::IntRect(1, 1, 0, 0));

	charName = CharacterName::DRUNKARD;

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}

Drunkard::~Drunkard()
{

}

void Drunkard::update(float dt)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		//Character positions set
		setSize(sf::Vector2f(22.0f, 30.0f));
		setPosition(sf::Vector2f(240.0f, 348.0f));
		setCollisionBox(0, 0, 22, 30);
	}
}

void Drunkard::handleInput(float dt)
{

}

bool Drunkard::interact(PlayerData* pd)
{
	talking = true;

	setSize(sf::Vector2f(360.0, 504.0f));
	setPosition(sf::Vector2f(100.0f, 100.0f));

	drunkardDialogue.setAlive(true);

	if (drunkardDialogue.DialogueUpdate(pd) == false)
	{

		switch (drunkardDialogue.getCurrState(pd))
		{
		case(CharacterStates::NEUTRAL):
		{
			neutral.animate(0);
			setTextureRect(neutral.getCurrentFrame());

		};	break;

		case(CharacterStates::ANGRY):
		{
			angry.animate(0);
			setTextureRect(angry.getCurrentFrame());

		};	break;

		case(CharacterStates::THINKING):
		{
			thinking.animate(0);
			setTextureRect(thinking.getCurrentFrame());

		};	break;

		case(CharacterStates::TURN):
		{
			turn.animate(0);
			setTextureRect(turn.getCurrentFrame());

		};	break;

		case(CharacterStates::BLANK):
		{
			blank.animate(0);
			setTextureRect(blank.getCurrentFrame());

		};	break;

		}

		return false;
	}

	else
	{
		return true;
	}
}

void Drunkard::endConvo(PlayerData* pd)
{
	setSize(sf::Vector2f(22.0f, 30.0f));
	setPosition(sf::Vector2f(240.0f, 348.0f));
	setCollisionBox(0, 0, 22, 30);

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}
