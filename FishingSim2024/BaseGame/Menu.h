#pragma once
#include "BaseClasses/Level.h"
#include "Cursor.h"
#include "PlayerData.h"
#include "MenuButton.h"
#include "ResetButton.h"


class Menu : public Level
{
public:
	Menu(sf::RenderWindow* wind, Input* in, GameState* gs, SoundManager* aud, PlayerData* pd);
	~Menu();

	void handleInput(float dt) override;
	void update(float dt) override;

	void render() override;

	void initMusic();


private:

	Cursor cursor;
	PlayerData* playerData;
	MenuButton menuButton;
	ResetButton resetButton;

	sf::Text dayText;
	sf::Texture texture;
	sf::Sprite background;
	sf::Font font;

};

