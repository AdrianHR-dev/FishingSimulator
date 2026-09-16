#pragma once

#include "SceneDataManager.h"
#include "Scene.h"
#include "BaseClasses/SoundManager.h"

struct SceneManager
{
public:

	SceneManager(sf::RenderWindow* wind, SoundManager* aud)
	{
		window = wind;
		audio = aud;

		testScene = new Scene(window, aud);
		testScene2 = new Scene(window, aud);
		testScene3 = new Scene(window, aud);

		path1 = new Scene(window, aud);
		path2 = new Scene(window, aud);
		path3 = new Scene(window, aud);
		path4 = new Scene(window, aud);
		path5 = new Scene(window, aud);
		path6 = new Scene(window, aud);
		bridge = new Scene(window, aud);
		dam = new Scene(window, aud);

		//NIGHT SCENES

		gate = new Scene(window, aud);
		alley = new Scene(window, aud);
		corner = new Scene(window, aud);
		crossroad1 = new Scene(window, aud);
		backstreet = new Scene(window, aud);
		crossroad2 = new Scene(window, aud);
		supermarket = new Scene(window, aud);
		trainstation = new Scene(window, aud);
		park = new Scene(window, aud);
		mainstreet = new Scene(window, aud);
		waterfront = new Scene(window, aud);
		tavern = new Scene(window, aud);
		forestGate = new Scene(window, aud);

		forestPath = new Scene(window, aud);
		forestBuilding = new Scene(window, aud);
		hydroDoor = new Scene(window, aud);

		dark = new Scene(window, aud);

		corpse = new Scene(window, aud);

		end1 = new Scene(window, aud);
		end2 = new Scene(window, aud);

		//Textures loaded and set
		initTextures();

		//Scene data set from data manager
		testScene->setSceneData(sdm.getSceneData(TESTSCENE));
		testScene2->setSceneData(sdm.getSceneData(TESTSCENE2));
		testScene3->setSceneData(sdm.getSceneData(TESTSCENE3));

		path1->setSceneData(sdm.getSceneData(PATH1));
		path2->setSceneData(sdm.getSceneData(PATH2));
		path3->setSceneData(sdm.getSceneData(PATH3));
		path4->setSceneData(sdm.getSceneData(PATH4));
		path5->setSceneData(sdm.getSceneData(PATH5));
		path6->setSceneData(sdm.getSceneData(PATH6));
		bridge->setSceneData(sdm.getSceneData(BRIDGE));
		dam->setSceneData(sdm.getSceneData(DAM));

		//NIGHT SCENES

		gate->setSceneData(sdm.getSceneData(GATE));
		alley->setSceneData(sdm.getSceneData(ALLEY));
		corner->setSceneData(sdm.getSceneData(CORNER));
		crossroad1->setSceneData(sdm.getSceneData(CROSSROAD1));
		crossroad2->setSceneData(sdm.getSceneData(CROSSROAD2));
		backstreet->setSceneData(sdm.getSceneData(BACKSTREET));
		supermarket->setSceneData(sdm.getSceneData(SUPERMARKET));
		trainstation->setSceneData(sdm.getSceneData(TRAINSTATION));
		park->setSceneData(sdm.getSceneData(PARK));
		mainstreet->setSceneData(sdm.getSceneData(MAINSTREET));
		waterfront->setSceneData(sdm.getSceneData(WATERFRONT));
		tavern->setSceneData(sdm.getSceneData(TAVERN));
		forestGate->setSceneData(sdm.getSceneData(FORESTGATE));

		forestPath->setSceneData(sdm.getSceneData(FORESTPATH));
		forestBuilding->setSceneData(sdm.getSceneData(FORESTBUILDING));
		hydroDoor->setSceneData(sdm.getSceneData(HYDRODOOR));

		dark->setSceneData(sdm.getSceneData(DARK));

		corpse->setSceneData(sdm.getSceneData(CORPSE));

		end1->setSceneData(sdm.getSceneData(END1));
		end2->setSceneData(sdm.getSceneData(END2));

		//Scenes added to map

		scenes[TESTSCENE] = testScene;
		scenes[TESTSCENE2] = testScene2;
		scenes[TESTSCENE3] = testScene3;
		scenes[PATH1] = path1;
		scenes[PATH2] = path2;
		scenes[PATH3] = path3;
		scenes[PATH4] = path4;
		scenes[PATH5] = path5;
		scenes[PATH6] = path6;
		scenes[BRIDGE] = bridge;
		scenes[DAM] = dam;


		scenes[GATE] = gate;
		scenes[ALLEY] = alley;
		scenes[CORNER] = corner;
		scenes[CROSSROAD1] = crossroad1;
		scenes[CROSSROAD2] = crossroad2;
		scenes[BACKSTREET] = backstreet;
		scenes[SUPERMARKET] = supermarket;
		scenes[TRAINSTATION] = trainstation;
		scenes[PARK] = park;
		scenes[MAINSTREET] = mainstreet;
		scenes[TAVERN] = tavern;
		scenes[WATERFRONT] = waterfront;
		scenes[FORESTGATE] = forestGate;

		scenes[FORESTPATH] = forestPath;
		scenes[FORESTBUILDING] = forestBuilding;
		scenes[HYDRODOOR] = hydroDoor;

		scenes[DARK] = dark;

		scenes[CORPSE] = corpse;

		scenes[END1] = end1;
		scenes[END2] = end2;
	};

private:

