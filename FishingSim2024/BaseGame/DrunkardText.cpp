#include "DrunkardText.h"

DrunkardText::DrunkardText()
{
	initDay1();
	initDay3();
	initDay5();
}

DrunkardText::~DrunkardText()
{

}

CharacterStates DrunkardText::returnCharState(PlayerData* pd, int prog)
{
	switch (pd->dayProgress)
	{

	case(1):
	{
		return charStates1.at(pd->tasks).at(prog);

	};	break;

	case(3):
	{
		return charStates3.at(pd->tasks).at(prog);

	};	break;

	case(5):
	{
		return charStates5.at(1).at(prog);

	};	break;

	}
}

void DrunkardText::initDay1()
{
	//This character has states neutral angry thinking and turn
	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task3;
	std::map<int, CharacterStates> t3CharStates;

	std::map<int, std::string> task4;
	std::map<int, CharacterStates> t4CharStates;

	std::map<int, std::string> task5;
	std::map<int, CharacterStates> t5CharStates;

	std::map<int, std::string> task6;
	std::map<int, CharacterStates> t6CharStates;

	//SECOND TASK
	task2.insert({ 1, "Drunkard" });
	task2.insert({ 2, "Huh? Who's that?" });
	t2CharStates.insert({ 1, CharacterStates::ANGRY });

	task2.insert({ 3, "You" });
	task2.insert({ 4, "Oh.. uhh... you're fine... I should be on \nmy way then..." });
	t2CharStates.insert({ 2, CharacterStates::ANGRY });

	task2.insert({ 5, "Drunkard" });
	task2.insert({ 6, "Woah, woah wait a... wait a minute..." });
	t2CharStates.insert({ 3, CharacterStates::TURN });

	task2.insert({ 7, "Drunkard" });
	task2.insert({ 8, "Help me out a little... would ya?" });
	t2CharStates.insert({ 4, CharacterStates::TURN });

	task2.insert({ 9, "You" });
	task2.insert({ 10, "What? Like... to walk...? Or...?" });
	t2CharStates.insert({ 5, CharacterStates::TURN });

	task2.insert({ 11, "Drunkard" });
	task2.insert({ 12, "Nah, nah I can... I can walk fine man... \nNah, I just... uh... need you to get me \na drink..." });
	t2CharStates.insert({ 6, CharacterStates::THINKING });

	task2.insert({ 13, "Drunkard" });
	task2.insert({ 14, "Its' that... fuckin' uhh... that bartender \nman!He's got it out for me and I'm not \neven that drunk and uhh... and..." });
	t2CharStates.insert({ 7, CharacterStates::ANGRY });

	task2.insert({ 15, "You" });
	task2.insert({ 16, "(He does not need another drink. Maybe \nI could just get him some water or \nsomething.)" });
	t2CharStates.insert({ 8, CharacterStates::TURN });

	task2.insert({ 17, "You" });
	task2.insert({ 18, "Yeah, ok sure I'll get you something." });
	t2CharStates.insert({ 9, CharacterStates::TURN });

	task2.insert({ 19, "Drunkard" });
	task2.insert({ 20, "Aww see, I just... I knew I could count \non you mate, you're the... uhhh... \nbest!" });
	t2CharStates.insert({ 10, CharacterStates::ANGRY });

	task2.insert({ 21, "Drunkard" });
	task2.insert({ 22, "END" });
	t2CharStates.insert({ 10, CharacterStates::ANGRY });

	//THIRD TASK

	task3.insert({ 1, "Drunkard" });
	task3.insert({ 2, "You're fuckin' uhhh... AWESOME man..." });
	t3CharStates.insert({ 1, CharacterStates::ANGRY });


	task3.insert({ 3, "Drunkard" });
	task3.insert({ 4, "END" });
	t3CharStates.insert({ 2, CharacterStates::ANGRY });

	//TASK 4

	task4.insert({ 1, "Drunkard" });
	task4.insert({ 2, "Oh? You're back! Yeahhhh, let's see \nwhat you got!" });
	t4CharStates.insert({ 1, CharacterStates::THINKING });

	task4.insert({ 3, "Drunkard" });
	task4.insert({ 4, "..." });
	t4CharStates.insert({ 2, CharacterStates::ANGRY });

	task4.insert({ 5, "Drunkard" });
	task4.insert({ 6, "Wait a... uhhh... fuckin' uhhh... Wait a \nminute mate. This is just water." });
	t4CharStates.insert({ 3, CharacterStates::ANGRY });

	task4.insert({ 7, "Drunkard" });
	task4.insert({ 8, "Come on man, I'm not stupid, I'm not \ngonna drink water mate, get me \nsomething with alcohol man..." });
	t4CharStates.insert({ 4, CharacterStates::TURN });

	task4.insert({ 9, "Drunkard" });
	task4.insert({ 10, "You're as bad as that uhhh... bartender \nguy man... Come onnnnnnn, I know \nyou're better than this..." });
	t4CharStates.insert({ 5, CharacterStates::TURN });

	task4.insert({ 11, "You" });
	task4.insert({ 12, "..." });
	t4CharStates.insert({ 6, CharacterStates::TURN });

	task4.insert({ 13, "You" });
	task4.insert({ 14, "(This guy's getting on my nerves now.)"});
	t4CharStates.insert({ 7, CharacterStates::TURN });

	task4.insert({ 15, "You" });
	task4.insert({ 16, "END" });
	t4CharStates.insert({ 8, CharacterStates::TURN });

	task5.insert({ 1, "Drunkard" });
	task5.insert({ 2, "Come onnnn, don't be a wet wipe!" });
	t5CharStates.insert({ 1, CharacterStates::ANGRY });

	task5.insert({ 3, "Drunkard" });
	task5.insert({ 4, "END" });
	t5CharStates.insert({ 1, CharacterStates::ANGRY });

	//TASK 5
	task6.insert({ 1, "You" });
	task6.insert({ 2, "Alright, here you go." });
	t6CharStates.insert({ 1, CharacterStates::TURN });

	task6.insert({ 3, "Drunkard" });
	task6.insert({ 4, "Huh? Oh I knew you'd pull through man, \nyou got me a whole pitcher? You're \nawesome man...." });
	t6CharStates.insert({ 2, CharacterStates::THINKING });

	task6.insert({ 5, "Drunkard" });
	task6.insert({ 6, "What's it called?" });
	t6CharStates.insert({ 3, CharacterStates::THINKING });

	task6.insert({ 7, "You" });
	task6.insert({ 8, "Uhh.... it's a... vodka... clear... Uhh... \nClear vodka... NOT water?" });
	t6CharStates.insert({ 4, CharacterStates::THINKING });

	task6.insert({ 9, "Drunkard" });
	task6.insert({ 10, "Alright, cooooool. I love a bit of vodka \nmate." });
	t6CharStates.insert({ 5, CharacterStates::ANGRY });

	task6.insert({ 11, "Drunkard" });
	task6.insert({ 12, "..." });
	t6CharStates.insert({ 6, CharacterStates::TURN });

	task6.insert({ 13, "Drunkard" });
	task6.insert({ 14, "(He just drank the whole thing in a \nmatter of seconds.)" });
	t6CharStates.insert({ 7, CharacterStates::TURN });

	task6.insert({ 15, "Drunkard" });
	task6.insert({ 16, "So, you get uhh... You get up to much \ntoday?" });
	t6CharStates.insert({ 8, CharacterStates::THINKING });

	task6.insert({ 17, "Drunkard" });
	task6.insert({ 18, "Fishing? Up by the dam? Oh, yeah, \nyeah... that's cool man, that's \ninteresting... but... like... Uhh..." });
	t6CharStates.insert({ 9, CharacterStates::ANGRY });

	task6.insert({ 19, "Drunkard" });
	task6.insert({ 20, "Surely you have to wonder how the \nfish get up there?" });
	t6CharStates.insert({ 10, CharacterStates::NEUTRAL });

	task6.insert({ 21, "You" });
	task6.insert({ 22, "...? What?" });
	t6CharStates.insert({ 11, CharacterStates::NEUTRAL });

	task6.insert({ 23, "Drunkard" });
	task6.insert({ 24, "Ahhh, nothing man... i'm just... \ndrunk... " });
	t6CharStates.insert({ 12, CharacterStates::ANGRY });

	task6.insert({ 25, "Drunkard" });
	task6.insert({ 26, "Probably time... I went home... I'll see \nyou around mate..." });
	t6CharStates.insert({ 13, CharacterStates::NEUTRAL });

	task6.insert({ 27, "You" });
	task6.insert({ 28, "... " });
	t6CharStates.insert({ 14, CharacterStates::BLANK });

	task6.insert({ 29, "You" });
	task6.insert({ 30, "You know... I never really thought about \nthat... Huh." });
	t6CharStates.insert({ 15, CharacterStates::BLANK });

	task6.insert({ 31, "You" });
	task6.insert({ 32, "They probably just get released up \nthere for... One reason or another..." });
	t6CharStates.insert({ 16, CharacterStates::BLANK });

	task6.insert({ 33, "You" });
	task6.insert({ 34, "Ahh, I should head home too, I'm \nexhausted.I want to get up in time to go \nfishing again tomorrow!" });
	t6CharStates.insert({ 17, CharacterStates::BLANK });

	task6.insert({ 35, "You" });
	task6.insert({ 36, "END" });
	t6CharStates.insert({ 18, CharacterStates::BLANK });

	//Inserting into maps
	dayDialogue1.insert({ 2, task2 });
	dayDialogue1.insert({ 3, task3 });
	dayDialogue1.insert({ 4, task4 });
	dayDialogue1.insert({ 5, task5 });
	dayDialogue1.insert({ 6, task6 });

	charStates1.insert({ 2, t2CharStates });
	charStates1.insert({ 3, t3CharStates });
	charStates1.insert({ 4, t4CharStates });
	charStates1.insert({ 5, t5CharStates });
	charStates1.insert({ 6, t6CharStates });
}

