#pragma once

#include "map"
#include "string"
#include "PlayerData.h"
#include "CharacterStates.h"

struct TestText
{
public:
	TestText();
	~TestText();

	CharacterStates returnCharState(PlayerData* pd, int prog);

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> testDialogue1;
	std::map <int, std::map<int, CharacterStates>> charStates1;
private:

	void initDay1();



};

