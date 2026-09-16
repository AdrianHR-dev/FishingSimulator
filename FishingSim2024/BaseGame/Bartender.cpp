#include "Bartender.h"

Bartender::Bartender()
{

	charTexture.loadFromFile("gfx/Characters/bartender/bartenderSprites.png");
	setTexture(&charTexture);

	//Character positions set
	setSize(sf::Vector2f(125.0f, 173.0f));
	setPosition(sf::Vector2f(360.0f, 251.0f));
	setCollisionBox(0, 0, 125, 173);

	//Initialise different character frames

	//BARTENDER CHARACTER SIZE: 163 X 228

	distance.addFrame(sf::IntRect(0, 0, 163, 228));
	neutral.addFrame(sf::IntRect(326, 0, 163, 228));
	thinking.addFrame(sf::IntRect(163, 0, 163, 228));
	smile.addFrame(sf::IntRect(0, 228, 163, 228));
	angry.addFrame(sf::IntRect(163, 228, 163, 228));
	blank.addFrame(sf::IntRect(0, 0, 1, 1));

	charName = CharacterName::BARTENDER;

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}

Bartender::~Bartender()
{

}

void Bartender::handleInput(float dt)
{

}

void Bartender::update(float dt)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		//Character positions set
		setSize(sf::Vector2f(125.0f, 173.0f));
		setPosition(sf::Vector2f(360.0f, 251.0f));
		setCollisionBox(0, 0, 125, 173);
	}
}

bool Bartender::interact(PlayerData* pd)
{
	talking = true;

	setSize(sf::Vector2f(360.0, 504.0f));
	setPosition(sf::Vector2f(100.0f, 100.0f));

	bartenderDialogue.setAlive(true);

	if (bartenderDialogue.DialogueUpdate(pd) == false)
	{

		switch (bartenderDialogue.getCurrState(pd))
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

void Bartender::endConvo(PlayerData* pd)
{
	//PLAYER DATA NOT CURRENTLY REQUIRED: HOWEVER! ITS BEING INCLUDED SO THAT, IF REQUIRED IN FUTURE 
	//(eg.character leaving or changing anim in certain scene) THEN YOU HAVE IT ON HAND! (You will require I actually
	// alreayd know when you'll use it but it's just pointless to utilise in this template)

	//Character positions set

	setSize(sf::Vector2f(360.0f, 504.0f));
	setPosition(sf::Vector2f(360.0f, 251.0f));
	setCollisionBox(0, 0, 220, 504);

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}