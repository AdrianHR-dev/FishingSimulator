#pragma once
#include "map"
#include "string"
#include "PlayerData.h"
#include "CharacterStates.h"

class DrunkardText
{
public:
	DrunkardText();
	~DrunkardText();

	CharacterStates returnCharState(PlayerData* pd, int prog);

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> dayDialogue1;
	std::map <int, std::map<int, CharacterStates>> charStates1;

	std::map <int, std::map <int, std::string>> dayDialogue3;
	std::map <int, std::map<int, CharacterStates>> charStates3;

	std::map <int, std::map <int, std::string>> dayDialogue5;
	std::map <int, std::map<int, CharacterStates>> charStates5;
private:

	void initDay1();
	void initDay3();
	void initDay5();

};

