#pragma once

#include "BaseClasses/Level.h"
#include "BaseClasses/Animation.h"
#include "Cursor.h"
#include "PlayerData.h"

class Cutscene : public Level
{
public:

	Cutscene(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd);
	~Cutscene();

	void handleInput(float dt) override;
	void update(float dt) override;

	void render() override;

private:

	Cursor cursor;
	PlayerData* playerData;

	sf::Text text;
	sf::Font font;
	GameObject background;
	sf::Texture cutsceneTexture;
	Animation cutsceneAnim;
	bool init;

};



