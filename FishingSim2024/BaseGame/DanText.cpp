#include "DanText.h"

DanText::DanText()
{

	initDay1();
	initDay2();
	initDay3();
	initDay4();
	initDay5();
	initDay6();
	initDay7();
}

DanText::~DanText()
{


}

CharacterStates DanText::returnCharState(PlayerData* pd, int prog)
{
	switch (pd->day)
	{

	case(1):
	{
		return charStates1.at(1).at(prog);

	};	break;

	case(2):
	{
		return charStates2.at(1).at(prog);

	};	break;

	case(3):
	{
		return charStates3.at(1).at(prog);

	};	break;

	case(4):
	{
		return charStates4.at(1).at(prog);

	};	break;

	case(5):
	{
		if (pd->isDay)
		{
			return charStates5.at(1).at(prog);
		}
		
		else
		{
			return charStates5.at(2).at(prog);
		}

	};	break;

	case(6):
	{
		return charStates6.at(1).at(prog);

	};	break;

	case(7):
	{
		return charStates7.at(1).at(prog);

	};	break;

	}
}

void DanText::initDay1()
{
	//This character has states neutral smile fear thinking and turn
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	task1.insert({ 1, "Dan" });
	task1.insert({ 2, "Hey!" });
	t1CharStates.insert({ 1, CharacterStates::SMILE });

	task1.insert({ 3, "Dan" });
	task1.insert({ 4, "I'm glad you could make it!" });
	t1CharStates.insert({ 2, CharacterStates::SMILE });

	task1.insert({ 5, "Dan" });
	task1.insert({ 6, "Let's go fishing!" });
	t1CharStates.insert({ 3, CharacterStates::SMILE });

	task1.insert({ 7, "Dan" });
	task1.insert({ 8, "END" });	//END ALL CONVOS WITH "END". This informs dialogue class to end 
	t1CharStates.insert({ 4, CharacterStates::NEUTRAL });

	dayDialogue1.insert({ 1, task1 });

	charStates1.insert({ 1, t1CharStates });

}

void DanText::initDay2()
{
	//This character has states neutral smile fear thinking and turn
	std::map<int, std::string> text;
	std::map<int, CharacterStates> CharStates;

	text.insert({ 1, "Dan" });
	text.insert({ 2, "Good to see you again!" });
	CharStates.insert({ 1, CharacterStates::SMILE });

	text.insert({ 3, "Dan" });
	text.insert({ 4, "Let's go fishing!" });
	CharStates.insert({ 2, CharacterStates::SMILE });

	text.insert({ 5, "Dan" });
	text.insert({ 6, "END" });	//END ALL CONVOS WITH "END". This informs dialogue class to end 
	CharStates.insert({ 3, CharacterStates::NEUTRAL });
	
	dayDialogue2.insert({ 1, text });

	charStates2.insert({ 1, CharStates });
}

void DanText::initDay3()
{
	//This character has states neutral smile fear thinking and turn
	std::map<int, std::string> text;
	std::map<int, CharacterStates> CharStates;

	text.insert({ 1, "Dan" });
	text.insert({ 2, "Good to see you again!" });
	CharStates.insert({ 1, CharacterStates::SMILE });

	text.insert({ 3, "Dan" });
	text.insert({ 4, "I was beginning to worry you might \nhave been scared off by some old \nrumours!" });
	CharStates.insert({ 2, CharacterStates::THINKING });

	text.insert({ 5, "Dan" });
	text.insert({ 6, "Let's go fishing!" });
	CharStates.insert({ 3, CharacterStates::SMILE });

	text.insert({ 7, "Dan" });
	text.insert({ 8, "END" });
	CharStates.insert({ 4, CharacterStates::SMILE });

	dayDialogue3.insert({ 1, text });

	charStates3.insert({ 1, CharStates });
}

void DanText::initDay4()
{
	//This character has states neutral smile fear thinking and turn
	std::map<int, std::string> text;
	std::map<int, CharacterStates> CharStates;

	text.insert({ 1, "Dan" });
	text.insert({ 2, "..." });
	CharStates.insert({ 1, CharacterStates::NEUTRAL });

	text.insert({ 3, "Dan" });
	text.insert({ 4, "Let's go fishing!" });
	CharStates.insert({ 2, CharacterStates::SMILE });

	text.insert({ 5, "Dan" });
	text.insert({ 6, "END" });
	CharStates.insert({ 3, CharacterStates::SMILE });

	dayDialogue4.insert({ 1, text });

	charStates4.insert({ 1, CharStates });
}

