#include "Body.h"

Body::Body()
{

	//Character positions set
	setPosition(sf::Vector2f(200, 325));
	setCollisionBox(0, 0, 150.0f, 150.0f);

	itemName = ItemName::BODY;

	talking = false;
	alive = true;
}

Body::~Body()
{

}

void Body::update(float dt)
{
	if (!isAlive())
	{
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive())
	{
		setCollisionBox(0, 0, 150, 150);
	}
}

void Body::handleInput(float dt)
{

}

bool Body::interact(PlayerData* pd)
{
	return true;
}

