#include "Home.h"

Home::Home()
{

	//Character positions set
	setPosition(sf::Vector2f(573.0f, 470.0f));
	setCollisionBox(0, 0, 69.0f, 90.0f);

	itemName = ItemName::HOME;

	talking = false;
}

Home::~Home()
{

}

void Home::update(float dt)
{
	if (!isAlive())
	{
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		setCollisionBox(0, 0, 69.0f, 90.0f);
	}
}

void Home::handleInput(float dt)
{

}

bool Home::interact(PlayerData* pd)
{
	talking = true;

	homeDialogue.setAlive(true);
	

	if (homeDialogue.DialogueUpdate(pd) == false)
	{
		return false;
	}

	else
	{
		return true;
	}
}

void Home::endInvestigation(PlayerData* pd)
{
	//Item pos reset
	setPosition(sf::Vector2f(573.0f, 470.0f));
	setCollisionBox(0, 0, 69.0f, 90.0f);


	talking = false;
}
