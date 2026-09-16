#pragma once
#include "SceneData.h"
#include "TestScene.h"
#include "DayScenes.h"
#include "NightScenes.h"


class SceneDataManager
{
public:

	SceneDataManager();
	~SceneDataManager();

	SceneData* getSceneData(SceneNames sn);
	SceneData* updateSceneData(SceneNames sn, PlayerData* pd);

private:

	TestScene* tsd;
	TestScene2* tsd2;
	TestScene3* tsd3;

	Path1* p1;
	Path2* p2;
	Path3* p3;
	Path4* p4;
	Path5* p5;
	Path6* p6;

	Bridge* bridge;

	Dam* dam;

	//NIGHT SCENES

	Gate* gate;
	Alley* alley;
	Corner* corner;
	Crossroad1* crossroad1;
	Crossroad2* crossroad2;
	Backstreet* backstreet;
	Supermarket* supermarket;
	TrainStation* trainStation;
	Park* park;
	MainStreet* mainStreet;
	Tavern* tavern;
	Waterfront* waterfront;
	ForestGate* forestGate;

	ForestPath* forestPath;
	ForestBuilding* forestBuilding;
	HydroDoor* hydroDoor;

	Dark* dark;

	Corpse* corpse;

	End1* end1;
	End2* end2;
};


