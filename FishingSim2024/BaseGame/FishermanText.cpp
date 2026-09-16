#include "FishermanText.h"


FishermanText::FishermanText()
{
	initDay1();
	initDay2();
	initDay3();
}

FishermanText::~FishermanText()
{

}

CharacterStates FishermanText::returnCharState(PlayerData* pd, int prog)
{
	switch (pd->dayProgress)
	{

	case(2):
	{
		return charStates1.at(pd->tasks-1).at(prog);

	};	break;

	case(3):
	{
		return charStates2.at(1).at(prog);

	};	break;

	}
}

void FishermanText::initDay1()
{
	//This character has states neutral, angry, smile and thinking
	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task3;
	std::map<int, CharacterStates> t3CharStates;

	std::map<int, std::string> task4;
	std::map<int, CharacterStates> t4CharStates;

	task2.insert({ 1, "You" });
	task2.insert({ 2, "(The man seems to be looking for \nsomething in his bag...)" });
	t2CharStates.insert({ 1, CharacterStates::DISTANCE });

	task2.insert({ 3, "Fisherman" });
	task2.insert({ 4, "Huh...?" });
	t2CharStates.insert({ 2, CharacterStates::ANGRY });

	task2.insert({ 5, "Fisherman" });
	task2.insert({ 6, "Oh... Can I help you? Look, I'm kind of \nbusy right now, I don't know what you \nwant but can't you find someone else?" });
	t2CharStates.insert({ 3, CharacterStates::THINKING });

	task2.insert({ 7, "You" });
	task2.insert({ 8, "Oh... Um... you're friends with 'The \nSeaside Tavern' bartender right? He \nsaid you're also into fishing." });
	t2CharStates.insert({ 4, CharacterStates::THINKING });

	task2.insert({ 9, "Fisherman" });
	task2.insert({10, "Oh, yeah, I love it! I'm just finishing \nup for the day right now actually!" });
	t2CharStates.insert({ 5, CharacterStates::SMILE });

	task2.insert({ 11, "Fisherman" });
	task2.insert({ 12, "But I really don't have the time to talk, \nI've lost my keys and the last train home \nis due soon!" });
	t2CharStates.insert({ 6, CharacterStates::THINKING });

	task2.insert({ 13, "Fisherman" });
	task2.insert({ 14, "So I really need to focus on finding \nthem... Could I have dropped them? Oh, \nthis is a nightmare!" });
	t2CharStates.insert({ 7, CharacterStates::ANGRY });

	task2.insert({ 15, "You" });
	task2.insert({ 16, "Hmm... i could help if you like? Maybe \nyou dropped them on your way here?" });
	t2CharStates.insert({ 8, CharacterStates::ANGRY });

	task2.insert({ 17, "Fisherman" });
	task2.insert({ 18, "Would you do that for me? That would \nbe a great help! That is, if you really \ndon't mind..." });
	t2CharStates.insert({ 9, CharacterStates::SMILE });

	task2.insert({ 19, "You" });
	task2.insert({ 20, "Of course! I assume you came in on the \ntrain, and then straight here, yes? You \ndidn't stop anywhere else in town?" });
	t2CharStates.insert({ 10, CharacterStates::SMILE });

	task2.insert({ 21, "Fisherman" });
	task2.insert({ 22, "Hmmm... Nope! Straight here! I got off \nthe train, passed through the park, and \nthen up the main street until I was here." });
	t2CharStates.insert({ 11, CharacterStates::THINKING });

	task2.insert({ 23, "You" });
	task2.insert({ 24, "Alright, I'll see if I can retrace your \nsteps. I'll be back soon hopefully!" });
	t2CharStates.insert({ 12, CharacterStates::ANGRY });

	task2.insert({ 25, "Fisherman" });
	task2.insert({ 26, "END" });
	t2CharStates.insert({ 13, CharacterStates::ANGRY });

	//TASK 2 
	task3.insert({ 1, "Fisherman" });
	task3.insert({ 2, "I really need my keys..." });
	t3CharStates.insert({ 1, CharacterStates::DISTANCE });

	task3.insert({ 3, "Fisherman" });
	task3.insert({ 4, "END" });
	t3CharStates.insert({ 2, CharacterStates::NEUTRAL });

	//FINAL TASK

	task4.insert({ 1, "You" });
	task4.insert({ 2, "Hey, I found these in the park, are \nthey yours?" });
	t4CharStates.insert({ 1, CharacterStates::DISTANCE });

	task4.insert({ 3, "Fisherman" });
	task4.insert({ 4, "Oh? Let me have a look..." });
	t4CharStates.insert({ 2, CharacterStates::THINKING });

	task4.insert({ 5, "Fisherman" });
	task4.insert({ 6, "Oh, yes! These are mine! Oh, thank \nyou so much for the help!" });
	t4CharStates.insert({ 3, CharacterStates::SMILE });

	task4.insert({ 7, "You" });
	task4.insert({ 8, "No problem. I'm glad I could help!" });
	t4CharStates.insert({ 4, CharacterStates::SMILE });

	task4.insert({ 9, "Fisherman" });
	task4.insert({ 10, "Now, how can I help? I recall it was you \nwho approached me looking to talk \nearlier on." });
	t4CharStates.insert({ 5, CharacterStates::NEUTRAL });

	task4.insert({ 11, "You" });
	task4.insert({ 12, "Well, I'm also quite into fishing myself. \nMe and my friend have been going \nup to the dam to fish recently." });
	t4CharStates.insert({ 6, CharacterStates::NEUTRAL });

	task4.insert({ 13, "You" });
	task4.insert({ 14, "I was having a chat with the bartender \nabout it and he mentioned that you're \nalso into fishing." });
	t4CharStates.insert({ 7, CharacterStates::NEUTRAL });

	task4.insert({ 15, "You" });
	task4.insert({ 16, "He also said that you have an aversion \nto the dam, and honestly, I was just \ncurious as to why." });
	t4CharStates.insert({ 8, CharacterStates::THINKING });

	task4.insert({ 17, "Fisherman" });
	task4.insert({ 18, "..." });
	t4CharStates.insert({ 9, CharacterStates::ANGRY });

	task4.insert({ 19, "Fisherman" });
	task4.insert({ 20, "You must've moved here recently, I \nsuppose?" });
	t4CharStates.insert({ 10, CharacterStates::THINKING });

	task4.insert({ 21, "You" });
	task4.insert({ 22, "Well... yes, but I don't see how that-" });
	t4CharStates.insert({ 11, CharacterStates::THINKING });

	task4.insert({ 23, "Fisherman" });
	task4.insert({ 24, "Nobody goes fishing at that dam \nanymore." });
	t4CharStates.insert({ 12, CharacterStates::ANGRY });

	task4.insert({ 25, "You" });
	task4.insert({ 26, "What do you mean?" });
	t4CharStates.insert({ 13, CharacterStates::ANGRY });

	task4.insert({ 27, "Fisherman" });
	task4.insert({ 28, "..." });
	t4CharStates.insert({ 14, CharacterStates::THINKING });

	task4.insert({ 29, "Fisherman" });
	task4.insert({ 30, "Listen mate, why would you even want \nto go all that way for some fishing \nanyway?" });
	t4CharStates.insert({ 15, CharacterStates::SMILE });

	task4.insert({ 31, "Fisherman" });
	task4.insert({ 32, "There's plenty of fish in the sea, \nand you have plenty of beach to use \nright here!" });
	t4CharStates.insert({ 16, CharacterStates::SMILE });

	task4.insert({ 33, "Fisherman" });
	task4.insert({ 34, "Why not stay in town next time?" });
	t4CharStates.insert({ 17, CharacterStates::SMILE });

	task4.insert({ 35, "You" });
	task4.insert({ 36, "I don't know, I've never really been one \nto get scared of rumours..." });
	t4CharStates.insert({ 18, CharacterStates::SMILE });

	task4.insert({ 37, "You" });
	task4.insert({ 38, "My friend's lived here for years, and \nhe loves fishing up there." });
	t4CharStates.insert({ 19, CharacterStates::NEUTRAL });

	task4.insert({ 39, "You" });
	task4.insert({ 40, "I wouldn't want to let him down." });
	t4CharStates.insert({ 20, CharacterStates::NEUTRAL });

	task4.insert({ 41, "Fisherman" });
	task4.insert({ 42, "..." });
	t4CharStates.insert({ 21, CharacterStates::NEUTRAL });

	task4.insert({ 43, "Fisherman" });
	task4.insert({ 44, "I see." });
	t4CharStates.insert({ 22, CharacterStates::NEUTRAL });

	task4.insert({ 45, "Fisherman" });
	task4.insert({ 46, "Well, I really need to be getting my \ntrain now, thanks again for the help!" });
	t4CharStates.insert({ 23, CharacterStates::SMILE });

	task4.insert({ 47, "You" });
	task4.insert({ 48, "..." });
	t4CharStates.insert({ 24, CharacterStates::BLANK });

	task4.insert({ 49, "You" });
	task4.insert({ 50, "I suppose I'd best head home \naswell. But I do wonder..." });
	t4CharStates.insert({ 25, CharacterStates::BLANK });

	task4.insert({ 51, "You" });
	task4.insert({ 52, "If these rumours really concern \nthe locals so much, why isn't Dan \nbothered?" });
	t4CharStates.insert({ 26, CharacterStates::BLANK });

	task4.insert({ 53, "You" });
	task4.insert({ 54, "He never even mentioned something \nlike that..." });
	t4CharStates.insert({ 27, CharacterStates::BLANK });

	task4.insert({ 55, "You" });
	task4.insert({ 56, "END" });
	t4CharStates.insert({ 27, CharacterStates::BLANK });

	dayDialogue1.insert({ 1, task2 });
	dayDialogue1.insert({ 2, task3 });
	dayDialogue1.insert({ 3, task4 });

	charStates1.insert({ 1, t2CharStates });
	charStates1.insert({ 2, t3CharStates });
	charStates1.insert({ 3, t4CharStates });

}

