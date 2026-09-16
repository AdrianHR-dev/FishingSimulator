#pragma once

#include "SceneData.h"
#include "Bartender.h"
#include "Drunkard.h"
#include "Nat.h"
#include "Enzo.h"
#include "Socks.h"
#include "Fisherman.h"
#include "Barfly.h"
#include "Dan.h"

#include "Supermarket.h"
#include "Home.h"
#include "Shiny.h"
#include "Door.h"
#include "Desk.h"

struct Gate : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::GATE;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setCollisionBox(0, 0, 0, 0);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 700, 100);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::ALLEY });

		characters.insert({ CharacterName::ENZO, new Enzo() });
		
		Barfly* b = new Barfly();
		b->setNight(false);

		characters.insert({ CharacterName::BARFLY, b });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(false);
		}
	}

	void updateData(PlayerData* pd) override
	{
		if (pd->luck <= 200 && pd->dayProgress < 6)
		{
			characters.at(CharacterName::ENZO)->setAlive(true); 
		}

		else
		{
			characters.at(CharacterName::ENZO)->setAlive(false);
		}

		if (pd->dayProgress == 6)
		{
			characters.at(CharacterName::BARFLY)->setAlive(true);
			characters.at(CharacterName::BARFLY)->setPosition(sf::Vector2f(0.0f, 800.0f));
			moveZones.at(BACK).setCollisionBox(0, 0, 0, 0);
		}

		else
		{
			characters.at(CharacterName::BARFLY)->setAlive(false);
			moveZones.at(BACK).setCollisionBox(0, 0, 700, 100);
		}
	}


};

struct Alley : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::ALLEY;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(212.0f, 180.0f));
		forward.setCollisionBox(0, 0, 120, 130);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 700, 100);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::GATE });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::CORNER });

	}
};

struct Corner : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::CORNER;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setCollisionBox(0, 0, 0, 0);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 700, 100);

		left.setPosition(sf::Vector2f(0.0f, 300.0f));
		left.setCollisionBox(0, 0, 190, 120);

		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::LEFT, SceneNames::CROSSROAD1 });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::ALLEY });

		characters.insert({ CharacterName::SOCKS, new Socks() });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(true);
		}

	}

	void updateData(PlayerData* pd) override
	{
		if (pd->socksTasks == 1)
		{
			characters.at(CharacterName::SOCKS)->setAlive(true);
		}

		else
		{
			characters.at(CharacterName::SOCKS)->setAlive(false);
		}
	}
};

struct Crossroad1 : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::CROSSROAD1;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(340.0f, 280.0f));
		forward.setCollisionBox(0, 0, 68, 74);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 700, 100);

		left.setCollisionBox(0, 0, 0, 0);

		right.setPosition(sf::Vector2f(550.0f, 380.0f));
		right.setCollisionBox(0, 0, 116, 58);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::BACKSTREET });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::CORNER });
		neighbouringScenes.insert({ MoveDirection::RIGHT, SceneNames::CROSSROAD2 });

		characters.insert({ CharacterName::SOCKS, new Socks() });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(false);
		}

	}

	void updateData(PlayerData* pd) override
	{
		if (pd->socksTasks == 6)
		{
			characters.at(CharacterName::SOCKS)->setAlive(true);
		}
		
		else
		{
			characters.at(CharacterName::SOCKS)->setAlive(false);
		}
	}
};

struct Backstreet : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::BACKSTREET;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setCollisionBox(0, 0, 0, 0);

		forward.setCollisionBox(0, 0, 90, 80);
		forward.setPosition(sf::Vector2f(260.0f, 400.0f)); 

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 700, 100);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::CROSSROAD1 });
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::FORESTGATE });

		items.insert({ ItemName::HOME, new Home() });

		items.at(ItemName::HOME)->setAlive(true);
	
		characters.insert({ CharacterName::SOCKS, new Socks() });

		Dan* d = new Dan();
		d->setNight(true);

		characters.insert({ CharacterName::DAN, d });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(false);
		}

	}

	void updateData(PlayerData* pd) override
	{
		if (pd->socksTasks == 7)
		{
			characters.at(CharacterName::SOCKS)->setPosition(sf::Vector2f(175.0f, 500.0f));
			characters.at(CharacterName::SOCKS)->setSize(sf::Vector2f(0.75f, 0.75f));
			characters.at(CharacterName::SOCKS)->setAlive(true);
		}

		else
		{
			characters.at(CharacterName::SOCKS)->setAlive(false);
		}

		if (pd->dayProgress == 5 && pd->tasks == 2)
		{
			characters.at(CharacterName::DAN)->setAlive(true);

			characters.at(CharacterName::DAN)->setSize(sf::Vector2f(180, 252));
			characters.at(CharacterName::DAN)->setPosition(sf::Vector2f(350.0f, 300.0f));
			characters.at(CharacterName::DAN)->setCollisionBox(80, 0, 110, 252);


		}

		else
		{
			characters.at(CharacterName::DAN)->setAlive(false);
		}
	
	}
};

