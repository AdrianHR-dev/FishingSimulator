#pragma once

#include "PuzzleNames.h"
#include "BasePuzzle.h"
#include "PlayerData.h"
#include "BaseClasses/Input.h"
#include "BaseClasses/GameState.h"
#include "BaseClasses/SoundManager.h"
#include "SFML/Graphics.hpp"
#include "NumberButton.h"
#include "HelpButton.h"
#include "Cursor.h"

class MagicSquare : public BasePuzzle
{

public:
	MagicSquare(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* player);
	~MagicSquare();

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
	std::vector<NumberButton*> buttons;
	sf::Texture texture;
	sf::Texture helpTexture;
	Cursor cursor;
	HelpButton helpButton;
};