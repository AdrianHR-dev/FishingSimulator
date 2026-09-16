#include "SceneDataManager.h"

SceneDataManager::SceneDataManager()
{
	//Scene datas initialised
	tsd = new TestScene();
	tsd->init();

	tsd2 = new TestScene2();
	tsd2->init();
	
	tsd3 = new TestScene3();
	tsd3->init();

	//DAY SCENES
	p1 = new Path1();
	p1->init();

	p2 = new Path2();
	p2->init();

	p3 = new Path3();
	p3->init();

	p4 = new Path4();
	p4->init();

	p5 = new Path5();
	p5->init();

	p6 = new Path6();
	p6->init();

	bridge = new Bridge();
	bridge->init();

	dam = new Dam();
	dam->init();

	//NIGHT SCENES

	gate = new Gate();
	gate->init();

	alley = new Alley();
	alley->init();

	corner = new Corner();
	corner->init();

	crossroad1 = new Crossroad1();
	crossroad1->init();

	backstreet = new Backstreet();
	backstreet->init();

	crossroad2 = new Crossroad2();
	crossroad2->init();

	supermarket = new Supermarket();
	supermarket->init();

	trainStation = new TrainStation();
	trainStation->init();

	park = new Park();
	park->init();

	mainStreet = new MainStreet();
	mainStreet->init();

	tavern = new Tavern();
	tavern->init();

	waterfront = new Waterfront();
	waterfront->init();

	forestGate = new ForestGate();
	forestGate->init();

	forestPath = new ForestPath();
	forestPath->init();

	forestBuilding = new ForestBuilding();
	forestBuilding->init();

	hydroDoor = new HydroDoor();
	hydroDoor->init();

	dark = new Dark();
	dark->init();

	corpse = new Corpse();
	corpse->init();

	end1 = new End1();
	end1->init();

	end2 = new End2();
	end2->init();


}

SceneDataManager::~SceneDataManager()
{

}

SceneData* SceneDataManager::getSceneData(SceneNames sn)
{
	//Find and return correct scene dataset
	switch (sn)
	{

	case(SceneNames::TESTSCENE):
	{
		return tsd;
	};	break;

	case(SceneNames::TESTSCENE2):
	{
		return tsd2;
	};	break;

	case(SceneNames::TESTSCENE3):
	{
		return tsd3;
	};	break;

	case(SceneNames::PATH1):
	{
		return p1;
	};	break;

	case(SceneNames::PATH2):
	{
		return p2;
	};	break;

	case(SceneNames::PATH3):
	{
		return p3;
	};	break;

	case(SceneNames::PATH4):
	{
		return p4;
	};	break;

	case(SceneNames::PATH5):
	{
		return p5;
	};	break;

	case(SceneNames::PATH6):
	{
		return p6;
	};	break;

	case(SceneNames::BRIDGE):
	{
		return bridge;
	};	break;

	case(SceneNames::DAM):
	{
		return dam;
	};	break;

	//NIGHT SCENES
	case(SceneNames::GATE):
	{
		return gate;
	};	break;

	case(SceneNames::ALLEY):
	{
		return alley;
	};	break;

	case(SceneNames::CORNER):
	{
		return corner;
	};	break;

	case(SceneNames::CROSSROAD1):
	{
		return crossroad1;
	};	break;

	case(SceneNames::BACKSTREET):
	{
		return backstreet;
	};	break;

	case(SceneNames::CROSSROAD2):
	{
		return crossroad2;
	};	break;

	case(SceneNames::SUPERMARKET):
	{
		return supermarket;
	};	break;

	case(SceneNames::TRAINSTATION):
	{
		return trainStation;
	};	break;

	case(SceneNames::PARK):
	{
		return park;
	};	break;

	case(SceneNames::MAINSTREET):
	{
		return mainStreet;
	};	break;

	case(SceneNames::TAVERN):
	{
		return tavern;
	};	break;

	case(SceneNames::WATERFRONT):
	{
		return waterfront;
	};	break;

	case(SceneNames::FORESTGATE):
	{
		return forestGate;
	};	break;

	case(SceneNames::FORESTPATH):
	{
		return forestPath;
	};	break;

	case(SceneNames::FORESTBUILDING):
	{
		return forestBuilding;
	};	break;

	case(SceneNames::HYDRODOOR):
	{
		return hydroDoor;
	};	break;

	case(SceneNames::DARK):
	{
		return dark;
	};	break;

	case(SceneNames::CORPSE):
	{
		return corpse;
	};	break;

	case(SceneNames::END1):
	{
		return end1;
	};	break;

	case(SceneNames::END2):
	{
		return end2;
	};	break;
	
	}

	return tsd;

}

