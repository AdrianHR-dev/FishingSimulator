#include "Door.h"

Door::Door()
{

	//Character positions set
	setPosition(sf::Vector2f(90.0f, 200.0f));
	setCollisionBox(0, 0, 43.0f, 70.0f);

	itemName = ItemName::DOOR;

	talking = false;
}

Door::~Door()
{

}

void Door::update(float dt)
{
	if (!isAlive())
	{
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		setCollisionBox(0, 0, 43.0f, 70.0f);
	}
}

void Door::handleInput(float dt)
{

}

bool Door::interact(PlayerData* pd)
{
	talking = true;

	doorDialogue.setAlive(true);

	if (doorDialogue.DialogueUpdate(pd) == false)
	{
		return false;
	}

	else
	{
		return true;
	}

}

void Door::endInvestigation(PlayerData* pd)
{
	//Item pos reset
	setPosition(sf::Vector2f(90.0f, 200.0f));
	setCollisionBox(0, 0, 43.0f, 70.0f);


	talking = false;
}
