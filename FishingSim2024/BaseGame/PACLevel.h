#pragma once
#include "BaseClasses/Level.h"
#include "SceneManager.h"
#include "Cursor.h"
#include "PlayerData.h"
#include "Map.h"


class PACLevel : public Level
{
public:

	PACLevel(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd);
	~PACLevel();

	void handleInput(float dt) override;
	void update(float dt) override;

	void render() override;



private:

	Scene* currentScene;
	SceneManager* sceneManager;
	Cursor cursor;
	PlayerData* playerData;
	Map* map;

	sf::Text dayText;
	sf::Font font;
	sf::Text mapText;
	float mapTimer;

};

