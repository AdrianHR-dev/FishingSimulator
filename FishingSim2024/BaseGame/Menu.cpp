#include "Menu.h"

Menu::Menu(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd)
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

	//Text variables set

	font.loadFromFile("font/arial.ttf");
	dayText.setFont(font);
	dayText.setCharacterSize(32);
	dayText.setPosition(575, 5);
	dayText.setFillColor(sf::Color::Red);

	dayText.setString("Day " + std::to_string(playerData->day));

	texture.loadFromFile("gfx/Scenes/title.png");
	background.setTexture(texture);

	background.setPosition(0.0f, 0.0f);

}

Menu::~Menu()
{

}

void Menu::handleInput(float dt)
{

}

void Menu::update(float dt)
{
	cursor.update(dt);

	//If cursor is colliding with button, button reacts
	if (Collision::checkBoxPoint(&menuButton, cursor.getPosition()))
	{
		menuButton.collisionResponse();

		//If mouse is pressed over button, game begins
		if (input->isLeftMouseDown())
		{
			audio->stopAllMusic();	//Title music stopped
			input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state
			gameState->setCurrentState(State::GAMEPLAY);	//Update game state

		}
	}

	else
	{
		menuButton.update(dt);
	}

	//Reset Button
	if (Collision::checkBoxPoint(&resetButton, cursor.getPosition()))
	{
		resetButton.collisionResponse();

		//If mouse is pressed over button, save data resets
		if (input->isLeftMouseDown())
		{
			playerData->init();
			playerData->saveData();
			playerData->loadData();
		}
	}

	else
	{
		resetButton.update(dt);
	}
}

void Menu::initMusic()
{
	audio->playMusicbyName("water");
	audio->getMusic()->setLoop(true);
}

void Menu::render()
{
	beginDraw();

	window->draw(background);
	window->draw(menuButton);
	window->draw(resetButton);
	window->draw(cursor);

	endDraw();
}