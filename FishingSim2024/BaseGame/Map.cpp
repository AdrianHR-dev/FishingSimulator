#include "Map.h"

Map::Map()
{
	mapTexture.loadFromFile("gfx/map.png");
	setTexture(&mapTexture);

	gate.addFrame(sf::IntRect(0, 0, 100, 100));
	alley.addFrame(sf::IntRect(100, 0, 100, 100));
	corner.addFrame(sf::IntRect(200, 0, 100, 100));
	crossroads.addFrame(sf::IntRect(300, 0, 100, 100));
	backstreet.addFrame(sf::IntRect(0, 100, 100, 100));
	crossroad2.addFrame(sf::IntRect(100, 100, 100, 100));
	trainStation.addFrame(sf::IntRect(200, 100, 100, 100));
	supermarket.addFrame(sf::IntRect(300, 100, 100, 100));
	park.addFrame(sf::IntRect(0, 200, 100, 100));
	mainStreet.addFrame(sf::IntRect(100, 200, 100, 100));
	bar.addFrame(sf::IntRect(200, 200, 100, 100));
	waterfront.addFrame(sf::IntRect(300, 200, 100, 100));
	forestPath.addFrame(sf::IntRect(0, 300, 100, 100));

	setSize(sf::Vector2f(300, 300));
	setPosition(sf::Vector2f(400, 0));

}

Map::~Map()
{

}

void Map::update(float dt, SceneNames currScene)
{

	//Map updated
	switch (currScene)
	{
	case(SceneNames::GATE):
	{
		gate.animate(0);
		setTextureRect(gate.getCurrentFrame());

	};	break;

	case(SceneNames::ALLEY):
	{

		alley.animate(0);
		setTextureRect(alley.getCurrentFrame());
	};	break;

	case(SceneNames::CORNER):
	{

		corner.animate(0);
		setTextureRect(corner.getCurrentFrame());
	};	break;

	case(SceneNames::CROSSROAD1):
	{
		crossroads.animate(0);
		setTextureRect(crossroads.getCurrentFrame());
	};	break;

	case(SceneNames::CROSSROAD2):
	{
		crossroad2.animate(0);
		setTextureRect(crossroad2.getCurrentFrame());
	};	break;

	case(SceneNames::SUPERMARKET):
	{

		supermarket.animate(0);
		setTextureRect(supermarket.getCurrentFrame());
	};	break;

	case(SceneNames::TRAINSTATION):
	{

		trainStation.animate(0);
		setTextureRect(trainStation.getCurrentFrame());
	};	break;

	case(SceneNames::PARK):
	{
		park.animate(0);
		setTextureRect(park.getCurrentFrame());
	};	break;

	case(SceneNames::MAINSTREET):
	{
		crossroad2.animate(0);
		setTextureRect(mainStreet.getCurrentFrame());
	};	break;

	case(SceneNames::WATERFRONT):
	{
		waterfront.animate(0);
		setTextureRect(waterfront.getCurrentFrame());
	};	break;

	case(SceneNames::BACKSTREET):
	{
		backstreet.animate(0);
		setTextureRect(backstreet.getCurrentFrame());
	};	break;

	case(SceneNames::TAVERN):
	{
		bar.animate(0);
		setTextureRect(bar.getCurrentFrame());
	};	break;

	case(SceneNames::FORESTGATE):
	{
		forestPath.animate(0);
		setTextureRect(forestPath.getCurrentFrame());
	};	break;

	}
}

void Map::handleInput(float dt)
{

}
