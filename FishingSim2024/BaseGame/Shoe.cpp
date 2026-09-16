#include "Shoe.h"

Shoe::Shoe()
{
	itemTexture.loadFromFile("gfx/Items/shoe.png");
	setTexture(&itemTexture);

	//Character positions set
	setSize(sf::Vector2f(10.0f, 10.0f));
	setPosition(sf::Vector2f(365.0f, 396.0f));
	setCollisionBox(0, 0, 10.0f, 10.0f);

	itemName = ItemName::SHOE;

	talking = false;
}

Shoe::~Shoe()
{

}

void Shoe::handleInput(float dt)
{

}

void Shoe::update(float)
{
	if (!isAlive())
	{
		setSize(sf::Vector2f(0.0f, 0.0f));
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		setSize(sf::Vector2f(10.0f, 10.0f));
		setCollisionBox(0, 0, 10, 10);
	}
}

bool Shoe::interact(PlayerData* pd)
{
	talking = true;

	setSize(sf::Vector2f(360.0, 504.0f));
	setPosition(sf::Vector2f(100.0f, 100.0f));

	shoeDialogue.setAlive(true);

	if (shoeDialogue.DialogueUpdate(pd) == false)
	{
		return false;
	}

	else
	{
		return true;
	}
	
}

void Shoe::endInvestigation(PlayerData* pd)
{
	//Character positions set
	setSize(sf::Vector2f(10.0f, 10.0f));
	setPosition(sf::Vector2f(365.0f, 396.0f));
	setCollisionBox(0, 0, 10.0f, 10.0f);


	talking = false;
}
