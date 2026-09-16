#include "Scene.h"

#include "TestScene.h"
#include "DayScenes.h"
#include "NightScenes.h"

Scene::Scene(sf::RenderWindow* wind, SoundManager* aud)
{
	//Initialise important variables for background
	setPosition(sf::Vector2f(0.0f, 0.0f));
	setSize(sf::Vector2f(700.0f, 700.0f));

	window = wind;
	audio = aud;

	Path1 p1;

	currentSceneData = p1;
}

Scene::~Scene()
{

}

void Scene::handleInput(float dt)
{

}

void Scene::update(float dt)
{
	for (const auto& i : currentSceneData.characters)
	{
		i.second->update(dt);
	}

	for (auto& i : currentSceneData.items)
	{
		i.second->update(dt);
	}
}


SceneNames Scene::getNewScene(MoveDirection moveDir)
{
	//Get new scene to travel to
	
	//DETERMINE AUDIO STATE FOR SCENE TO BE LOADED

	if ((currentSceneData.neighbouringScenes[moveDir] == DAM || currentSceneData.neighbouringScenes[moveDir] == BRIDGE))
	{
		audio->playMusicbyName("water");
		audio->getMusic()->setVolume(100);
		audio->getMusic()->setLoop(true);
	}

	else if(currentSceneData.neighbouringScenes[moveDir] == SceneNames::PATH6 || currentSceneData.neighbouringScenes[moveDir] == SceneNames::PATH4)
	{
		audio->stopAllMusic();
	}

	return currentSceneData.neighbouringScenes[moveDir];

}

void Scene::render(PlayerData* pd)
{
	window->draw(*this);

	for (const auto i : currentSceneData.characters)
	{
		//Draw characters
	

		if (pd->talking == false)
		{
			if (pd->day >= 6 && pd->isDay && i.second->getCharName() == CharacterName::DAN)
			{
			
			}

			else
			{
				window->draw(*i.second);
			}
			
		}

		if (i.second->getTalking())
		{
			if (pd->day == 6 && pd->isDay)
			{

			}

			else
			{
				window->draw(*i.second);
			}

			window->draw(*i.second->getDialogue());
			window->draw(*i.second->getDialogue()->getName());
			window->draw(*i.second->getDialogue()->getText());

		}
	}
	//Draw items
	for (const auto i : currentSceneData.items)
	{
		if (pd->talking == false)
		{
			window->draw(*i.second);
		}
	
		if (i.second->getTalking())
		{
			window->draw(*i.second);

			window->draw(*i.second->getDialogue());
			window->draw(*i.second->getDialogue()->getName());
			window->draw(*i.second->getDialogue()->getText());
		}
	}
}

