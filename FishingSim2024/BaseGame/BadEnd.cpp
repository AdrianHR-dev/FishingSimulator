#include "BadEnd.h"

BadEnd::BadEnd(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd)
{
	window = wind;
	input = in;
	gameState = gs;
	audio = aud;
	playerData = pd;

	//Hides cursor for new cursor texture to show
	window->setMouseCursorVisible(false);

	//Cursor setup
	cursor.setInput(input);
	cursor.setWindow(window);

	background.setWindow(window);
	background.setAlive(true);
	background.setSize(sf::Vector2f(700.0f, 700.0f));
	background.setPosition(sf::Vector2f(0.0f, 0.0f));
	sceneTexture.loadFromFile("gfx/Scenes/dark.png");
	badEndTexture.loadFromFile("gfx/Scenes/badEnd.png");
	background.setTexture(&sceneTexture);

	init = false;
}

BadEnd::~BadEnd()
{

}

void BadEnd::update(float dt)
{
	cursor.update(dt);

	if (audio->getSound("bigSplash")->getStatus() == sf::SoundSource::Status::Stopped && init == false)
	{
		audio->playMusicbyName("water");

		background.setTexture(&badEndTexture);
		background.setSize(sf::Vector2f(1500.0f, 1500.0f));

		init = true;
	}

}

void BadEnd::handleInput(float dt)
{
	if (input->isLeftMouseDown())
	{
		input->setLeftMouse(Input::MouseState::UP);

		if (init)
		{
			audio->stopAllSounds();

			gameState->setCurrentState(State::CLOSE);
		}
	}
}


void BadEnd::render()
{

	if (playerData->transition == false)
	{
		beginDraw();


		window->draw(background);
		window->draw(cursor);
	}

	else
	{
		window->clear(sf::Color::Black);

		beginDraw();

	}

	endDraw();
}
