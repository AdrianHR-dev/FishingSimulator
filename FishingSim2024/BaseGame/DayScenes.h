#pragma once

#include "SceneData.h"
#include "Barfly.h"
#include "Dan.h"
#include "Shoe.h"
#include "Body.h"
#include "Tentacle.h"
#include "Beast.h"
#include "Morty.h"

struct Path1 : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::PATH1;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(270.0f, 312.0f));
		forward.setCollisionBox(0, 0, 126, 76);
		back.setCollisionBox(0, 0, 0, 0);
		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::PATH2 });

	}


};

struct Path2 : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::PATH2;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(222.0f, 226.0f));
		forward.setCollisionBox(0, 0, 196, 118);

		back.setPosition(sf::Vector2f(0, 550));
		back.setCollisionBox(0, 0, 650, 100);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::PATH3 });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::PATH1 });

	}
};

struct Path3 : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::PATH3;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(334.0f, 328.0f));
		forward.setCollisionBox(0, 0, 132, 42);

		back.setPosition(sf::Vector2f(0, 550));
		back.setCollisionBox(0, 0, 650, 100);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::PATH4 });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::PATH2 });

	}
};

struct Path4 : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::PATH4;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(14.0f, 266.0f));
		forward.setCollisionBox(0, 0, 294, 148);

		back.setPosition(sf::Vector2f(0, 550));
		back.setCollisionBox(0, 0, 650, 100);

		right.setPosition(sf::Vector2f(540.0f, 416.0));
		right.setCollisionBox(0, 0, 110, 120);

		left.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::PATH5 });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::PATH3 });
		neighbouringScenes.insert({ MoveDirection::RIGHT, SceneNames::BRIDGE });

	}
};

struct Bridge : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::BRIDGE;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		left.setPosition(sf::Vector2f(0.0f,274.0f));
		left.setCollisionBox(0, 0, 74, 376);

		forward.setCollisionBox(0, 0, 0, 0);

		back.setCollisionBox(0, 0, 0, 0);

		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::LEFT, SceneNames::PATH4 });

		items.insert({ ItemName::SHOE, new Shoe() });
		items.insert({ ItemName::TENTACLE, new Tentacle() });

		characters.insert({CharacterName::BARFLY, new Barfly() });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(false);
		}

		for (const auto i : items)
		{
			i.second->setAlive(false);
		}

	}

	void updateData(PlayerData* pd) override
	{
		if (pd->day == 3)
		{
			items.at(ItemName::SHOE)->setAlive(true);
		}

		else
		{
			items.at(ItemName::SHOE)->setAlive(false);
		}

		if (pd->day == 5)
		{
			items.at(ItemName::TENTACLE)->setAlive(true);
		}

		else
		{
			items.at(ItemName::TENTACLE)->setAlive(false);
		}

		if (pd->dayProgress > 7)
		{
			characters.at(CharacterName::BARFLY)->setAlive(true);
			moveZones.at(MoveDirection::LEFT).setCollisionBox(0, 0, 0, 0);
		}
	}
};


struct Path5 : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::PATH5;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(210.0f, 296.0f));
		forward.setCollisionBox(0, 0, 162, 116);

		back.setPosition(sf::Vector2f(0.0f, 550.f));
		back.setCollisionBox(0, 0, 650, 100);


		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::PATH6 });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::PATH4 });

	}
};

struct Path6 : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::PATH6;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(258.0f, 254.0f));
		forward.setCollisionBox(0, 0, 102, 84);

		back.setPosition(sf::Vector2f(0.0f, 550.f));
		back.setCollisionBox(0, 0, 650, 100);


		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::DAM });
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::PATH5 });

	}
};

struct Dam : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::DAM;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setCollisionBox(0, 0, 0, 0);

		back.setCollisionBox(0, 0, 650, 100);
		back.setPosition(sf::Vector2f(250.0f, 550.f));

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::PATH6 });

		characters.insert({ CharacterName::DAN, new Dan() });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(true);
		}

	}


};

struct Corpse : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::CORPSE;

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

		items.insert({ ItemName::BODY, new Body() });
		items.insert({ ItemName::BEAST, new Beast() });

		for (const auto i : items)
		{
			i.second->setAlive(true);
		}

		items.at(ItemName::BEAST)->setAlive(false);
	}


	void updateData(PlayerData* pd) override
	{
		if (pd->dayProgress < 7)
		{
			items.at(ItemName::BEAST)->setAlive(false);

		}

		else if (pd->dayProgress == 8)
		{
			items.at(ItemName::BEAST)->setAlive(true);

			items.at(ItemName::BODY)->setAlive(false);

		}

		else
		{
			pd->beastTime = 1;
		}
	}

};

struct End1 : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::END1;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setCollisionBox(0, 0, 440, 80);
		forward.setPosition(200.0f, 620.0f);

		back.setCollisionBox(0, 0, 0, 0);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		neighbouringScenes.insert({ MoveDirection::FORWARD, SceneNames::END2 });

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

	
	}

	void updateData(PlayerData* pd) override
	{
	
	}

};

struct End2 : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::END2;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setCollisionBox(0, 0, 0, 0);

		back.setCollisionBox(0, 0, 410, 100);
		back.setPosition(0.0f, 600.0f);

		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::END1 });

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		characters.insert({ CharacterName::MORTY, new Morty() });

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(true);
		}

	}


	void updateData(PlayerData* pd) override
	{

	}


};