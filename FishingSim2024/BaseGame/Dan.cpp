#include "Dan.h"

Dan::Dan()
{

	charTexture.loadFromFile("gfx/Characters/friend/danSprites.png");
	setTexture(&charTexture);

	//Character positions set
	setSize(sf::Vector2f(180.0f, 252.0f));
	setPosition(sf::Vector2f(10.0, 300.0f));
	setCollisionBox(40, 0, 80.0f, 252.0f);

	//Initialise different character frames

	//MY CHARACTER SIZE: 240X336

	distance.addFrame(sf::IntRect(480, 336, 240, 336));
	neutral.addFrame(sf::IntRect(0, 0, 240, 336));
	smile.addFrame(sf::IntRect(240, 0, 240, 336));
	turn.addFrame(sf::IntRect(480, 0, 240, 336));
	thinking.addFrame(sf::IntRect(0, 336, 240, 336));
	nervous.addFrame(sf::IntRect(240, 336, 240, 336));
	blank.addFrame(sf::IntRect(0, 0, 1, 1));

	charName = CharacterName::DAN;

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;

	night = false;
}

Dan::~Dan()
{

}

void Dan::handleInput(float dt)
{

}

void Dan::update(float dt)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false )
	{
		if (!night)
		{
			setSize(sf::Vector2f(360.0f, 504.0f));
			setPosition(sf::Vector2f(-100.0f, 150.0f));
			setCollisionBox(0, 0, 220, 504);
		}

		else
		{
			setSize(sf::Vector2f(180.0f, 252));
			setPosition(sf::Vector2f(350.0f, 300.0f));
			setCollisionBox(80, 0, 110, 252);
		}
	
	}
}

bool Dan::interact(PlayerData* pd)
{
	talking = true;

	setSize(sf::Vector2f(360.0, 504.0f));
	setPosition(sf::Vector2f(100.0f, 100.0f));

	danDialogue.setAlive(true);

	if (danDialogue.DialogueUpdate(pd) == false)
	{

		switch (danDialogue.getCurrState(pd))
		{
		case(CharacterStates::NEUTRAL):
		{
			neutral.animate(0);
			setTextureRect(neutral.getCurrentFrame());

		};	break;

		case(CharacterStates::SMILE):
		{
			smile.animate(0);
			setTextureRect(smile.getCurrentFrame());

		};	break;

		case(CharacterStates::FEAR):
		{
			nervous.animate(0);
			setTextureRect(nervous.getCurrentFrame());

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

void Dan::endConvo(PlayerData* pd)
{
	//PLAYER DATA NOT CURRENTLY REQUIRED: HOWEVER! ITS BEING INCLUDED SO THAT, IF REQUIRED IN FUTURE 
	//(eg.character leaving or changing anim in certain scene) THEN YOU HAVE IT ON HAND! (You will require I actually
	// alreayd know when you'll use it but it's just pointless to utilise in this template)

	//Character positions set

	setSize(sf::Vector2f(360.0f, 504.0f));
	setPosition(sf::Vector2f(-100.0f, 150.0f));
	setCollisionBox(0, 0, 220, 504);
	

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}