void FishermanText::initDay2()
{
	//This character has states neutral, angry, smile and thinking
	std::map<int, std::string> task;
	std::map<int, CharacterStates> CharStates;

	task.insert({ 1, "Fisherman" });
	task.insert({ 2, "Dum da dum... dum diddily dum da \ndum..." });
	CharStates.insert({ 1, CharacterStates::DISTANCE });

	task.insert({ 3, "Fisherman" });
	task.insert({ 4, "(He seems busy...)" });
	CharStates.insert({ 2, CharacterStates::DISTANCE });

	task.insert({ 5, "Fisherman" });
	task.insert({ 6, "END" });
	CharStates.insert({ 3, CharacterStates::DISTANCE });

	dayDialogue2.insert({ 1, task });

	charStates2.insert({ 1, CharStates });
}

void FishermanText::initDay3()
{
	//This character has states neutral, angry, smile and thinking
	std::map<int, std::string> task;
	std::map<int, CharacterStates> CharStates;

	task.insert({ 1, "Fisherman" });
	task.insert({ 2, "Dum da dum... dum diddily dum da \ndum..." });
	CharStates.insert({ 1, CharacterStates::DISTANCE });

	task.insert({ 3, "Fisherman" });
	task.insert({ 4, "(He seems busy...)" });
	CharStates.insert({ 2, CharacterStates::DISTANCE });

	task.insert({ 5, "Fisherman" });
	task.insert({ 6, "END" });
	CharStates.insert({ 3, CharacterStates::DISTANCE });

	dayDialogue3.insert({ 1, task });

	charStates3.insert({ 1, CharStates });
}

