#pragma once

#include "map"
#include "string"
#include "PlayerData.h"
#include "CharacterStates.h"

class EnzoText
{
public:
	EnzoText();
	~EnzoText();

	CharacterStates returnCharState(PlayerData* pd, int prog);

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> enzoSpeech;
	std::map <int, std::map<int, CharacterStates>> enzoStates;

private:

	void initText();

};

