#pragma once


#include "Map.h"
#include "CharacterStates.h"
#include "PlayerData.h" 
#include "string.h"

class DeskText
{
public:

	DeskText();
	~DeskText();

	CharacterStates returnCharState(PlayerData* pd, int prog);

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> deskDialogue;
	std::map <int, std::map <int, CharacterStates>> deskStatus;

};