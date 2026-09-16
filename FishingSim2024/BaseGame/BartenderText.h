#pragma once

#include "map"
#include "string"
#include "PlayerData.h"
#include "CharacterStates.h"

struct BartenderText
{
public:
	BartenderText();
	~BartenderText();

	CharacterStates returnCharState(PlayerData* pd, int prog);

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> dayDialogue1;
	std::map <int, std::map<int, CharacterStates>> charStates1;

	std::map <int, std::map <int, std::string>> dayDialogue2;
	std::map <int, std::map<int, CharacterStates>> charStates2;

	std::map <int, std::map <int, std::string>> dayDialogue3;
	std::map <int, std::map<int, CharacterStates>> charStates3;

	std::map <int, std::map <int, std::string>> dayDialogue4;
	std::map <int, std::map<int, CharacterStates>> charStates4;

	std::map <int, std::map <int, std::string>> dayDialogue5;
	std::map <int, std::map<int, CharacterStates>> charStates5;
private:

	void initDay1();
	void initDay2();
	void initDay3();
	void initDay4();
	void initDay5();



};

