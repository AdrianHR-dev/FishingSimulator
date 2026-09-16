#include "MagicSquare.h"

MagicSquare::MagicSquare(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* player)
{
	window = wind;
	input = in;
	gameState = gs;
	audio = aud;
	playerData = player;

	name = PuzzleNames::MAGICSQUARE;

	//Cursor setup
	cursor.setInput(input);
	cursor.setWindow(window);

	texture.loadFromFile("gfx/Puzzles/magicSquare.png");
	helpTexture.loadFromFile("gfx/Puzzles/helpScreens/MagicSquareHelp.jpg");
	background.setTexture(&texture);

	background.setPosition(sf::Vector2f(0.0f, 0.0f));
	background.setSize(sf::Vector2f(700.f, 700.0f));

	complete = false;

	for (int i = 0; i < 9; i++)
	{
		buttons.push_back(new NumberButton());
		buttons[i]->setValue(1);
		
		if (i < 3)
		{
			buttons[i]->setPosition(sf::Vector2f((250.0f + (130*i)), (295.0f)));
			buttons[i]->setTextPos(sf::Vector2f((295.0f + (130 * i)), (330.0f)));
		}

		else if (i < 6)
		{
			buttons[i]->setPosition(sf::Vector2f((250.0f + (130 * (i-3))), (425.0f)));
			buttons[i]->setTextPos(sf::Vector2f((295.0f + (130 * (i-3))), (455.0f)));
		}

		else
		{
			buttons[i]->setPosition(sf::Vector2f((250.0f + (130 * (i-6))), (560.0f)));
			buttons[i]->setTextPos(sf::Vector2f((295.0f + (130 * (i-6))), (590.0f)));
		}

		if (i == 3 || i == 8)
		{
			buttons[i]->setLocked(true);

			if (i == 3)
			{
				buttons[i]->setValue(7);
			}

			else
			{
				buttons[i]->setValue(8);
			}
		}

		
	}
}

MagicSquare::~MagicSquare()
{

}

void MagicSquare::update(float dt)
{
	cursor.update(dt);

	if (complete == true && audio->getSound("puzzleSolve")->getStatus() == sf::SoundSource::Status::Stopped)
	{
		playerData->puzzle = false;
	}
}

void MagicSquare::handleInput(float dt)
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
		}
	}


}

void MagicSquare::render()
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

void MagicSquare::winCheck()
{
	int correctTiles = 0;

	for (int i = 0; i < 9; i++)
	{
		switch (i)
		{

		case(0):
		{
			if (buttons[i]->getValue() == 2)
			{
				correctTiles++;
			}

		}; break;

		case(1):
		{
			if (buttons[i]->getValue() == 9)
			{
				correctTiles++;
			}
		}; break;

		case(2):
		{
			if (buttons[i]->getValue() == 4)
			{
				correctTiles++;
			}
		}; break;

		case(4):
		{
			if (buttons[i]->getValue() == 5)
			{
				correctTiles++;
			}
		}; break;

		case(5):
		{
			if (buttons[i]->getValue() == 3)
			{
				correctTiles++;
			}
		}; break;

		case(6):
		{
			if (buttons[i]->getValue() == 6)
			{
				correctTiles++;
			}
		}; break;

		case(7):
		{
			if (buttons[i]->getValue() == 1)
			{
				correctTiles++;
			}
		}; break;

		}
	}

	if (correctTiles == 7)
	{
		complete = true;
		audio->playSoundbyName("puzzleSolve");
	}
}