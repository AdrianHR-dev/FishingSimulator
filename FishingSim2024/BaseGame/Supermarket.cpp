#include "Supermarket.h"

Shop::Shop()
{
	//itemTexture.loadFromFile("gfx/Items/shoe.png");
	//setTexture(&itemTexture);

//Position set
	setPosition(sf::Vector2f(0, 282));
	setCollisionBox(0, 0, 620, 108);
	setAlive(false);

	itemName = ItemName::SHOP;

	talking = false;
}

Shop::~Shop()
{
 
}

void Shop::handleInput(float dt)
{

}

void Shop::update(float)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		setPosition(sf::Vector2f(0, 282));
		setCollisionBox(0, 0, 620, 108);

	}
}

bool Shop::interact(PlayerData* pd)
{
	talking = true;

	supermarketDialogue.setAlive(true);

	if (supermarketDialogue.DialogueUpdate(pd) == false)
	{
		return false;
	}

	else
	{
		return true;
	}
}

void Shop::endInvestigation(PlayerData* pd)
{
	//Character positions set
	setPosition(sf::Vector2f(0, 282));
	setCollisionBox(0, 0, 620, 108);

	talking = false;
}
