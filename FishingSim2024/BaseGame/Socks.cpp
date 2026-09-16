#include "Socks.h"

Socks::Socks()
{
	charTexture.loadFromFile("gfx/Characters/socks/socksSprites.png");
	setTexture(&charTexture);


	//Character positions set
	setSize(sf::Vector2f(152.0f, 213.0f));
	setPosition(sf::Vector2f(375.0f, 450.0f));
	setCollisionBox(0, 0, 152, 75);
	setAlive(false);

	//Initialise different character frames

	//SOCKS CHARACTER SIZE: 152 x 213

	distance.addFrame(sf::IntRect(0, 0, 152, 213));
	thinking.addFrame(sf::IntRect(152, 0, 152, 213));
	angry.addFrame(sf::IntRect(0, 213, 152, 213));
	smile.addFrame(sf::IntRect(152, 213, 152, 213));
	map.addFrame(sf::IntRect(0, 426, 152, 213));
	blank.addFrame(sf::IntRect(0, 0, 1, 1));

	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	charName = CharacterName::SOCKS;

	talking = false;
}

Socks::~Socks()
{

}

void Socks::update(float dt)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		//Character positions set
		setSize(sf::Vector2f(152.0f, 213.0f));
		setCollisionBox(0, 0, 152, 75);
	}
}

void Socks::handleInput(float dt)
{

}

bool Socks::interact(PlayerData* pd)
{
	talking = true;

	setSize(sf::Vector2f(360.0, 504.0f));
	setPosition(sf::Vector2f(100.0f, 100.0f));


	socksDialogue.setAlive(true);

	if (socksDialogue.DialogueUpdate(pd) == false)
	{

		switch (socksDialogue.getCurrState(pd))
		{
		case(CharacterStates::BLANK):
		{
			blank.animate(0);
			setTextureRect(blank.getCurrentFrame());

		};	break;

		case(CharacterStates::DISTANCE):
		{
			distance.animate(0);
			setTextureRect(distance.getCurrentFrame());

		};	break;

		case(CharacterStates::SMILE):
		{
			smile.animate(0);
			setTextureRect(smile.getCurrentFrame());

		};	break;

		case(CharacterStates::THINKING):
		{
			thinking.animate(0);
			setTextureRect(thinking.getCurrentFrame());

		};	break;

		case(CharacterStates::ANGRY):
		{
			angry.animate(0);
			setTextureRect(angry.getCurrentFrame());

		};	break;

		case(CharacterStates::ITEM):
		{
			map.animate(0);
			setTextureRect(map.getCurrentFrame());

		};	break;

		}

		return false;
	}

	else
	{
		return true;
	}
}

void Socks::endConvo(PlayerData* pd)
{
	setCollisionBox(0, 0, 152, 75);
	setSize(sf::Vector2f(152.0f, 213.0f));

	if (pd->socksTasks < 4)
	{
		setPosition(sf::Vector2f(375.0f, 450.0f));
	}

	else if(pd->socksTasks < 6)
	{
		setPosition(sf::Vector2f(175.0f, 450.0f));
	}

	else
	{
		setPosition(sf::Vector2f(375.0f, 450.0f));
	}


	//Default stance set
	distance.animate(0);
	setTextureRect(distance.getCurrentFrame());

	talking = false;
}