SceneData* SceneDataManager::updateSceneData(SceneNames sn, PlayerData* pd)
{
	//Find and return correct scene dataset
	switch (sn)
	{

	case(SceneNames::TESTSCENE):
	{
		tsd->updateData(pd);
		return tsd;
	};	break;

	case(SceneNames::TESTSCENE2):
	{
		tsd2->updateData(pd);
		return tsd2;
	};	break;

	case(SceneNames::TESTSCENE3):
	{
		tsd3->updateData(pd);
		return tsd3;
	};	break;

	case(SceneNames::PATH1):
	{
		p1->updateData(pd);
		return p1;
	};	break;

	case(SceneNames::PATH2):
	{
		p2->updateData(pd);
		return p2;
	};	break;

	case(SceneNames::PATH3):
	{
		p3->updateData(pd);
		return p3;
	};	break;

	case(SceneNames::PATH4):
	{
		p4->updateData(pd);
		return p4;
	};	break;

	case(SceneNames::PATH5):
	{
		p5->updateData(pd);
		return p5;
	};	break;

	case(SceneNames::PATH6):
	{
		p6->updateData(pd);
		return p6;
	};	break;

	case(SceneNames::BRIDGE):
	{
		bridge->updateData(pd);
		return bridge;

	};	break;

	case(SceneNames::DAM):
	{
		dam->updateData(pd);
		return dam;

	};	break;

	//NIGHT SCENES BELOW
	case(SceneNames::GATE):
	{
		gate->updateData(pd);
		return gate;

	};	break;

	case(SceneNames::ALLEY):
	{
		alley->updateData(pd);
		return alley;

	};	break;

	case(SceneNames::CORNER):
	{
		corner->updateData(pd);
		return corner;

	};	break;

	case(SceneNames::CROSSROAD1):
	{
		crossroad1->updateData(pd);
		return crossroad1;

	};	break;

	case(SceneNames::BACKSTREET):
	{
		backstreet->updateData(pd);
		return backstreet;

	};	break;

	case(SceneNames::CROSSROAD2):
	{
		crossroad2->updateData(pd);
		return crossroad2;

	};	break;

	case(SceneNames::SUPERMARKET):
	{
		supermarket->updateData(pd);
		return supermarket;

	};	break;

	case(SceneNames::TRAINSTATION):
	{
		trainStation->updateData(pd);
		return trainStation;

	};	break;

	case(SceneNames::PARK):
	{
		park->updateData(pd);
		return park;

	};	break;

	case(SceneNames::MAINSTREET):
	{
		mainStreet->updateData(pd);
		return mainStreet;

	};	break;

	case(SceneNames::TAVERN):
	{
		tavern->updateData(pd);
		return tavern;

	};	break;

	case(SceneNames::WATERFRONT):
	{
		waterfront->updateData(pd);
		return waterfront;

	};	break;

	case(SceneNames::FORESTGATE):
	{
		forestGate->updateData(pd);
		return forestGate;

	};	break;

	case(SceneNames::FORESTPATH):
	{
		forestPath->updateData(pd);
		return forestPath;

	};	break;

	case(SceneNames::FORESTBUILDING):
	{
		forestBuilding->updateData(pd);
		return forestBuilding;

	};	break;

	case(SceneNames::HYDRODOOR):
	{
		hydroDoor->updateData(pd);
		return hydroDoor;

	};	break;

	case(SceneNames::DARK):
	{
		dark->updateData(pd);
		return dark;

	};	break;

	case(SceneNames::CORPSE):
	{
		corpse->updateData(pd);
		return corpse;

	};	break;

	case(SceneNames::END1):
	{
		end1->updateData(pd);
		return end1;

	};	break;

	case(SceneNames::END2):
	{
		end2->updateData(pd);
		return end2;

	};	break;
	  
	}

	return tsd;

}