	SceneDataManager sdm;

	sf::RenderWindow* window;
	SoundManager* audio;

	std::map<SceneNames, Scene*> scenes;

	//Scenes and data created
	Scene* testScene;
	Scene* testScene2;
	Scene* testScene3;

	//DAY SCENES
	Scene* path1;
	Scene* path2;
	Scene* path3;
	Scene* path4;
	Scene* path5;
	Scene* path6;

	Scene* bridge;
	Scene* dam;

	//NIGHT SCENES
	
	Scene* gate;
	Scene* alley;
	Scene* corner;
	Scene* crossroad1;
	Scene* crossroad2;
	Scene* backstreet;
	Scene* supermarket;
	Scene* trainstation;
	Scene* park;
	Scene* mainstreet;
	Scene* tavern;
	Scene* waterfront;
	Scene* forestGate;

	Scene* forestPath;
	Scene* forestBuilding;
	Scene* hydroDoor;

	Scene* dark;

	Scene* corpse;

	Scene* end1;
	Scene* end2;

	//TEXTURES

	sf::Texture testSceneT;
	sf::Texture test2SceneT;
	sf::Texture test3SceneT;

	sf::Texture path1T;
	sf::Texture path2T;
	sf::Texture path3T;
	sf::Texture path4T;
	sf::Texture path5T;
	sf::Texture path6T;
	sf::Texture bridgeT;
	sf::Texture damT;

	//NIGHT SCENE TEXTURES

	sf::Texture gateT;
	sf::Texture alleyT;
	sf::Texture cornerT;
	sf::Texture crossroadT1;
	sf::Texture crossroadT2;
	sf::Texture backstreetT;
	sf::Texture supermarketT;
	sf::Texture trainstationT;
	sf::Texture parkT;
	sf::Texture mainstreetT;
	sf::Texture tavernT;
	sf::Texture waterfrontT;
	sf::Texture forestGateT;
	sf::Texture forestPathT;
	sf::Texture forestBuildingT;
	sf::Texture hydroDoorT;

	sf::Texture darkT;
	sf::Texture corpseT;

	sf::Texture end1T;
	sf::Texture end2T;


