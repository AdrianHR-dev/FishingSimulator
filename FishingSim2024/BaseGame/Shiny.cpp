#include "Shiny.h"

Shiny::Shiny()
{
	//Shiny setup

	setPosition(sf::Vector2f(90.0f, 520.0f));
	setSize(sf::Vector2f(16, 16));
	setCollisionBox(0, 0, 16, 16);

	itemTexture.loadFromFile("gfx/Items/shiny.png");
	setTexture(&itemTexture);

	setAlive(false);

	//ANIMATION FRAMES SET
	shineAnim.addFrame(sf::IntRect(0, 0, 16, 16));
	shineAnim.addFrame(sf::IntRect(0, 16, 16, 16));

	//Frame speed set
	shineAnim.setFrameSpeed(1.0f / 2.0f);

	//Initial frame set
	shineAnim.animate(0);
	setTextureRect(shineAnim.getCurrentFrame());

	itemName = ItemName::SHINY;

	talking = false;
}

Shiny::~Shiny()
{

}

void Shiny::update(float dt)
{
	if (!isAlive())
	{
		setCollisionBox(0, 0, 0, 0);
		setSize(sf::Vector2f(0.0f, 0.0f));
	}

	if (isAlive() && talking == false)
	{
		setCollisionBox(0, 0, 16, 16);
		setSize(sf::Vector2f(16.0f, 16.0f));

		//Animation running
		shineAnim.animate(dt);
		setTextureRect(shineAnim.getCurrentFrame());
	}

	
}

void Shiny::handleInput(float dt)
{

}

bool Shiny::interact(PlayerData* pd)
{
	talking = true;

	shinyDialogue.setAlive(true);

	if (shinyDialogue.DialogueUpdate(pd) == false)
	{
		return false;
	}

	else
	{
		return true;
	}
}

void Shiny::endInvestigation(PlayerData* pd)
{
	//Item pos reset

	setPosition(sf::Vector2f(90.0f, 520.0f));
	setSize(sf::Vector2f(16, 16));
	setCollisionBox(0, 0, 16, 16);

	talking = false;
}
