#include "DoorPuzzle.h"

DoorPuzzle::DoorPuzzle(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* player)
{
	window = wind;
	input = in;
	gameState = gs;
	audio = aud;
	playerData = player;

	name = PuzzleNames::DOORLOCK;

	//Cursor setup
	cursor.setInput(input);
	cursor.setWindow(window);

	texture.loadFromFile("gfx/Puzzles/DoorPuzzle.png");
	helpTexture.loadFromFile("gfx/Puzzles/helpScreens/NumLockHelp.jpg");
	background.setTexture(&texture);

	background.setPosition(sf::Vector2f(0.0f, 0.0f));
	background.setSize(sf::Vector2f(700.f, 700.0f));

	complete = false;

	for (int i = 0; i < 4; i++)
	{
		buttons.push_back(new NumberButton());
		buttons[i]->setValue(0);

		buttons[i]->setSize(sf::Vector2f(100.0f, 100.0f));
		buttons[i]->setCollisionBox(0, 0, 100, 100);
		buttons[i]->setPosition(sf::Vector2f((120.0f + (110 * i)), (170.0f)));
		buttons[i]->setTextPos(sf::Vector2f((150.0f + (110 * i)), (195.0f)));
	
	}
}

DoorPuzzle::~DoorPuzzle()
{

}

void DoorPuzzle::update(float dt)
{
	cursor.update(dt);

	if (complete == true && audio->getSound("puzzleSolve")->getStatus() == sf::SoundSource::Status::Stopped)
	{
		playerData->puzzle = false;
	}
}

void DoorPuzzle::handleInput(float dt)
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
				background.setScale(2.0f, 2.0f);
			}

			for (int i = 0; i < 4; i++)
			{

				if (Collision::checkBoxPoint(buttons[i], cursor.getPosition()) && buttons[i]->getLocked() == false)
				{
					buttons[i]->incrementValue();
					audio->playSoundbyName("tileMove");
					winCheck();
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

			background.setScale(1.0f, 1.0f);
		}
	}


}

void DoorPuzzle::render()
{
	window->clear(sf::Color::Black);
	if (!help)
	{
		window->draw(background);

		for (int i = 0; i < buttons.size(); i++)
		{
			window->draw(*buttons[i]);
			window->draw(buttons[i]->getText());
		}

		window->draw(helpButton);

		window->draw(cursor);
	}

	else
	{
		window->draw(background);
	}

	window->display();

}

void DoorPuzzle::winCheck()
{
	int correctTiles = 0;

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{

		case(0):
		{
			if (buttons[i]->getValue() == 7)
			{
				correctTiles++;
			}

		}; break;

		case(1):
		{
			if (buttons[i]->getValue() == 5)
			{
				correctTiles++;
			}
		}; break;

		case(2):
		{
			if (buttons[i]->getValue() == 8)
			{
				correctTiles++;
			}
		}; break;

		case(3):
		{
			if (buttons[i]->getValue() == 6)
			{
				correctTiles++;
			}
		}; break;

		}
	}

	if (correctTiles == 4)
	{
		complete = true;
		audio->playSoundbyName("puzzleSolve");
	}
}