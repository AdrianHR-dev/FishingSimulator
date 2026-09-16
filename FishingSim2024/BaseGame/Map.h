#pragma once

#include "BaseClasses/GameObject.h"
#include "BaseClasses/Animation.h"
#include "SceneNames.h"


class Map : public GameObject
{
public:

	Map();
	~Map();

	void update(float dt, SceneNames currScene);
	void handleInput(float dt);

private:

	sf::Texture mapTexture;

	Animation gate;
	Animation alley;
	Animation corner;
	Animation crossroads;
	Animation backstreet;
	Animation crossroad2;
	Animation mainStreet;
	Animation supermarket;
	Animation trainStation;
	Animation park;
	Animation waterfront;
	Animation forestPath;
	Animation bar;

};