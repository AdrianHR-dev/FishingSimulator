#pragma once

#include "map"
#include "string"
#include "PlayerData.h"
#include "CharacterStates.h"

struct BarflyText
{
public:
	BarflyText();
	~BarflyText();

	CharacterStates returnCharState(PlayerData* pd, int prog);

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> dayDialogue1;
	std::map <int, std::map<int, CharacterStates>> charStates1;

	std::map <int, std::map <int, std::string>> dayDialogue4;
	std::map <int, std::map<int, CharacterStates>> charStates4;

	std::map <int, std::map <int, std::string>> dayDialogue5;
	std::map <int, std::map<int, CharacterStates>> charStates5;

	std::map <int, std::map <int, std::string>> dayDialogue6;
	std::map <int, std::map<int, CharacterStates>> charStates6;

	std::map <int, std::map <int, std::string>> dayDialogue9;
	std::map <int, std::map<int, CharacterStates>> charStates9;

private:

	void initDay1();
	void initDay4();
	void initDay5();
	void initDay6();

	void initFinalDay();


};

