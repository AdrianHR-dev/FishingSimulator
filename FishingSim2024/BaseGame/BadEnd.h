#pragma once

#include "BaseClasses/Level.h"
#include "Cursor.h"
#include "PlayerData.h"

class BadEnd : public Level
{
public:

	BadEnd(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd);
	~BadEnd();

	void handleInput(float dt) override;
	void update(float dt) override;

	void render() override;

private:

	Cursor cursor;
	PlayerData* playerData;

	sf::Text text;
	sf::Font font;
	GameObject background;
	sf::Texture sceneTexture;
	sf::Texture badEndTexture;
	bool init;

};