struct Crossroad2 : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::CROSSROAD2;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(222.0f, 220.0f));
		forward.setCollisionBox(0, 0, 96, 50);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 322, 110);

		left.setPosition(sf::Vector2f(0.0f, 280.0f));
		left.setCollisionBox(0, 0, 50, 480);

		right.setPosition(sf::Vector2f(570.0f, 310.0f));
		right.setCollisionBox(0, 0, 100, 390);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::CROSSROAD1 });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::TRAINSTATION });
		neighbouringScenes.insert({ MoveDirection::LEFT, SceneNames::MAINSTREET });
		neighbouringScenes.insert({ MoveDirection::RIGHT, SceneNames::SUPERMARKET });
	}
};

struct Supermarket : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::SUPERMARKET;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setCollisionBox(0, 0, 0, 0);

		back.setCollisionBox(0, 0, 0, 0);

		left.setPosition(sf::Vector2f(0.0f, 130.0f));
		left.setCollisionBox(0, 0, 50, 540);

		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::LEFT, SceneNames::CROSSROAD2 });

		items.insert({ ItemName::SHOP, new Shop() });

	}

	void updateData(PlayerData* pd) override
	{
		switch (pd->tasks)
		{
		case(1):
		{
	
			items.at(ItemName::SHOP)->setAlive(false);

		};	break;

		case(3):
		{
			if (pd->day == 1)
			{
				items.at(ItemName::SHOP)->setAlive(true);
			}

		};	break;

		case(4):
		{
			items.at(ItemName::SHOP)->setAlive(false);
		};	break;

		}
	}

	
};

struct TrainStation : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::TRAINSTATION;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(330.0f, 320.0f));
		forward.setCollisionBox(0, 0, 65, 55);

		back.setCollisionBox(0, 0, 0, 0);

		left.setPosition(sf::Vector2f(0.0f, 430));
		left.setCollisionBox(0, 0, 110, 270);

		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::CROSSROAD2 });
		neighbouringScenes.insert({ MoveDirection::LEFT, SceneNames::PARK });

		characters.insert({ CharacterName::NAT, new Nat() });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(true);
		}

	}


	void updateData(PlayerData* pd) override
	{
		if (pd->dayProgress == 3 && pd->tasks == 3)
		{
			characters.at(CharacterName::NAT)->setAlive(false);
		}
		
		else
		{
			characters.at(CharacterName::NAT)->setAlive(true);
		}
	}
};

struct Park : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::PARK;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(210.0f, 250.0f));
		forward.setCollisionBox(0, 0, 180, 50);

		left.setCollisionBox(0, 0, 0, 0);

		back.setPosition(sf::Vector2f(0.0f, 590.0f));
		back.setCollisionBox(0, 0, 700, 110);

		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::TRAINSTATION });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::MAINSTREET });

		characters.insert({ CharacterName::SOCKS, new Socks() });
		items.insert({ItemName::SHINY, new Shiny() });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(true);
		}

		for (const auto i : items)
		{
			i.second->setAlive(false);
		}

	}

	void updateData(PlayerData* pd) override
	{
		if (pd->socksTasks == 2)
		{
			characters.at(CharacterName::SOCKS)->setAlive(true);
		}

		else
		{
			characters.at(CharacterName::SOCKS)->setAlive(false);
		}

		if (pd->dayProgress == 2 && pd->tasks == 3)
		{
			items.at(ItemName::SHINY)->setAlive(true);
		}

		else
		{
			items.at(ItemName::SHINY)->setAlive(false);
		}
	}
};

struct MainStreet : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::MAINSTREET;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(265.0f, 325.0f));
		forward.setCollisionBox(0, 0, 120, 160);

		left.setPosition(sf::Vector2f(116.0f, 320));
		left.setCollisionBox(0, 0, 50, 60);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 350, 100);

		right.setPosition(sf::Vector2f(545.0f, 445.0f));
		right.setCollisionBox(0, 0, 140, 240);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::WATERFRONT });
		neighbouringScenes.insert({ MoveDirection::LEFT, SceneNames::TAVERN });
		neighbouringScenes.insert({ MoveDirection::RIGHT, SceneNames::CROSSROAD2 });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::PARK });

		characters.insert({ CharacterName::DRUNKARD, new Drunkard() });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(true);
		}

	}

	void updateData(PlayerData* pd) override
	{
		switch (pd->dayProgress)
		{
		case(1):
		{
			if (pd->tasks == 1)
			{
				characters.at(CharacterName::DRUNKARD)->setAlive(false);
			}

			else
			{
				characters.at(CharacterName::DRUNKARD)->setAlive(true);
			}
		};	break;

		case(2):
		{
			characters.at(CharacterName::DRUNKARD)->setAlive(false);
		};	break;

		case(3):
		{
			characters.at(CharacterName::DRUNKARD)->setAlive(true);
		};	break;

		case(4):
		{
			characters.at(CharacterName::DRUNKARD)->setAlive(false);
		};	break;

		case(5):
		{
			characters.at(CharacterName::DRUNKARD)->setAlive(true);
		};	break;

		}
	}
};

