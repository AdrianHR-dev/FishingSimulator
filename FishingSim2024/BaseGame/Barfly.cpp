#include "Barfly.h"

Barfly::Barfly()
{

	charTexture.loadFromFile("gfx/Characters/barfly/barflySprites.png");
	setTexture(&charTexture);

	//Character positions set
	setSize(sf::Vector2f(150.0f, 390.0f));
	setPosition(sf::Vector2f(120.0f, 250.0f));
	setCollisionBox(0, 0, 150, 390);

	//Initialise different character frames

	//BARFLY CHARACTER SIZE: 	SIZE: 100X278

	distance.addFrame(sf::IntRect(0, 0, 100, 278));
	neutral.addFrame(sf::IntRect(300, 0, 100, 278));
	thinking.addFrame(sf::IntRect(200, 0, 100, 278));
	side.addFrame(sf::IntRect(0, 278, 100, 278));
	angry.addFrame(sf::IntRect(100, 0, 100, 278));
	blank.addFrame(sf::IntRect(0, 0, 1, 1));

	charName = CharacterName::BARFLY;

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
	night = true;
}

Barfly::~Barfly()
{

}

void Barfly::handleInput(float dt)
{

}

void Barfly::update(float dt)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		if (night)
		{
			//Character positions set
			setSize(sf::Vector2f(150.0f, 390.0f));
			setPosition(sf::Vector2f(120.0f, 250.0f));
			setCollisionBox(0, 0, 150, 390);
		}

		else
		{
			//Character positions set
			setSize(sf::Vector2f(150.0f, 390.0f));
			setPosition(sf::Vector2f(50.0f, 225.0f));
			setCollisionBox(0, 0, 150, 390);
		}
	}
}

bool Barfly::interact(PlayerData* pd)
{
	talking = true;

	setSize(sf::Vector2f(280.0, 504.0f));
	setPosition(sf::Vector2f(150.0f, 125.0f));

	barflyDialogue.setAlive(true);

	if (barflyDialogue.DialogueUpdate(pd) == false)
	{

		switch (barflyDialogue.getCurrState(pd))
		{
		case(CharacterStates::NEUTRAL):
		{
			neutral.animate(0);
			setTextureRect(neutral.getCurrentFrame());

		};	break;

		case(CharacterStates::TURN):
		{
			side.animate(0);
			setTextureRect(side.getCurrentFrame());

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

void Barfly::endConvo(PlayerData* pd)
{
	//PLAYER DATA NOT CURRENTLY REQUIRED: HOWEVER! ITS BEING INCLUDED SO THAT, IF REQUIRED IN FUTURE 
	//(eg.character leaving or changing anim in certain scene) THEN YOU HAVE IT ON HAND! (You will require I actually
	// alreayd know when you'll use it but it's just pointless to utilise in this template)

	//I forgot to tell you when youd use it so now im not sure you DO need it actually
	
	//Character positions set
	setSize(sf::Vector2f(150.0f, 390.0f));
	setPosition(sf::Vector2f(120.0f, 250.0f));
	setCollisionBox(0, 0, 150, 390);

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}