void DrunkardText::initDay3()
{
	//This character has states neutral angry thinking and turn
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task3;
	std::map<int, CharacterStates> t3CharStates;

	std::map<int, std::string> task4;
	std::map<int, CharacterStates> t4CharStates;


	//TASK 1
	task1.insert({ 1, "Drunkard" });
	task1.insert({ 2, "Fuckin' bartender... too drunk my ass..." });
	t1CharStates.insert({ 1, CharacterStates::TURN });

	task1.insert({ 3, "Drunkard" });
	task1.insert({ 4, "Didn't even have that much... I think... \nFuckin'... asshole..." });
	t1CharStates.insert({ 2, CharacterStates::TURN });

	task1.insert({ 5, "Drunkard" });
	task1.insert({ 6, "..." });
	t1CharStates.insert({ 3, CharacterStates::NEUTRAL });

	task1.insert({ 7, "Drunkard" });
	task1.insert({ 8, "I'm gonna throw up." });
	t1CharStates.insert({ 4, CharacterStates::NEUTRAL });

	task1.insert({ 9, "Drunkard" });
	task1.insert({ 10, "END" });
	t1CharStates.insert({ 5, CharacterStates::NEUTRAL });

	//TASK 2
	task2.insert({ 1, "You" });
	task2.insert({ 2, "(I don't really want to speak to this \nguy to be honest...)" });
	t2CharStates.insert({ 1, CharacterStates::TURN });

	task2.insert({ 3, "You" });
	task2.insert({ 4, "Hey... Uhh... Excuse me, have you \nseen a guy in a red jacket pass by?" });
	t2CharStates.insert({ 2, CharacterStates::TURN });

	task2.insert({ 5, "Drunkard" });
	task2.insert({ 6, "Huh? Oh it's... Uhhhh... You again!" });
	t2CharStates.insert({ 3, CharacterStates::ANGRY });

	task2.insert({ 7, "Drunkard" });
	task2.insert({ 8, "Heyyyy, how've you been, mate? \nKeeping well, yeah?" });
	t2CharStates.insert({ 4, CharacterStates::THINKING });

	task2.insert({ 9, "Drunkard" });
	task2.insert({ 10, "Uh, listen, I don't suppose you could... \nUh... Do me a favour again?" });
	t2CharStates.insert({ 5, CharacterStates::THINKING });

	task2.insert({ 11, "You" });
	task2.insert({ 12, "No.I'm not doing that again. Go home." });
	t2CharStates.insert({ 6, CharacterStates::THINKING });

	task2.insert({ 13, "Drunkard" });
	task2.insert({ 14, "Awww.... Pshhh... Whatever man..." });
	t2CharStates.insert({ 7, CharacterStates::ANGRY });

	task2.insert({ 15, "Drunkard" });
	task2.insert({ 16, "END" });
	t2CharStates.insert({ 8, CharacterStates::NEUTRAL });

	//TASK 3
	task3.insert({ 1, "You" });
	task3.insert({ 2, "(Surely it doesn't belong to this guy \nright...?)" });
	t3CharStates.insert({ 1, CharacterStates::TURN });

	task3.insert({ 3, "Drunkard" });
	task3.insert({ 4, "Huh? It's you! Awwww, I'm... uh... Am I \nhappy to see you, mate!" });
	t3CharStates.insert({ 2, CharacterStates::THINKING });

	task3.insert({ 5, "You" });
	task3.insert({ 6, "You're not getting a drink off me again." });
	t3CharStates.insert({ 3, CharacterStates::THINKING });
	
	task3.insert({ 7, "Drunkard" });
	task3.insert({ 8, "..." });
	t3CharStates.insert({ 4, CharacterStates::ANGRY });

	task3.insert({ 9, "Drunkard" });
	task3.insert({ 10, "Evil being.... Foul... Sinister entity... \nRepent..." });
	t3CharStates.insert({ 5, CharacterStates::TURN });

	task3.insert({ 11, "You" });
	task3.insert({ 12, "Look man, I found this newspaper in the \npub, and I was just checking to see if \nit belonged to you." });
	t3CharStates.insert({ 6, CharacterStates::TURN });

	task3.insert({ 13, "You" });
	task3.insert({ 14, "Does it?" });
	t3CharStates.insert({ 7, CharacterStates::TURN });

	task3.insert({ 15, "Drunkard" });
	task3.insert({ 16, "Uhhh..." });
	t3CharStates.insert({ 8, CharacterStates::THINKING });

	task3.insert({ 17, "Drunkard" });
	task3.insert({ 18, "You know... I think it does! You're a \nreal... lifesaver... I gotta... return all \nthese favours one day..." });
	t3CharStates.insert({ 9, CharacterStates::NEUTRAL });

	task3.insert({ 19, "You" });
	task3.insert({ 20, "Nope. No you don't. Don't worry about it. \nEnjoy your evening." });
	t3CharStates.insert({ 10, CharacterStates::ANGRY });

	task3.insert({ 21, "Drunkard" });
	task3.insert({ 22, "END" });
	t3CharStates.insert({ 11, CharacterStates::THINKING });

	//TASK 4
	task4.insert({ 1, "Drunkard" });
	task4.insert({ 2, "Ourghhh..." });
	t4CharStates.insert({ 1, CharacterStates::TURN });

	task4.insert({ 3, "Drunkard" });
	task4.insert({ 4, "END" });
	t4CharStates.insert({ 2, CharacterStates::TURN });

	dayDialogue3.insert({ 1, task1 });
	dayDialogue3.insert({ 2, task2 });
	dayDialogue3.insert({ 3, task3 });
	dayDialogue3.insert({ 4, task4 });

	charStates3.insert({ 1, t1CharStates });
	charStates3.insert({ 2, t2CharStates });
	charStates3.insert({ 3, t3CharStates });
	charStates3.insert({ 4, t4CharStates });
}

void DrunkardText::initDay5()
{
	//This character has states neutral angry thinking and turn
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	task1.insert({ 1, "Drunkard" });
	task1.insert({ 2, "*hic*" });
	t1CharStates.insert({ 1, CharacterStates::TURN });

	task1.insert({ 3, "Drunkard" });
	task1.insert({ 4, "You fucked it." });
	t1CharStates.insert({ 2, CharacterStates::NEUTRAL });

	task1.insert({ 5, "You" });
	task1.insert({ 6, "Excuse me?" });
	t1CharStates.insert({ 3, CharacterStates::NEUTRAL });

	task1.insert({ 7, "Drunkard" });
	task1.insert({ 8, "..." });
	t1CharStates.insert({ 4, CharacterStates::NEUTRAL });

	task1.insert({ 9, "Drunkard" });
	task1.insert({ 10, "urnghh..." });
	t1CharStates.insert({ 5, CharacterStates::TURN });

	task1.insert({ 11, "Drunkard" });
	task1.insert({ 12, "END" });
	t1CharStates.insert({ 6, CharacterStates::TURN });

	dayDialogue5.insert({ 1, task1 });

	charStates5.insert({ 1, t1CharStates });
}
