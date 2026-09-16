#pragma once

#include <SFML/Graphics.hpp>
#include "Input.h"
#include "SoundManager.h"
#include "GameState.h"
#include <string>
#include <iostream>


//Standard class that all your levels and scenes and such can inherit from
//Depends on the type of game your making i suppose.... 
//For our current project I'm thinking more "scenes" than levels but I like to keep my options wide
//Level is such a broooaaaaad word really 
//I like it

class Level
{
public:
	Level();
	~Level();

	//standard game loop functions for level, these can be overridden by YOU again chum
	virtual void handleInput(float dt) = 0;
	virtual void update(float dt) = 0;
	virtual void render() = 0;

protected:
	//Render level to screen
	void beginDraw();
	void endDraw();

	//Al necessary variables for your default level
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	SoundManager* audio;
};

