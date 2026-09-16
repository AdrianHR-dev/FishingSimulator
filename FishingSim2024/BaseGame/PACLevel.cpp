#include "PACLevel.h"

#include <stdlib.h>
#include <time.h>

PACLevel::PACLevel(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd)
{

	//Random seed set
	srand(time(NULL));

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

	sceneManager = new SceneManager(window, aud);
	currentScene = new Scene(window, aud);

	currentScene = sceneManager->getNamedScene(SceneNames::PATH1);

	//Text variables set

	font.loadFromFile("font/arial.ttf");
	dayText.setFont(font);
	dayText.setCharacterSize(32);
	dayText.setPosition(575, 5);
	dayText.setFillColor(sf::Color::Red);

	mapText.setFont(font);
	mapText.setCharacterSize(32);
	mapText.setPosition(150.0f, 550.0f);
	mapText.setFillColor(sf::Color::Red);
	mapTimer = 0.0f;

	mapText.setString("Press 'M' to display map.");

	map = new Map();
}

PACLevel::~PACLevel()
{

}

void PACLevel::handleInput(float dt)
{
	//Scene move input
	if (input->isLeftMouseDown() )
	{
		input->setLeftMouse(Input::MouseState::UP);

		//Ingame interactions
		if (playerData->talking == false && playerData->transition == false)
		{
			//Move interaction
			if (cursor.getMoveDir() != MoveDirection::NONE)
			{
				//Stop music when leaving tavern, play ambience
				if (currentScene->getSceneData().sceneName == SceneNames::TAVERN)
				{
					audio->stopAllMusic();
					audio->stopAllSounds();
				}


				Scene* newScene = sceneManager->getNamedScene(currentScene->getNewScene(cursor.getMoveDir()));
				currentScene = newScene;

				//New scene set
				currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));

				playerData->transition = true;

				//Stop ambience when entering tavern
				if (currentScene->getSceneData().sceneName == SceneNames::TAVERN)
				{
					audio->stopAllMusic();
					audio->stopAllSounds();
				}

				audio->playSoundbyName("footsteps");
				input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state

				//Luck randomised
				playerData->luck = rand() & 1000 + 1;
			}

			//Character talk interaction
			else if (cursor.getCurrChar() != CharacterName::NONAME)
			{
				audio->playSoundbyName("textBeep");
				playerData->talking = true;
				playerData->currChar = cursor.getCurrChar();
				currentScene->getSceneData().characters.at(cursor.getCurrChar())->interact(playerData);
			}

			//item talk interaction
			else if (cursor.getCurrItem() != ItemName::NOITEM)
			{
				if (cursor.getCurrItem() != ItemName::BODY)
				{
					audio->playSoundbyName("textBeep");
					playerData->talking = true;
					playerData->currItem = cursor.getCurrItem();
					currentScene->getSceneData().items.at(cursor.getCurrItem())->interact(playerData);
				}

				else
				{
					audio->stopAllMusic();
					gameState->setCurrentState(State::BADEND);
					audio->playSoundbyName("bigSplash");
				}
			}
		}

		else if (playerData->currChar != CharacterName::NONAME)
		{
			audio->playSoundbyName("textBeep");


			if (currentScene->getSceneData().characters.at(playerData->currChar)->interact(playerData) == true)
			{
				//End player convo
				currentScene->getSceneData().characters.at(playerData->currChar)->endConvo(playerData);
				playerData->talking = false;
				playerData->currChar = CharacterName::NONAME;

				currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));
			} 
		}

		else if (playerData->currItem != ItemName::NOITEM && playerData->currItem != ItemName::HOME)
		{
		
			audio->playSoundbyName("textBeep");
			//if player is finished talking (dialogue updated here regardless)
			if (currentScene->getSceneData().items.at(playerData->currItem)->interact(playerData) == true)
			{
				//End player investigation
				currentScene->getSceneData().items.at(playerData->currItem)->endInvestigation(playerData);
				playerData->talking = false;
				playerData->currItem = ItemName::NOITEM;

				currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));
			}
		}

	}

	if (playerData->currItem == ItemName::HOME && currentScene->getSceneData().items.at(playerData->currItem)->getDialogue()->isAlive() == true)
	{

		if (input->isKeyDown(sf::Keyboard::N))
		{
			audio->playSoundbyName("textBeep");
			//if player is finished talking (dialogue updated here regardless)
			if (currentScene->getSceneData().items.at(playerData->currItem)->getDialogue()->DialogueUpdate(playerData) == true)
			{
				//End player investigation
				currentScene->getSceneData().items.at(playerData->currItem)->endInvestigation(playerData);
				playerData->talking = false;
				playerData->currItem = ItemName::NOITEM;

				currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));
			}
		}

		else if (input->isKeyDown(sf::Keyboard::Y))
		{

			//if player is finished talking (dialogue updated here regardless)
			if (currentScene->getSceneData().items.at(playerData->currItem)->getDialogue()->DialogueUpdate(playerData) == true)
			{
				//End player investigation
				currentScene->getSceneData().items.at(playerData->currItem)->endInvestigation(playerData);
				playerData->talking = false;
				playerData->currItem = ItemName::NOITEM;

				currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));

				audio->stopAllMusic();
				audio->stopAllSounds();

				playerData->startDay();

				Scene* newScene = sceneManager->getNamedScene(SceneNames::PATH1);
				currentScene = newScene;

				audio->playSoundbyName("footsteps");
				input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state

				currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));

				playerData->transition = true;

				dayText.setString("Day " + std::to_string(playerData->day));
			}
			

		}
	}

	if (input->isKeyDown(sf::Keyboard::M))
	{
		input->setKeyUp(sf::Keyboard::M);

		if (map->isAlive())
		{
			map->setAlive(false);
		}

		else
		{
			map->setAlive(true);
		}
	}

	

}

