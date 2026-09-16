#include "Level.h"

Level::Level()
{
	//Level variables initialised 
	window = nullptr;
	input = nullptr;
	gameState = nullptr;
	audio = nullptr;
}

Level::~Level()
{

}

//Begin the rendering process! I like BLUE ! what colour... do you like!?!?!?
void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}

//Rendering to buffer done, now displayed on screen
void Level::endDraw()
{
	window->display();
}
