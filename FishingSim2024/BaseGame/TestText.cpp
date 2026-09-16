#include "TestText.h"

TestText::TestText()
{

	initDay1();
}

TestText::~TestText()
{


}

CharacterStates TestText::returnCharState(PlayerData* pd, int prog)
{
	switch (pd->dayProgress)
	{

	case(1):
	{
		return charStates1.at(pd->tasks).at(prog);

	};	break;

	}
}

void TestText::initDay1()
{
	//This character has states neutral smile fear thinking and turn
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task3;
	std::map<int, CharacterStates> t3CharStates;

	task1.insert({ 1, "Adrian" });
	task1.insert({ 2, "poo" });
	t1CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task1.insert({ 3, "Adrian" });
	task1.insert({ 4, "poopywoopy" });
	t1CharStates.insert({ 2, CharacterStates::SMILE });

	task1.insert({ 5, "Adrian" });
	task1.insert({ 6, "Get a load of\n this!!!!" });
	t1CharStates.insert({ 3, CharacterStates::TURN });

	task1.insert({ 7, "Adrian" });
	task1.insert({ 8, "END" });	//END ALL CONVOS WITH "END". This informs dialogue class to end 
	t1CharStates.insert({ 4, CharacterStates::NEUTRAL });

	//TASK 2
	task2.insert({ 1, "Adrian" });
	task2.insert({ 2, "Ok actually you beat the game. \nCharacter count!" });
	t2CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task2.insert({ 3, "Adrian" });
	task2.insert({ 4, "1234567890123456789012345678901234567890" });

	task2.insert({ 5, "Adrian" });
	t2CharStates.insert({ 2, CharacterStates::SMILE });
	task2.insert({ 6, "34. Your strings can be 34 chars long" });

	task2.insert({ 7, "Adrian" });
	task2.insert({ 8, "It's probably worth now making \nanimations...\nand also my name. Wheres my name pal?" });
	t2CharStates.insert({ 3, CharacterStates::FEAR });

	task2.insert({ 9, "Adrian" });
	task2.insert({ 10, "END" });	//END ALL CONVOS WITH "END". This informs dialogue class to end 
	t2CharStates.insert({ 4, CharacterStates::NEUTRAL });

	//TASK 3
	task3.insert({ 1, "Adrian" });
	task3.insert({ 2, "Oh, wow! You found an item! I love items! \nThank you so much!" });
	t3CharStates.insert({ 1, CharacterStates::SMILE });

	task3.insert({ 3, "Adrian" });
	task3.insert({ 4, "1234567890 hello. this is char 33\nSorry I'm just testing my text lengths again!" });
	t3CharStates.insert({ 2, CharacterStates::THINKING });

	task3.insert({ 5, "Adrian" });
	task3.insert({ 6, "This string is 48 chars long. thirtyone. eight.8" });
	t3CharStates.insert({ 3, CharacterStates::TURN });

	task3.insert({ 7, "Adrian" });
	task3.insert({ 8, "It seems you can fit about 45-47 characters \nin a single line of these text boxes." });
	t3CharStates.insert({ 4, CharacterStates::NEUTRAL });

	task3.insert({ 9, "You" });
	task3.insert({ 10, "END" });	//END ALL CONVOS WITH "END". This informs dialogue class to end conversation
	t3CharStates.insert({ 1, CharacterStates::NEUTRAL });

	testDialogue1.insert({ 1, task1 });
	testDialogue1.insert({ 2, task2 });
	testDialogue1.insert({ 3, task3 });

	charStates1.insert({1, t1CharStates});
	charStates1.insert({ 2, t2CharStates });
	charStates1.insert({ 3, t3CharStates });

}