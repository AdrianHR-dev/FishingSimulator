#include "DrunkEnd.h"

DrunkEnd::DrunkEnd(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd)
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
	sceneTexture.loadFromFile("gfx/Scenes/dunk.jpg");
	background.setTexture(&sceneTexture);
}

DrunkEnd::~DrunkEnd()
{

}

void DrunkEnd::update(float dt)
{
	cursor.update(dt);

	if (audio->getMusic()->getStatus() == sf::SoundSource::Status::Stopped && gameState->getCurrentState() == State::DRUNKEND)
	{
		audio->playMusicbyName("nightAmb");
	}

}

void DrunkEnd::handleInput(float dt)
{

	if (input->isLeftMouseDown())
	{
		input->setLeftMouse(Input::MouseState::UP);

		audio->stopAllSounds();

		gameState->setCurrentState(State::CLOSE);

	}
}


void DrunkEnd::render()
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
