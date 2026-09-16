#pragma once

#include "BaseClasses/GameObject.h"
#include "SceneData.h"
#include "PlayerData.h"
#include "MoveZone.h"
#include "MoveDirection.h"
#include "BaseClasses/SoundManager.h"

#include "SceneNames.h"

class Scene : public GameObject
{
public:

	Scene(sf::RenderWindow* wind, SoundManager* aud);
	~Scene();

	void handleInput(float dt);
	void update(float dt);
	void render(PlayerData* pd);

	SceneData getSceneData()
	{
		return currentSceneData;
	}

	void setSceneData(SceneData* sd)
	{
		currentSceneData = *sd;
	}

	SceneNames getNewScene(MoveDirection moveDir);


protected:

	//sf::Texture sceneTexture;
	SceneData currentSceneData;
	SoundManager* audio;

};

