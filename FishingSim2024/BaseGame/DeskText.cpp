#include "DeskText.h"

DeskText::DeskText()
{

	std::map<int, std::string> deskInvestigation;
	std::map<int, CharacterStates> deskStates;


	deskInvestigation.insert({ 1,"You" });
	deskInvestigation.insert({ 2,"It's so dark in here...\nHow am I going to find one specific \nnotebook in here?" });
	deskStates.insert({1, CharacterStates::BLANK});

	deskInvestigation.insert({ 3, "You" });
	deskInvestigation.insert({ 4, "..." });
	deskStates.insert({ 2, CharacterStates::BLANK });

	deskInvestigation.insert({ 5, "You" });
	deskInvestigation.insert({ 6, "...\n..." });
	deskStates.insert({ 3, CharacterStates::BLANK });

	deskInvestigation.insert({ 7, "You" });
	deskInvestigation.insert({ 8, "...\n...\n..." });
	deskStates.insert({ 4, CharacterStates::BLANK });

	deskInvestigation.insert({ 9, "You" });
	deskInvestigation.insert({ 10, "Oh? This seems promising..." });
	deskStates.insert({ 5, CharacterStates::BLANK });

	deskInvestigation.insert({ 11, "You" });
	deskInvestigation.insert({ 12, "There's a notebook in here... \nIs this the one I'm looking for?" });
	deskStates.insert({ 6, CharacterStates::BLANK });

	deskInvestigation.insert({ 13, "You" });
	deskInvestigation.insert({ 14, "C. Donaldson... C for Clark hopefully?" });
	deskStates.insert({ 7, CharacterStates::BLANK });

	deskInvestigation.insert({ 15, "You" });
	deskInvestigation.insert({ 16, "Let's have a look here..." });
	deskStates.insert({ 8, CharacterStates::BLANK });

	deskInvestigation.insert({ 17, "You" });
	deskInvestigation.insert({ 18, "What's this? Is this... the dam?" });
	deskStates.insert({ 9, CharacterStates::ITEM });

	deskInvestigation.insert({ 19, "You" });
	deskInvestigation.insert({ 20, "It looks like a turbine for producing \nhydro power and..." });
	deskStates.insert({ 10, CharacterStates::ITEM });

	deskInvestigation.insert({ 21, "You" });
	deskInvestigation.insert({ 22, "What's this other hole for?" });
	deskStates.insert({ 11, CharacterStates::ITEM });

	deskInvestigation.insert({ 23, "You" });
	deskInvestigation.insert({ 24, "A cave maybe?" });
	deskStates.insert({ 12, CharacterStates::ITEM });

	deskInvestigation.insert({ 25, "You" });
	deskInvestigation.insert({ 26, "I can't tell if this is supposed to show \nsomething coming out or going in..." });
	deskStates.insert({ 13, CharacterStates::ITEM });

	deskInvestigation.insert({ 27, "You" });
	deskInvestigation.insert({ 28, "I guess I'll ask Clark when I get this \nnotebook back to him." });
	deskStates.insert({ 14, CharacterStates::ITEM });

	deskInvestigation.insert({ 29, "You" });
	deskInvestigation.insert({ 30, "It's late now, The bar will be closed. I'll \nhave to try find him tomorrow." });
	deskStates.insert({ 15, CharacterStates::ITEM });

	deskInvestigation.insert({ 31, "You" });
	deskInvestigation.insert({ 32, "END" });
	deskStates.insert({ 16, CharacterStates::BLANK });

	deskDialogue.insert({ 1, deskInvestigation });
	deskStatus.insert({1, deskStates});
}

DeskText::~DeskText()
{


}

CharacterStates DeskText::returnCharState(PlayerData* pd, int prog)
{
	return deskStatus.at(1).at(prog);
	
}