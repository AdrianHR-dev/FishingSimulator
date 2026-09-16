#include "MenuButton.h"

MenuButton::MenuButton()
{
	//Load and set button texture
	buttonTexture.loadFromFile("gfx/playButton.png");
	setTexture(&buttonTexture);

	//Important button variables initialised on spawning
	setSize(sf::Vector2f(150.0f, 92.0f));
	setCollisionBox(0, 0, 150.0f, 92.0f);
	setPosition(sf::Vector2f(275.0f, 450.0f));

	//Adding animation frames
	idleButton.addFrame(sf::IntRect(0, 0, 300, 184));
	selectButton.addFrame(sf::IntRect(0, 184, 300, 184));

	//Sets button to spawn with idle animation
	idleButton.animate(0);
	setTextureRect(idleButton.getCurrentFrame());
}

MenuButton::~MenuButton()
{

}

void MenuButton::update(float dt)
{
	idleButton.animate(0);
	setTextureRect(idleButton.getCurrentFrame());
}

void MenuButton::collisionResponse()
{
	//Changes button texture when hovered over
	selectButton.animate(0);
	setTextureRect(selectButton.getCurrentFrame());
}
