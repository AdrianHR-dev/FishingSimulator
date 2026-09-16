#include "Fisherman.h"

Fisherman::Fisherman()
{

	charTexture.loadFromFile("gfx/Characters/fisherman/fishermanSprites.png");
	setTexture(&charTexture);;

	//Initialise different character frames

	//Character positions set
	setSize(sf::Vector2f(120, 150));
	setPosition(sf::Vector2f(470, 315));
	setCollisionBox(0, 0, 120, 150);
	setAlive(false);

	//Initialise different character frames

	//FISHERMAN CHARACTER SIZE: 225 x 260

	distance.addFrame(sf::IntRect(450, 260, 225, 260));
	neutral.addFrame(sf::IntRect(0, 0, 225, 260));
	thinking.addFrame(sf::IntRect(225, 0, 225, 260));
	smile.addFrame(sf::IntRect(0, 260, 225, 260));
	angry.addFrame(sf::IntRect(450, 0, 225, 260));
	blank.addFrame(sf::IntRect(1, 1, 0, 0));

	charName = CharacterName::FISHERMAN;

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}

Fisherman::~Fisherman()
{

}

void Fisherman::handleInput(float dt)
{

}

void Fisherman::update(float dt)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		//Character positions set
		setSize(sf::Vector2f(120, 150));
		setPosition(sf::Vector2f(470, 315));
		setCollisionBox(0, 0, 120, 150);
	}
}

bool Fisherman::interact(PlayerData* pd)
{
	talking = true;

	setSize(sf::Vector2f(360.0, 504.0f));
	setPosition(sf::Vector2f(100.0f, 100.0f));

	fishermanDialogue.setAlive(true);

	if (fishermanDialogue.DialogueUpdate(pd) == false)
	{

		switch (fishermanDialogue.getCurrState(pd))
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

void Fisherman::endConvo(PlayerData* pd)
{
	//PLAYER DATA NOT CURRENTLY REQUIRED: HOWEVER! ITS BEING INCLUDED SO THAT, IF REQUIRED IN FUTURE 
	//(eg.character leaving or changing anim in certain scene) THEN YOU HAVE IT ON HAND! (You will require I actually
	// alreayd know when you'll use it but it's just pointless to utilise in this template)

	//Character positions set

	setSize(sf::Vector2f(120, 150));
	setPosition(sf::Vector2f(470, 315));
	setCollisionBox(0, 0, 120, 150);

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}