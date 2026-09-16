#pragma once
#include "BaseClasses/GameObject.h"
#include "SFML/Graphics.hpp"
#include "vector"

class Tile : public GameObject
{
public:
	
	Tile()
	{
		id = 0;
	}

	~Tile()
	{
	
	}

	int id;
	sf::Texture tileTexture;
};

class TileMap : public GameObject
{
public:

	TileMap(sf::RenderWindow* wind);
	~TileMap();

	void update(float dt) override;
	void handleInput(float dt) override;
	void render();

	bool TileMovement(int tileNum);
	void TileSwap(int t1, int t2);

	Tile* getTile(int i)
	{
		return tiles[i];
	}

private:

	std::vector<Tile*> tiles;
	sf::RenderWindow* window;
	sf::Texture texture;

};