void PACLevel::update(float dt)
{

	//CREDITS TRIGGER
	
	if (playerData->credits)
	{
		gameState->setCurrentState(State::CREDITS);
	}
	//Check whetehr to display map help

	if (playerData->mapHint == false && playerData->transition == false && playerData->isDay == false)
	{
		playerData->mapHint = true;
	}

	if (playerData->mapHint == true)
	{
		mapTimer = mapTimer + dt;
	}

	if (mapTimer >= 5)
	{
		playerData->mapHint = false;
	}

	//Day text reset for instancez of players resetting data
	if (playerData->initialised == false)
	{
		playerData->initialised = true;

		dayText.setString("Day " + std::to_string(playerData->day));
	}
	//ENDING SEQUENCE UPDATES
	
	//SWITCH TO GOOD ENDING SCREEN
	if (playerData->dayProgress == 10 && playerData->transition == false)
	{
		if (playerData->socksTasks < 9)
		{
			gameState->setCurrentState(State::GOODEND);
		}

		else
		{
			gameState->setCurrentState(State::CUTSCENE);
		}
	}


	//Beast timer updates when player has reached ending scene
	if (playerData->beastTime > 0)
	{
		playerData->beastTime = playerData->beastTime + dt;
	}

	//Lock player into good ending
	if (playerData->beastTime >= 6)
	{
		playerData->dayProgress = 8;
		playerData->beastTime = 0;

		audio->stopAllMusic();
		audio->stopAllSounds();

		Scene* newScene = sceneManager->getNamedScene(SceneNames::CORPSE);
		currentScene = newScene;

		input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state

		currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));

		dayText.setString("Day " + std::to_string(playerData->day));

		//Play attack sound to sync with beast rising.
		audio->playSoundbyName("attack");
		
	}

	if (playerData->dayProgress == 8 && audio->getSound("attack")->getStatus() == sf::SoundSource::Status::Stopped)
	{
		playerData->dayProgress = 9;

		audio->stopAllMusic();
		audio->stopAllSounds();

		Scene* newScene = sceneManager->getNamedScene(SceneNames::BRIDGE);
		currentScene = newScene;

		input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state

		currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));

		dayText.setString("Day " + std::to_string(playerData->day));

		playerData->transition = true;

		//Play attack sound to sync with beast rising.
		audio->playSoundbyName("explode");
	}

	//START NEW DAY UPON TASK COMPLETION
	if (playerData->tasks >= 10)
	{
		playerData->startDay();
		
		audio->stopAllMusic();
		audio->stopAllSounds();

		Scene* newScene = sceneManager->getNamedScene(SceneNames::PATH1);
		currentScene = newScene;

		audio->playSoundbyName("footsteps");
		input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state

		currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));

		playerData->transition = true;

		dayText.setString("Day " + std::to_string(playerData->day));
	}

	//True ending gameplay trigger
	if (playerData->dayProgress == 11)
	{
		playerData->startDay();

		playerData->dayProgress = 12;
		playerData->day = 1;

		audio->stopAllMusic();
		audio->stopAllSounds();

		Scene* newScene = sceneManager->getNamedScene(SceneNames::END1);
		currentScene = newScene;

		audio->playSoundbyName("footsteps");
		input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state

		currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));

		playerData->transition = true;

		dayText.setString("Day " + std::to_string(playerData->day));
	}


	//DRUNK ENDING HERE
	if (playerData->drink >= 7)
	{
		audio->stopAllMusic();
		gameState->setCurrentState(State::DRUNKEND);
	}

	//BAD END TRIGGER
	if (playerData->isDay && playerData->tasks == 5)
	{
		playerData->tasks = 6;
		Scene* newScene = sceneManager->getNamedScene(SceneNames::CORPSE);

		currentScene = newScene;

		//New scene set
		currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));

	}

	//Fishing check
	if (playerData->fishing == true)
	{
		gameState->setCurrentState(State::FISHING);
	}

	//PUZZLE CHECK
	if (playerData->puzzle == true)
	{
		gameState->setCurrentState(State::PUZZLE);

		audio->stopAllMusic();
		audio->stopAllSounds();
	}


	//Initialise night sequence
	if (playerData->nightInit == false && playerData->isDay == false)
	{
		playerData->nightInit = true;

		Scene* gateScene = sceneManager->getNamedScene(SceneNames::GATE);

		currentScene = gateScene;

		//sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData);

		currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));

		map->update(dt, currentScene->getSceneData().sceneName);

		audio->playMusicbyName("nightAmb");
		audio->getMusic()->setLoop(true);
		audio->getMusic()->setVolume(20);

		//LOCK INTO BAD ENDING IF TASKS NOT COMPLETED; SKIP NIGHT SEQUENCE
		if (playerData->dayProgress < 6 && playerData->day == 6)
		{
			{
				playerData->startDay();

				audio->stopAllMusic();
				audio->stopAllSounds();

				Scene* newScene = sceneManager->getNamedScene(SceneNames::PATH1);
				currentScene = newScene;

				audio->playSoundbyName("footsteps");
				input->setLeftMouse(Input::MouseState::UP);	//Reset mouse state

				currentScene->setSceneData(sceneManager->getDataManager().updateSceneData(currentScene->getSceneData().sceneName, playerData));

				playerData->transition = true;

				dayText.setString("Day " + std::to_string(playerData->day));
			}
		}
		
	}

	//Transition check
	if (playerData->transition == true && audio->getSound("footsteps")->getStatus() == sf::SoundSource::Status::Stopped && audio->getSound("explode")->getStatus() == sf::SoundSource::Status::Stopped)
	{
		
		if (currentScene->getSceneData().sceneName == SceneNames::TAVERN)
		{
			audio->playMusicbyName("seasideTavern");
			audio->getMusic()->setVolume(20);
			audio->getMusic()->setLoop(true);
		}

		else if (playerData->isDay == false && audio->getMusic()->getStatus() == sf::SoundSource::Status::Stopped)
		{
			audio->playMusicbyName("nightAmb");
			audio->getMusic()->setLoop(true);
			audio->getMusic()->setVolume(20);
		}

		playerData->transition = false;
		map->update(dt, currentScene->getSceneData().sceneName);
	}

	//Objects updated

	cursor.update(dt);

	currentScene->update(dt);

	//COLLISION CHECKS
	if (playerData->transition == false && playerData->talking == false)
	{
		cursor.collisionResponses(currentScene);
	}

}

void PACLevel::render()
{
	//Only draw when not transitioning
	if (playerData->transition == false)
	{
		beginDraw();

		currentScene->render(playerData);

		window->draw(cursor);

		if (playerData->isDay)
		{
			window->draw(dayText);
		}

		else
		{
			if (map->isAlive())
			{
				window->draw(*map);
			}

			if (playerData->mapHint)
			{
				window->draw(mapText);
			}
		}
		
		endDraw();
	}

	//Black screen while player moves
	else
	{
		window->clear(sf::Color::Black);

		beginDraw();

		endDraw();
	}
}
