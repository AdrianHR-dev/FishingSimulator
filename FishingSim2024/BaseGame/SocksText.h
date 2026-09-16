#pragma once

#include "PlayerData.h"
#include "CharacterStates.h"
#include "Map.h"
#include "String.h"

class SocksText
{
public:
	SocksText();
	~SocksText();

	CharacterStates returnCharState(PlayerData* pd, int prog);

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> socksSpeech;
	std::map <int, std::map<int, CharacterStates>> socksStates;

private:

	void initText();
};

