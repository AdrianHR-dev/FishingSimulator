#pragma once

#include "PuzzleNames.h"
#include "BasePuzzle.h"
#include "PlayerData.h"
#include "BaseClasses/Input.h"
#include "BaseClasses/GameState.h"
#include "BaseClasses/SoundManager.h"
#include "SFML/Graphics.hpp"
#include "TileMap.h"
#include "HelpButton.h"
#include "Cursor.h"

class SlidePuzzle : public BasePuzzle
{	

public:
	SlidePuzzle(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* player);
	~SlidePuzzle();

	void update(float dt) override;
	void handleInput(float dt) override;
	void render() override;

	void winCheck();


private:

	PuzzleNames name;

	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	SoundManager* audio;
	PlayerData* playerData;
	bool complete;

	sf::RectangleShape background;
	sf::Texture texture;
	sf::Texture helpTexture;
	Cursor cursor;
	TileMap* tileMap;
	HelpButton helpButton;

};