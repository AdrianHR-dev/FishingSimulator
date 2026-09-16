#include "Nat.h"

Nat::Nat()
{
	charTexture.loadFromFile("gfx/Characters/nat/natSprites.png");
	setTexture(&charTexture);

	//Character positions set
	setSize(sf::Vector2f(30.0f, 42.0f));
	setPosition(sf::Vector2f(420.0f, 370.0f));
	setCollisionBox(0, 0, 30, 42);

	//Initialise different character frames

	//NAT CHARACTER SIZE: 173 X 243

	distance.addFrame(sf::IntRect(173, 243, 173, 243));
	neutral.addFrame(sf::IntRect(0, 0, 173, 243));
	thinking.addFrame(sf::IntRect(173, 0, 173, 243));
	smile.addFrame(sf::IntRect(346, 0, 173, 243));
	angry.addFrame(sf::IntRect(0, 243, 173, 243));
	blank.addFrame(sf::IntRect(0, 0, 1, 1));

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	charName = CharacterName::NAT;

	talking = false;
}

Nat::~Nat()
{

}

void Nat::update(float dt)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		//Character positions set
		setSize(sf::Vector2f(30.0f, 42.0f));
		setPosition(sf::Vector2f(420.0f, 370.0f));
		setCollisionBox(0, 0, 30, 42);
	}
}

void Nat::handleInput(float dt)
{

}

bool Nat::interact(PlayerData* pd)
{
	talking = true;

	setSize(sf::Vector2f(360.0, 504.0f));
	setPosition(sf::Vector2f(100.0f, 100.0f));

	natDialogue.setAlive(true);

	if (natDialogue.DialogueUpdate(pd) == false)
	{

		switch (natDialogue.getCurrState(pd))
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

		case(CharacterStates::SMILE):
		{
			smile.animate(0);
			setTextureRect(smile.getCurrentFrame());

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

void Nat::endConvo(PlayerData* pd)
{
	setSize(sf::Vector2f(30.0f, 42.0f));
	setPosition(sf::Vector2f(420.0f, 370.0f));
	setCollisionBox(0, 0, 30, 42);

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}
