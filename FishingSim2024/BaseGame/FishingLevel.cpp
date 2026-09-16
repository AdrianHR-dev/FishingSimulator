#include "FishingLevel.h"

FishingLevel::FishingLevel(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd)
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
	sceneTexture.loadFromFile("gfx/Scenes/water.png");
	background.setTexture(&sceneTexture);
}

FishingLevel::~FishingLevel()
{

}

void FishingLevel::update(float dt)
{
	cursor.update(dt);
	fish.update(dt);

	//If fish is in splash state splash noise plays
	if (fish.getFishStatus() == FishStatus::SPLASH && audio->getSound("splash")->getStatus() == sf::SoundSource::Stopped && playerData->fishing == true)
	{
		audio->playSoundbyName("splash");
	}

	if (Collision::checkBoxPoint(&fish, cursor.getPosition()) && fish.getFishStatus() == FishStatus::SPLASH)
	{
		//Cursor updated to arrow
		cursor.fishingCollisionResponse();
	}

}

void FishingLevel::handleInput(float dt)
{
	if (input->isLeftMouseDown() && (Collision::checkBoxPoint(&fish, cursor.getPosition()) && fish.getFishStatus() == FishStatus::SPLASH))
	{
		input->setLeftMouse(Input::MouseState::UP);
		fish.setFishStatus(FishStatus::CAUGHT);

		if (playerData->day < 5)
		{
			audio->playSoundbyName("day1Catch");

			//Fish catch animations
			if (playerData->day < 4)
			{
				fish.getFishCatch()->animate(0);
				fish.setTextureRect(fish.getFishCatch()->getCurrentFrame());
			}

			else if (playerData->day == 4)
			{
				fish.getShoeCatch()->animate(0);
				fish.setTextureRect(fish.getShoeCatch()->getCurrentFrame());
			}

		}

		else if (playerData->day == 5)
		{
			audio->getSound("day5Catch")->setVolume(100);
			audio->playSoundbyName("day5Catch");

			fish.getEngineCatch()->animate(0);
			fish.setTextureRect(fish.getEngineCatch()->getCurrentFrame());
		}

		else if (playerData->day == 6)
		{
			audio->playSoundbyName("day6Catch");

			fish.getHandCatch()->animate(0);
			fish.setTextureRect(fish.getHandCatch()->getCurrentFrame());

		}
	}

	if (input->isLeftMouseDown() && fish.getFishStatus() == FishStatus::CAUGHT && playerData->transition == false)
	{
		input->setLeftMouse(Input::MouseState::UP);

		fish.getHandCatch()->animate(0);
		fish.setTextureRect(fish.getHandCatch()->getCurrentFrame());

		audio->stopAllSounds();
		audio->stopAllMusic();

		audio->playSoundbyName("footsteps");

		playerData->transition = true;
		playerData->fishing = false;
		playerData->isDay = false;

	}

	if (playerData->transition == true && audio->getSound("footsteps")->getStatus() == sf::Sound::Status::Stopped)
	{

		fish.setFishStatus(FishStatus::IDLE);

		playerData->transition = false;
		playerData->nightInit = false;

		audio->stopAllSounds();

		gameState->setCurrentState(State::GAMEPLAY);
			
	}
}


void FishingLevel::render()
{

	if (playerData->transition == false && playerData->nightInit == true)
	{
		beginDraw();


		window->draw(background);
		window->draw(fish);
		window->draw(cursor);
	}

	else
	{
		window->clear(sf::Color::Black);

		beginDraw();

	}

	endDraw();
}
