#pragma once

#include "BaseClasses/Level.h"
#include "Cursor.h"
#include "PlayerData.h"

class GoodEnd : public Level
{
public:

	GoodEnd(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd);
	~GoodEnd();

	void handleInput(float dt) override;
	void update(float dt) override;

	void render() override;

private:

	Cursor cursor;
	PlayerData* playerData;

	sf::Text text;
	sf::Font font;
	GameObject background;
	sf::Texture goodEndTexture;

};



