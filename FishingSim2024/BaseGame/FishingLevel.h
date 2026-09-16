#pragma once
#include "BaseClasses/Level.h"
#include "BaseClasses/GameObject.h"
#include "PlayerData.h"
#include "Cursor.h"
#include "Fish.h"

class FishingLevel : public Level
{
public:

	FishingLevel(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd);
	~FishingLevel();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;



private:

	Cursor cursor;
	PlayerData* playerData;
	sf::Texture sceneTexture;
	GameObject background;
	Fish fish;

};

