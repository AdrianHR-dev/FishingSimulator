#include "Desk.h"

Desk::Desk()
{
	itemTexture.loadFromFile("gfx/Items/damDocument.png");
	setTexture(&itemTexture);

	//Character positions set
	setPosition(sf::Vector2f(100.0f, 100.0f));
	setCollisionBox(0, 0, 450.0f, 450.0f);

	blank.addFrame(sf::IntRect(0, 0, 0, 0));
	page.addFrame(sf::IntRect(0, 0, 891, 658));

	//Default stance set
	blank.animate(0);
	setTextureRect(blank.getCurrentFrame());

	itemName = ItemName::DESK;

	talking = false;
}

Desk::~Desk()
{

}

void Desk::update(float dt)
{
	if (!isAlive())
	{
		setCollisionBox(0, 0, 0, 0);
	}

	if (isAlive() && talking == false)
	{
		setCollisionBox(0, 0, 450, 450);
	}
}

void Desk::handleInput(float dt)
{

}

bool Desk::interact(PlayerData* pd)
{
	talking = true;

	deskDialogue.setAlive(true);

	setPosition(sf::Vector2f(150.0f, 125.0f));

	if (deskDialogue.DialogueUpdate(pd) == false)
	{

		switch (deskDialogue.getCurrState(pd))
		{
		case(CharacterStates::BLANK):
		{
			blank.animate(0);
			setTextureRect(blank.getCurrentFrame());

			setSize(sf::Vector2f(0.0, 0.0f));
			

		};	break;

		case(CharacterStates::ITEM):
		{
			page.animate(0);
			setTextureRect(page.getCurrentFrame());

			setSize(sf::Vector2f(300.0f, 225.0f));

		};	break;

		}

		return false;

	}

	else
	{
		return true;
	}

	
}

void Desk::endInvestigation(PlayerData* pd)
{
	setPosition(sf::Vector2f(100.0f, 100.0f));
	setCollisionBox(0, 0, 450.0f, 450.0f);


	talking = false;
}