	void initTextures()
	{
		testSceneT.loadFromFile("gfx/Scenes/test.png");
		test2SceneT.loadFromFile("gfx/Scenes/test2.png");
		test3SceneT.loadFromFile("gfx/Scenes/test3.png");

		path1T.loadFromFile("gfx/Scenes/path1.png");
		path2T.loadFromFile("gfx/Scenes/path2.png");
		path3T.loadFromFile("gfx/Scenes/path3.png");
		path4T.loadFromFile("gfx/Scenes/path4.png");
		path5T.loadFromFile("gfx/Scenes/path5.png");
		path6T.loadFromFile("gfx/Scenes/path6.png");
		bridgeT.loadFromFile("gfx/Scenes/bridge.png");
		damT.loadFromFile("gfx/Scenes/dam.png");

		//NIGHT TEXTURES LOADED
		gateT.loadFromFile("gfx/Scenes/gate.png");
		alleyT.loadFromFile("gfx/Scenes/alley.png");
		cornerT.loadFromFile("gfx/Scenes/corner.png");
		crossroadT1.loadFromFile("gfx/Scenes/crossroads.png");
		crossroadT2.loadFromFile("gfx/Scenes/crossroad2.png");
		backstreetT.loadFromFile("gfx/Scenes/backstreet.png");
		supermarketT.loadFromFile("gfx/Scenes/shop.png");
		trainstationT.loadFromFile("gfx/Scenes/trainstation.png");
		parkT.loadFromFile("gfx/Scenes/park.png");
		mainstreetT.loadFromFile("gfx/Scenes/mainstreet.png");
		tavernT.loadFromFile("gfx/Scenes/pub.png");
		waterfrontT.loadFromFile("gfx/Scenes/waterfront.png");
		forestGateT.loadFromFile("gfx/Scenes/forestGate.png");

		forestPathT.loadFromFile("gfx/Scenes/forestPath.png");
		forestBuildingT.loadFromFile("gfx/Scenes/forestBuilding.png");
		hydroDoorT.loadFromFile("gfx/Scenes/hydroDoor.png");

		darkT.loadFromFile("gfx/Scenes/dark.png");

		corpseT.loadFromFile("gfx/Scenes/corpse.png");

		end1T.loadFromFile("gfx/Scenes/end1.png");


		end2T.loadFromFile("gfx/Scenes/end2.png");

		end1->setTexture(&end1T);
		end2->setTexture(&end2T);

		//Scenes textures set
		testScene->setTexture(&testSceneT);
		testScene2->setTexture(&test2SceneT);
		testScene3->setTexture(&test3SceneT);

		//DAY SCENE TEXTURES
		path1->setTexture(&path1T);
		path2->setTexture(&path2T);
		path3->setTexture(&path3T);
		path4->setTexture(&path4T);
		path5->setTexture(&path5T);
		path6->setTexture(&path6T);
		bridge->setTexture(&bridgeT);
		dam->setTexture(&damT);

		//NIGHT SCENE TEXTURES

		gate->setTexture(&gateT);
		alley->setTexture(&alleyT);
		corner->setTexture(&cornerT);
		crossroad1->setTexture(&crossroadT1);
		crossroad2->setTexture(&crossroadT2);
		backstreet->setTexture(&backstreetT);
		supermarket->setTexture(&supermarketT);
		trainstation->setTexture(&trainstationT);
		park->setTexture(&parkT);
		mainstreet->setTexture(&mainstreetT);
		tavern->setTexture(&tavernT);
		waterfront->setTexture(&waterfrontT);
		forestGate->setTexture(&forestGateT);

		forestPath->setTexture(&forestPathT);
		forestBuilding->setTexture(&forestBuildingT);
		hydroDoor->setTexture(&hydroDoorT);

		dark->setTexture(&darkT);

		corpse->setTexture(&corpseT);
	}

public:
	SceneDataManager getDataManager()
	{
		return sdm;
	}

	Scene* getNamedScene(SceneNames name)
	{
		return scenes.at(name);
	}
};

