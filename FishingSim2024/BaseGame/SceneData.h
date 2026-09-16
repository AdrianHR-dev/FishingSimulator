#pragma once

#include "SFML/Graphics.hpp"
#include "Character.h"
#include "MoveDirection.h"
#include "MoveZone.h"
#include "SceneNames.h"
#include "CharacterNames.h"
#include "Item.h"


//Structure to be used to set scenes easily. Includes scene move options, characters and objects
struct SceneData
{
public:

	std::map <MoveDirection, MoveZone> moveZones;
	std::map<MoveDirection, SceneNames> neighbouringScenes;
	std::map<CharacterName, Character*> characters;
	std::map<ItemName, Item*> items;
	SceneNames sceneName;

	virtual void updateData(PlayerData* pd)
	{
	
	}

};
