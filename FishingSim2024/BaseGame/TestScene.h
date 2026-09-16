#pragma once

#include "SceneData.h"
#include "TestCharacter.h"
#include "Shoe.h"

struct TestScene : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::TESTSCENE;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		forward.setPosition(sf::Vector2f(268, 494));
		back.setPosition(sf::Vector2f(364, 640));

		forward.setCollisionBox(0, 0, 172, 66);
		back.setCollisionBox(0, 0, 180, 60);
		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set
		neighbouringScenes.insert({MoveDirection::FORWARD, SceneNames::TESTSCENE2});
		neighbouringScenes.insert({ MoveDirection::BACK, SceneNames::TESTSCENE3 });

		characters.insert({CharacterName::TEST, new TestCharacter()});

		//Loop sets all chars alive; can be changed to manually setting if needed
		for (const auto i : characters)
		{
			i.second->setAlive(true);
		}
	
	}


};

struct TestScene2 : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::TESTSCENE2;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		left.setPosition(sf::Vector2f(0.0, 350));

		forward.setCollisionBox(0, 0, 0, 0);
		back.setCollisionBox(0, 0, 0, 0);
		left.setCollisionBox(0, 0, 50, 350);
		right.setCollisionBox(0, 0, 0, 0);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set

		neighbouringScenes.insert({ MoveDirection::LEFT, SceneNames::TESTSCENE });

		items.insert({ItemName::SHOE, new Shoe()});

		//Set all items not alive
		for (const auto i : items)
		{
			i.second->setAlive(false);
		}
	}

	void updateData(PlayerData* pd) override
	{
		switch(pd->tasks)
		{
		case(0):
		{
			items.at(ItemName::SHOE)->setAlive(false);
		};	break;

		case(2):
		{
			items.at(ItemName::SHOE)->setAlive(true);
		};	break;

		case(3):
		{
			items.at(ItemName::SHOE)->setAlive(false);
		};	break;

		}
	}

};

struct TestScene3 : public SceneData
{
public:
	void init()
	{
		sceneName = SceneNames::TESTSCENE3;

		MoveZone forward;
		MoveZone back;
		MoveZone left;
		MoveZone right;

		right.setPosition(sf::Vector2f(650, 500));

		forward.setCollisionBox(0, 0, 0, 0);
		back.setCollisionBox(0, 0, 0, 0);
		left.setCollisionBox(0, 0, 0, 0);
		right.setCollisionBox(0, 0, 50, 200);

		moveZones.insert({ MoveDirection::FORWARD, forward });
		moveZones.insert({ MoveDirection::BACK, back });
		moveZones.insert({ MoveDirection::LEFT, left });
		moveZones.insert({ MoveDirection::RIGHT, right });

		//Surrounding scenes set

		neighbouringScenes.insert({ MoveDirection::RIGHT, SceneNames::TESTSCENE });

	}


};




