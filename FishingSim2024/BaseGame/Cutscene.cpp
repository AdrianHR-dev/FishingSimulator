#include "Cutscene.h"

Cutscene::Cutscene(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd)
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
	cutsceneTexture.loadFromFile("gfx/Cutscenes/endCutscene.png");
	background.setTexture(&cutsceneTexture);

	init = false;

	//END CUTSCENE DIMENSIONS: 152X150px, 5 X 5 TILES (3 tiles on last row)
	cutsceneAnim.addFrame(sf::IntRect(0, 0, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(152, 0, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(304, 0, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(456, 0, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(608, 0, 152, 150));

	cutsceneAnim.addFrame(sf::IntRect(0, 150, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(152, 150, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(304, 150, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(456, 150, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(608, 150, 152, 150));

	cutsceneAnim.addFrame(sf::IntRect(0, 300, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(152, 300, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(304, 300, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(456, 300, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(608, 300, 152, 150));

	cutsceneAnim.addFrame(sf::IntRect(0, 450, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(152, 450, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(304, 450, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(456, 450, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(608, 450, 152, 150));

	cutsceneAnim.addFrame(sf::IntRect(0, 600, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(152, 600, 152, 150));
	cutsceneAnim.addFrame(sf::IntRect(304, 600, 152, 150));

	init = false;


	//Frame speed set
	cutsceneAnim.setFrameSpeed(1.0f / 1.0f);

	//Initial frame set
	cutsceneAnim.animate(0);
	background.setTextureRect(cutsceneAnim.getCurrentFrame());

	cutsceneAnim.setLooping(false);
}

Cutscene::~Cutscene()
{

}

void Cutscene::update(float dt)
{
	cursor.update(dt);

	if (init == false)
	{
		init = true;
	}

	else
	{
		cutsceneAnim.animate(dt);
		background.setTextureRect(cutsceneAnim.getCurrentFrame());

		if (cutsceneAnim.getCurrentFrame() == sf::IntRect(304, 600, 152, 150))
		{
			gameState->setCurrentState(State::GAMEPLAY);
			playerData->dayProgress = 11;
			playerData->day = 1;
		}
	}

	if (audio->getMusic()->getStatus() == sf::SoundSource::Status::Stopped)
	{
		audio->playMusicbyName("ambience");
	}

}

void Cutscene::handleInput(float dt)
{

}


void Cutscene::render()
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
