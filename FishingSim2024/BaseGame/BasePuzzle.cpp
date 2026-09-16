#include "BasePuzzle.h"

BasePuzzle::BasePuzzle()
{
	window = nullptr;
	input = nullptr;
	gameState = nullptr;
	audio = nullptr;
	name = PuzzleNames::TESTPUZZLE;
	playerData = nullptr;
}

BasePuzzle::BasePuzzle(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* player)
{
	window = wind;
	input = in;
	gameState = gs;
	audio = aud;
	playerData = player;

	name = PuzzleNames::TESTPUZZLE;

	//Cursor setup
	cursor.setInput(input);
	cursor.setWindow(window);

	texture.loadFromFile("gfx/Puzzles/testPuzzle.png");
	background.setTexture(&texture);

	background.setPosition(sf::Vector2f(0.0f, 0.0f));
	background.setSize(sf::Vector2f(700.f, 700.0f));
}

BasePuzzle::~BasePuzzle()
{

}

void BasePuzzle::update(float dt)
{
	cursor.update(dt);
}

void BasePuzzle::handleInput(float dt)
{
	if (input->isLeftMouseDown())
	{
		input->setLeftMouse(Input::MouseState::UP);
		playerData->puzzle = false;
	}
}

void BasePuzzle::render()
{
	window->clear(sf::Color::Black);

	window->draw(background);
	window->draw(cursor);

	window->display();
}