void DanText::initDay5()
{
	//This character has states neutral smile fear thinking and turn
	std::map<int, std::string> text;
	std::map<int, CharacterStates> CharStates;

	std::map<int, std::string> nightText;
	std::map<int, CharacterStates> nightCharStates;

	text.insert({ 1, "Dan" });
	text.insert({ 2, "Something has awoken here." });
	CharStates.insert({ 1, CharacterStates::FEAR });

	text.insert({ 3, "Dan" });
	text.insert({ 4, "Let's go fishing!" });
	CharStates.insert({ 2, CharacterStates::SMILE });

	text.insert({ 5, "Dan" });
	text.insert({ 6, "END" });
	CharStates.insert({ 3, CharacterStates::SMILE });

	//NIGHT 5 NIGHT TEXT BELOW

	nightText.insert({ 1, "You" });
	nightText.insert({ 2, "...?" });
	nightCharStates.insert({ 1, CharacterStates::FEAR });

	nightText.insert({ 3, "You" });
	nightText.insert({ 4, "Dan? What are you doing here?" });
	nightCharStates.insert({ 2, CharacterStates::FEAR });

	nightText.insert({ 5, "Dan" });
	nightText.insert({ 6, "Huh?" });
	nightCharStates.insert({ 3, CharacterStates::NEUTRAL });

	nightText.insert({ 7, "Dan" });
	nightText.insert({ 8, "Oh, hey!" });
	nightCharStates.insert({ 4, CharacterStates::SMILE });

	nightText.insert({ 9, "You" });
	nightText.insert({ 10, "Is... everything all right?" });
	nightCharStates.insert({ 5, CharacterStates::FEAR });

	nightText.insert({ 11, "Dan" });
	nightText.insert({ 12, "Yeah, yeah!" });
	nightCharStates.insert({ 6, CharacterStates::SMILE });

	nightText.insert({ 13, "Dan" });
	nightText.insert({ 14, "I just thought I'd stop by and uh..." });
	nightCharStates.insert({ 7, CharacterStates::SMILE });

	nightText.insert({ 15, "Dan" });
	nightText.insert({ 16, "I mean... maybe we..." });
	nightCharStates.insert({ 8, CharacterStates::NEUTRAL });

	nightText.insert({ 17, "Dan" });
	nightText.insert({ 18, "We've done so much fishing recently..." });
	nightCharStates.insert({ 9, CharacterStates::NEUTRAL });

	nightText.insert({ 19, "Dan" });
	nightText.insert({ 20, "Maybe we do something else tomorrow?" });
	nightCharStates.insert({ 10, CharacterStates::TURN });

	nightText.insert({ 21, "You" });
	nightText.insert({ 22, "Oh.\nYeah, sure, what did you have in mind?" });
	nightCharStates.insert({ 11, CharacterStates::FEAR });

	nightText.insert({ 23, "You" });
	nightText.insert({ 24, "Maybe we could just have a night at the-" });
	nightCharStates.insert({ 12, CharacterStates::FEAR });

	nightText.insert({ 25, "Dan" });
	nightText.insert({ 26, "Actually, one more day couldnt hurt!" });
	nightCharStates.insert({ 13, CharacterStates::SMILE });

	nightText.insert({ 27, "Dan" });
	nightText.insert({ 28, "The weather is still supposed to be nice!\nWe don't get that often up here!" });
	nightCharStates.insert({ 14, CharacterStates::SMILE });

	nightText.insert({ 29, "Dan" });
	nightText.insert({ 30, "..." });
	nightCharStates.insert({ 15, CharacterStates::FEAR });

	nightText.insert({ 31, "Dan" });
	nightText.insert({ 32, "I'll see you tomorrow." });
	nightCharStates.insert({ 16, CharacterStates::NEUTRAL });

	nightText.insert({ 33, "You" });
	nightText.insert({ 34, "Oh. Uh, yeah. Sure!" });
	nightCharStates.insert({ 17, CharacterStates::NEUTRAL });

	nightText.insert({ 35, "You" });
	nightText.insert({ 36, "..." });
	nightCharStates.insert({ 18, CharacterStates::BLANK });

	nightText.insert({ 37, "You" });
	nightText.insert({ 38, "What was that about?" });
	nightCharStates.insert({ 19, CharacterStates::BLANK });

	nightText.insert({ 39, "You" });
	nightText.insert({ 40, "..." });
	nightCharStates.insert({ 20, CharacterStates::BLANK });

	nightText.insert({ 41, "You" });
	nightText.insert({ 42, "Is... everything ok with him?" });
	nightCharStates.insert({ 21, CharacterStates::BLANK });

	nightText.insert({ 43, "You" });
	nightText.insert({ 44, "I guess I'll just...ask him\n tomorrow..." });
	nightCharStates.insert({ 22, CharacterStates::BLANK });

	nightText.insert({ 45, "You" });
	nightText.insert({ 46, "While we're fishing..." });
	nightCharStates.insert({ 23, CharacterStates::BLANK });

	nightText.insert({ 47, "You" });
	nightText.insert({ 48, "END" });
	nightCharStates.insert({ 24, CharacterStates::BLANK });


	dayDialogue5.insert({ 1, text });
	dayDialogue5.insert({ 2, nightText });


	charStates5.insert({ 1, CharStates });
	charStates5.insert({ 2, nightCharStates });
}

void DanText::initDay6()
{
	//This character has states neutral smile fear thinking and turn
	std::map<int, std::string> text;
	std::map<int, CharacterStates> CharStates;

	text.insert({ 1, "You" });
	text.insert({ 2, "..." });
	CharStates.insert({ 1, CharacterStates::BLANK });

	text.insert({ 3, "Dan" });
	text.insert({ 4, "END" });
	CharStates.insert({ 2, CharacterStates::SMILE });

	dayDialogue6.insert({ 1, text });

	charStates6.insert({ 1, CharStates });
}

void DanText::initDay7()
{
	//This character has states neutral smile fear thinking and turn
	std::map<int, std::string> text;
	std::map<int, CharacterStates> CharStates;

	text.insert({ 1, "You" });
	text.insert({ 2, "Let's go fishing." });
	CharStates.insert({ 1, CharacterStates::BLANK });

	text.insert({ 3, "You" });
	text.insert({ 4, "END" });
	CharStates.insert({ 1, CharacterStates::BLANK });

	dayDialogue7.insert({ 1, text });

	charStates7.insert({ 1, CharStates });
}