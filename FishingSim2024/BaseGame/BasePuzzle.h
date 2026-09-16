#pragma once

#include "PuzzleNames.h"
#include "PlayerData.h"
#include "BaseClasses/Input.h"
#include "BaseClasses/GameState.h"
#include "BaseClasses/SoundManager.h"
#include "SFML/Graphics.hpp"
#include "BaseClasses/Level.h"
#include "Cursor.h"

class BasePuzzle 
{

public:

	BasePuzzle();
	BasePuzzle(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* player);
	~BasePuzzle();

	virtual void update(float dt);
	virtual void handleInput(float dt);
	virtual void render();

protected:

	PuzzleNames name;

	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	SoundManager* audio;
	PlayerData* playerData;

	sf::RectangleShape background;
	sf::Texture texture;
	Cursor cursor;

	bool help;
};
