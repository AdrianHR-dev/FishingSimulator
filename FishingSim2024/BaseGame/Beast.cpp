#include "Beast.h"

Beast::Beast()
{
	//Shiny setup
	setSize(sf::Vector2f(256.0f, 256.0f));
	setPosition(sf::Vector2f(400.0f, 200.0f));
	setCollisionBox(0, 0, 0, 0);

	itemTexture.loadFromFile("gfx/Items/beast.png");
	setTexture(&itemTexture);

	setAlive(false);

	//ANIMATION FRAMES SET
	rise.addFrame(sf::IntRect(0, 0, 128, 128));
	rise.addFrame(sf::IntRect(128, 0, 128, 128));
	rise.addFrame(sf::IntRect(256, 0, 128, 128));

	rise.addFrame(sf::IntRect(0, 128, 128, 128));
	rise.addFrame(sf::IntRect(128, 128, 128, 128));
	rise.addFrame(sf::IntRect(256, 128, 128, 128));

	rise.addFrame(sf::IntRect(0, 256, 128, 128));

	//Frame speed set
	rise.setFrameSpeed(1.0f / 12.0f);

	//Initial frame set
	rise.animate(0);
	setTextureRect(rise.getCurrentFrame());

	rise.setLooping(false);

	itemName = ItemName::BEAST;

	talking = false;
}

Beast::~Beast()
{

}

void Beast::update(float dt)
{
	if (!isAlive())
	{
		setCollisionBox(0, 0, 0, 0);
		setSize(sf::Vector2f(0.0f, 0.0f));
	}

	if (isAlive() && talking == false)
	{
		setSize(sf::Vector2f(256.0f, 256.0f));
		setPosition(sf::Vector2f(400.0f, 200.0f));

		//Animation running
		rise.animate(dt);
		setTextureRect(rise.getCurrentFrame());
	}


}

void Beast::handleInput(float dt)
{

}
