#include "Tentacle.h"

Tentacle::Tentacle()
{
	//Tentacle setup

	itemTexture.loadFromFile("gfx/Items/tentacleSheet.png");
	setTexture(&itemTexture);

	//Tentacle setup
	setPosition(sf::Vector2f(80.0f, 242.0f));
	setSize(sf::Vector2f(52, 40));
	setCollisionBox(0, 0, 52, 40);
	setTexture(&itemTexture);
	setAlive(false);

	//ANIMATION FRAMES SET
	tentacleAnim.addFrame(sf::IntRect(0, 0, 26, 20));
	tentacleAnim.addFrame(sf::IntRect(26, 0, 26, 20));
	tentacleAnim.addFrame(sf::IntRect(0, 20, 26, 20));
	tentacleAnim.addFrame(sf::IntRect(26, 20, 26, 20));
	tentacleAnim.addFrame(sf::IntRect(0, 20, 26, 20));
	tentacleAnim.addFrame(sf::IntRect(26, 0, 26, 20));

	//Frame speed set
	tentacleAnim.setFrameSpeed(1.0f / 6.0f);

	//Initial frame set
	tentacleAnim.animate(0);
	setTextureRect(tentacleAnim.getCurrentFrame());

	itemName = ItemName::TENTACLE;

	talking = false;
}

Tentacle::~Tentacle()
{

}

void Tentacle::update(float dt)
{
	if (!isAlive())
	{
		setCollisionBox(0, 0, 0, 0);
		setSize(sf::Vector2f(0.0f, 0.0f));
	}

	if (isAlive() && talking == false)
	{
		setPosition(sf::Vector2f(80.0f, 242.0f));
		setSize(sf::Vector2f(52, 40));
		setCollisionBox(0, 0, 52, 40);

		//Animation running
		tentacleAnim.animate(dt);
		setTextureRect(tentacleAnim.getCurrentFrame());
	}


}

void Tentacle::handleInput(float dt)
{

}

bool Tentacle::interact(PlayerData* pd)
{
	talking = true;

	tentacleDialogue.setAlive(true);

	if (tentacleDialogue.DialogueUpdate(pd) == false)
	{
		return false;
	}

	else
	{
		return true;
	}
}

void Tentacle::endInvestigation(PlayerData* pd)
{
	//Item pos reset

	setPosition(sf::Vector2f(70.0f, 222.0f));
	setSize(sf::Vector2f(52, 40));
	setCollisionBox(0, 0, 52, 40);

	talking = false;
}
