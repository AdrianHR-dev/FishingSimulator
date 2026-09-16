#include "SlidePuzzle.h"

SlidePuzzle::SlidePuzzle(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* player)
{
	window = wind;
	input = in;
	gameState = gs;
	audio = aud;
	playerData = player;

	name = PuzzleNames::SLIDE;

	tileMap = new TileMap(wind);

	//Cursor setup
	cursor.setInput(input);
	cursor.setWindow(window);

	texture.loadFromFile("gfx/Puzzles/slidePuzzle.png");
	background.setTexture(&texture);

	helpTexture.loadFromFile("gfx/Puzzles/helpScreens/SlidePuzzleHelp.jpg");

	background.setPosition(sf::Vector2f(0.0f, 0.0f));
	background.setSize(sf::Vector2f(700.f, 700.0f));

	complete = false;

	help = false;
}

SlidePuzzle::~SlidePuzzle()
{

}

void SlidePuzzle::update(float dt)
{
	cursor.update(dt);

	if (complete == true && audio->getSound("puzzleSolve")->getStatus() == sf::SoundSource::Status::Stopped)
	{
		playerData->puzzle = false;
		playerData->socksTasks = playerData->socksTasks + 1;
	}
}

void SlidePuzzle::handleInput(float dt)
{
	if (!help)
	{
		//COLLISION CHECKS
		if (input->isLeftMouseDown() && complete == false)
		{
			input->setLeftMouse(Input::MouseState::UP);

			if (Collision::checkBoxPoint(&helpButton, cursor.getPosition()))
			{
				help = true;

				background.setTexture(&helpTexture);

			}

			for (int i = 0; i < 9; i++)
			{

				if (Collision::checkBoxPoint(tileMap->getTile(i), cursor.getPosition()))
				{
					if (tileMap->TileMovement(i))
					{
						audio->playSoundbyName("tileMove");
						winCheck();
					}

					return;
				}
			}
		}
	}

	else
	{
		if (input->isLeftMouseDown())
		{
			input->setLeftMouse(Input::MouseState::UP);

			help = false;

			background.setTexture(&texture);

		}
	}


}

void SlidePuzzle::render()
{
	window->clear(sf::Color::Black);

	if (!help)
	{
		window->draw(background);

		tileMap->render();

		window->draw(helpButton);

		window->draw(cursor);
	}

	else
	{
		window->draw(background);
	}

	window->display();

}

void SlidePuzzle::winCheck()
{
	int correctTiles = 0;

	for(int i = 0; i < 9; i++)
	{
		if (tileMap->getTile(i)->id == i)
		{
			correctTiles = correctTiles + 1;
		}
	}

	if (correctTiles == 9)
	{
		complete = true;
		audio->playSoundbyName("puzzleSolve");
	}
}