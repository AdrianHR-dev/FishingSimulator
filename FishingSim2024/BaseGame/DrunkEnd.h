#pragma once

#include "BaseClasses/Level.h"
#include "Cursor.h"
#include "PlayerData.h"

class DrunkEnd : public Level
{
public:

	DrunkEnd(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd);
	~DrunkEnd();

	void handleInput(float dt) override;
	void update(float dt) override;

	void render() override;

private:

	Cursor cursor;
	PlayerData* playerData;

	sf::Text dayText;
	sf::Font font;
	GameObject background;
	sf::Texture sceneTexture;

};
