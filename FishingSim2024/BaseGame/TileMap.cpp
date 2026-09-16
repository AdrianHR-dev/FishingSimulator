#include "TileMap.h"
#include <iostream>

TileMap::TileMap(sf::RenderWindow* wind)
{

	window = wind;

	for (int i = 0; i < 9; i++)
	{
		tiles.push_back(new Tile());

		if (i < 3)
		{
			tiles[i]->setPosition(sf::Vector2f(100.0f + (i * 150) + (5*i), 150.0f ));
		}

		else if (i < 6)
		{
			tiles[i]->setPosition(sf::Vector2f(100.0f + ((i-3) * 150) + (5 * (i-3)), 305.0f));
		}

		else
		{
			tiles[i]->setPosition(sf::Vector2f(100.0f + ((i-6) * 150) + (5 * (i-6)), 460.0f));
		}
	}

	//START MAP IDS SHOULD LOOK AS FOLLOWS:
	//4 7 0
	//5 6 1
	//2 3 8

	tiles[0]->tileTexture.loadFromFile("gfx/Puzzles/SlidePuzzleTiles/Tile5.png");
	tiles[0]->setTexture(&tiles[0]->tileTexture);
	tiles[0]->id = 4;
	tiles[0]->setSize(sf::Vector2f(0.f, 0.0f));
	tiles[0]->setCollisionBox(0, 0, 0, 0);

	tiles[1]->tileTexture.loadFromFile("gfx/Puzzles/SlidePuzzleTiles/Tile8.png");
	tiles[1]->setTexture(&tiles[1]->tileTexture);
	tiles[1]->id = 7;
	tiles[1]->setSize(sf::Vector2f(150.f, 150.0f));
	tiles[1]->setCollisionBox(0, 0, 150, 150);

	tiles[2]->tileTexture.loadFromFile("gfx/Puzzles/SlidePuzzleTiles/Tile1.png");
	tiles[2]->setTexture(&tiles[2]->tileTexture);
	tiles[2]->id = 0;
	tiles[2]->setSize(sf::Vector2f(150.f, 150.0f));
	tiles[2]->setCollisionBox(0, 0, 150, 150);

	tiles[3]->tileTexture.loadFromFile("gfx/Puzzles/SlidePuzzleTiles/Tile6.png");
	tiles[3]->setTexture(&tiles[3]->tileTexture);
	tiles[3]->id = 5;
	tiles[3]->setSize(sf::Vector2f(150.f, 150.0f));
	tiles[3]->setCollisionBox(0, 0, 150, 150);

	tiles[4]->tileTexture.loadFromFile("gfx/Puzzles/SlidePuzzleTiles/Tile7.png");
	tiles[4]->setTexture(&tiles[4]->tileTexture);
	tiles[4]->id = 6;
	tiles[4]->setSize(sf::Vector2f(150.f, 150.0f));
	tiles[4]->setCollisionBox(0, 0, 150, 150);

	tiles[5]->tileTexture.loadFromFile("gfx/Puzzles/SlidePuzzleTiles/Tile2.png");
	tiles[5]->setTexture(&tiles[5]->tileTexture);
	tiles[5]->id = 1;
	tiles[5]->setSize(sf::Vector2f(150.f, 150.0f));
	tiles[5]->setCollisionBox(0, 0, 150, 150);

	tiles[6]->tileTexture.loadFromFile("gfx/Puzzles/SlidePuzzleTiles/Tile3.png");
	tiles[6]->setTexture(&tiles[6]->tileTexture);
	tiles[6]->id = 2;
	tiles[6]->setSize(sf::Vector2f(150.f, 150.0f));
	tiles[6]->setCollisionBox(0, 0, 150, 150);

	tiles[7]->tileTexture.loadFromFile("gfx/Puzzles/SlidePuzzleTiles/Tile4.png");
	tiles[7]->setTexture(&tiles[7]->tileTexture);
	tiles[7]->id = 3;
	tiles[7]->setSize(sf::Vector2f(150.f, 150.0f));
	tiles[7]->setCollisionBox(0, 0, 150, 150);

	tiles[8]->tileTexture.loadFromFile("gfx/Puzzles/SlidePuzzleTiles/Tile9.png");
	tiles[8]->setTexture(&tiles[8]->tileTexture);
	tiles[8]->id = 8;
	tiles[8]->setSize(sf::Vector2f(150.f, 150.0f));
	tiles[8]->setCollisionBox(0, 0, 150, 150);

}

TileMap::~TileMap()
{

}

void TileMap::update(float dt)
{

}

void TileMap::handleInput(float dt)
{

}

void TileMap::render()
{
	for (int i = 0; i < 9; i++)
	{
		window->draw(*tiles[i]);
	}
}

bool TileMap::TileMovement(int tileNum)
{
	//BLANK TILE HAS ID 4
	//Can tile move down?
	if (tileNum < 6)
	{
		if (tiles[tileNum + 3]->id == 4)
		{
			TileSwap(tileNum, tileNum + 3);

			return true;
		}
	}

	//Can tile move up?

	if (tileNum > 2)
	{

		if (tiles[tileNum - 3]->id == 4)
		{
			TileSwap(tileNum, tileNum - 3);

			return true;
		}
	}


	//Can tile move left?

	if (tileNum != 0 && tileNum != 3 && tileNum != 6)
	{

		if (tiles[tileNum - 1]->id == 4)
		{
			TileSwap(tileNum, tileNum - 1);

			return true;
		}
	}

	//Can tile move right?

	if (tileNum != 2 && tileNum != 5 && tileNum != 8)
	{

		if (tiles[tileNum + 1]->id == 4)
		{
			TileSwap(tileNum, tileNum + 1);

			return true;
		}
	}

	return false;
}

void TileMap::TileSwap(int t1, int t2)
{
	//Tiles swapped
	Tile tempTile1;
	Tile tempTile2;

	tempTile1.tileTexture = tiles[t1]->tileTexture;
	tempTile1.id = tiles[t1]->id;
	tempTile1.setSize(tiles[t1]->getSize());
	tempTile1.setCollisionBox(0, 0, tiles[t1]->getCollisionBox().width, tiles[t1]->getCollisionBox().height);

	tempTile2.tileTexture = tiles[t2]->tileTexture;
	tempTile2.id = tiles[t2]->id;
	tempTile2.setSize(tiles[t2]->getSize());
	tempTile2.setCollisionBox(0, 0, tiles[t2]->getCollisionBox().width, tiles[t2]->getCollisionBox().height);

	tiles[t1]->tileTexture = tempTile2.tileTexture;
	tiles[t1]->id = tempTile2.id;
	tiles[t1]->setSize(tempTile2.getSize());
	tiles[t1]->setCollisionBox(0, 0, tempTile2.getCollisionBox().width, tempTile2.getCollisionBox().height);

	tiles[t2]->tileTexture = tempTile1.tileTexture;
	tiles[t2]->id = tempTile1.id;
	tiles[t2]->setSize(tempTile1.getSize());
	tiles[t2]->setCollisionBox(0, 0, tempTile1.getCollisionBox().width, tempTile1.getCollisionBox().height);
	
}

