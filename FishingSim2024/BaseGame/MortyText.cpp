#include "MortyText.h"

MortyText::MortyText()
{
	initDay1();
}

MortyText::~MortyText()
{

}

void MortyText::initDay1()
{
	//This character has states neutral angry thinking and smile

	std::map<int, std::string> day1;
	std::map<int, CharacterStates> day1CStates;

	//SECOND TASK
	day1.insert({ 1, "Morty" });
	day1.insert({ 2, "Hey!\nI'm glad you could make it!" });
	day1CStates.insert({ 1, CharacterStates::SMILE });

	day1.insert({ 3, "Morty" });
	day1.insert({ 4, "Let's go fishing!" });
	day1CStates.insert({ 2, CharacterStates::SMILE });

	day1.insert({ 5, "Morty" });
	day1.insert({ 6, "END" });
	day1CStates.insert({ 3, CharacterStates::SMILE });

	dayDialogue1.insert({ 1, day1 });

	charStates1.insert({ 1, day1CStates });


}

CharacterStates MortyText::returnCharState(PlayerData* pd, int prog)
{

	return charStates1.at(1).at(prog);

}