struct Tavern : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::TAVERN;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setCollisionBox(0, 0, 0, 0);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 700, 100);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::MAINSTREET });

		characters.insert({ CharacterName::BARTENDER, new Bartender() });
		characters.insert({ CharacterName::BARFLY, new Barfly() });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(true);
		}

	}

	void updateData(PlayerData* pd) override
	{
		if (pd->dayProgress == 5 && pd->tasks == 2)
		{
			characters.at(CharacterName::BARFLY)->setAlive(false);
		}

	}
};

struct Waterfront : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::WATERFRONT;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setCollisionBox(0, 0, 0, 0);
		back.setCollisionBox(0, 0, 0, 0);

		left.setPosition(sf::Vector2f(0.0f, 390.0f));
		left.setCollisionBox(0, 0, 130, 300);

		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::LEFT, SceneNames::MAINSTREET });

		characters.insert({ CharacterName::SOCKS, new Socks() });
		characters.insert({CharacterName::FISHERMAN, new Fisherman()});

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(true);
		}

	}

	void updateData(PlayerData* pd) override
	{
		if (pd->socksTasks > 3 && pd->socksTasks <= 5)
		{
			characters.at(CharacterName::SOCKS)->setAlive(true);
			characters.at(CharacterName::SOCKS)->setPosition(sf::Vector2f(175.0f, 450.0f));
		}

		else
		{
			characters.at(CharacterName::SOCKS)->setAlive(false);
		}

		if (pd->dayProgress >= 2 && pd->dayProgress < 4)
		{
			if (pd->dayProgress != 2 || pd->tasks > 1)
			{
				characters.at(CharacterName::FISHERMAN)->setAlive(true);
			}

			else
			{
				characters.at(CharacterName::FISHERMAN)->setAlive(false);
			}
		}

		else
		{
			characters.at(CharacterName::FISHERMAN)->setAlive(false);
		}
	}

};


struct ForestGate : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::FORESTGATE;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(140.0f, 240.0f));
		forward.setCollisionBox(0, 0, 0, 0);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 700, 100);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::BACKSTREET });
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::FORESTPATH });

		characters.insert({ CharacterName::SOCKS, new Socks() });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(false);
		}

	}

	void updateData(PlayerData* pd) override
	{
		if (pd->socksTasks == 8 || pd->socksTasks == 9)
		{
			characters.at(CharacterName::SOCKS)->setAlive(true);
			characters.at(CharacterName::SOCKS)->setPosition(sf::Vector2f(125.0f, 450.0f));
			characters.at(CharacterName::SOCKS)->setSize(sf::Vector2f(1.0f, 1.0f));
		}

		else
		{
			characters.at(CharacterName::SOCKS)->setAlive(false);
		}

		if (pd->dayProgress > 4 || (pd->dayProgress == 4 && pd->tasks > 2))
		{
			moveZones.at(FORWARD).setCollisionBox(0, 0, 380, 200);
		}

		else
		{
			moveZones.at(FORWARD).setCollisionBox(0, 0, 0, 0);
		}
	}
};

struct ForestPath : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::FORESTPATH;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(240.0f, 150.0f));
		forward.setCollisionBox(0, 0, 200, 50);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 700, 100);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::FORESTGATE });
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::FORESTBUILDING });

	}

	void updateData(PlayerData* pd) override
	{

	}
};

struct ForestBuilding : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::FORESTBUILDING;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(220.0f, 140.0f));
		forward.setCollisionBox(0, 0, 300, 90);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 700, 100);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::FORESTPATH });
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::HYDRODOOR });

	}

	void updateData(PlayerData* pd) override
	{

	}
};

struct HydroDoor : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::HYDRODOOR;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(90.0f, 200.0f);
		forward.setCollisionBox(0, 0, 0, 0);

		back.setPosition(sf::Vector2f(0.0f, 600.0f));
		back.setCollisionBox(0, 0, 700, 100);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::FORESTBUILDING });
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::DARK });

		items.insert({ ItemName::DOOR, new Door() });

		//Loop sets all chars alive; can be changed to manually setting if needed

		for (const auto i : items)
		{
			i.second->setAlive(false);
		}

	}

	void updateData(PlayerData* pd) override
	{

		if (pd->dayProgress == 4 && pd->tasks == 3)
		{
			items.at(DOOR)->setAlive(true);
		}

		else
		{
			items.at(DOOR)->setAlive(false);
		}

		if (pd->dayProgress == 4 && pd->tasks == 4)
		{
			moveZones.at(FORWARD).setCollisionBox(0, 0, 43, 70);
		}

		else
		{
			moveZones.at(FORWARD).setCollisionBox(0, 0, 0, 0);
		}
	}
};

struct Dark : public SceneData
{
public:

	void init()
	{
		sceneName = SceneNames::DARK;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setCollisionBox(0, 0, 0, 0);
		back.setCollisionBox(0, 0, 0, 0);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });


		items.insert({ ItemName::DESK, new Desk() });

		//Loop sets all chars alive; can be changed to manually setting if needed

		for (const auto i : items)
		{
			i.second->setAlive(false);
		}

	}

	void updateData(PlayerData* pd) override
	{
		if (pd->dayProgress == 4)
		{
			items.at(DESK)->setAlive(true);
		}
	}
};


