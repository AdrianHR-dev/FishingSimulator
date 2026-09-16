#include "BarflyText.h"

BarflyText::BarflyText()
{
	initDay1();
	initDay4();
	initDay5();
	initDay6();
	initFinalDay();
}

BarflyText::~BarflyText()
{

}

CharacterStates BarflyText::returnCharState(PlayerData* pd, int prog)
{
	if (pd->dayProgress < 4)
	{
		return charStates1.at(1).at(prog);
	}
	else
	{
		switch (pd->dayProgress)
		{

		case(4):
		{
			return charStates4.at(pd->tasks).at(prog);

		};	break;

		case(5):
		{
			return charStates5.at(pd->tasks).at(prog);

		};	break;

		case(6):
		{
			return charStates6.at(1).at(prog);

		};	break;

		case(9):
		{
			return charStates9.at(1).at(prog);

		};	break;

		}
	}
}

void BarflyText::initDay1()
{
	//This character has states neutral, angry, smile and thinking
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	task1.insert({ 1, "???" });
	task1.insert({ 2, "..." });
	t1CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task1.insert({ 3, "You"});
	task1.insert({ 4, "..." });
	t1CharStates.insert({ 2, CharacterStates::NEUTRAL });

	task1.insert({ 5, "You" });
	task1.insert({ 6, "He doesn't seem keen to talk..." });
	t1CharStates.insert({ 3, CharacterStates::NEUTRAL });

	task1.insert({ 7, "You" });
	task1.insert({ 8, "END" });
	t1CharStates.insert({ 4, CharacterStates::NEUTRAL });


	dayDialogue1.insert({ 1, task1 });

	charStates1.insert({ 1, t1CharStates });

}

void BarflyText::initDay4()
{
	//This character has states neutral, angry, smile and thinking
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task3;
	std::map<int, CharacterStates> t3CharStates;

	task1.insert({ 1, "???" });
	task1.insert({ 2, "..." });
	t1CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task1.insert({ 3, "You" });
	task1.insert({ 4, "..." });
	t1CharStates.insert({ 2, CharacterStates::NEUTRAL });

	task1.insert({ 5, "You" });
	task1.insert({ 6, "He doesn't seem keen to talk..." });
	t1CharStates.insert({ 3, CharacterStates::NEUTRAL });

	task1.insert({ 7, "You" });
	task1.insert({ 8, "END" });
	t1CharStates.insert({ 4, CharacterStates::NEUTRAL });

	task2.insert({ 1, "You" });
	task2.insert({ 2, "Hello?" });
	t2CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task2.insert({ 3, "???" });
	task2.insert({ 4, "..." });
	t2CharStates.insert({ 2, CharacterStates::NEUTRAL });

	task2.insert({ 5, "???" });
	task2.insert({ 6, "Hey." });
	t2CharStates.insert({ 3, CharacterStates::TURN });

	task2.insert({ 7, "???" });
	task2.insert({ 8, "I think me and you need to have a chat." });
	t2CharStates.insert({ 4, CharacterStates::TURN });

	task2.insert({ 9, "Clark"});
	task2.insert({ 10, "My name is Clark. I've heard you running \naround, night after night, asking about \nthat dam." });
	t2CharStates.insert({ 5, CharacterStates::TURN });

	task2.insert({ 11, "Clark"});
	task2.insert({ 12, "I can help you. But I need you to promise \nto keep your mouth shut from here on \nout." });
	t2CharStates.insert({ 6, CharacterStates::TURN });

	task2.insert({ 13, "You"});
	task2.insert({ 14, "Excuse me?" });
	t2CharStates.insert({ 7, CharacterStates::TURN });

	task2.insert({ 15, "Clark"});
	task2.insert({ 16, "That guy you spoke with yesterday? Dead \nend, as you presumed." });
	t2CharStates.insert({ 8, CharacterStates::THINKING });

	task2.insert({ 17, "Clark" });
	task2.insert({ 18, "There are powers at play here. Powers that \nwill already be keeping an eye on you \nI imagine." });
	t2CharStates.insert({ 9, CharacterStates::THINKING });

	task2.insert({ 19, "Clark" });
	task2.insert({ 20, "Now listen carefully. You gain my trust, and \nwe can talk more." });
	t2CharStates.insert({ 10, CharacterStates::THINKING });

	task2.insert({ 21, "Clark" });
	task2.insert({ 22, "There's an old hydro plant deep in the \nwoods. It's been derelict for years." });
	t2CharStates.insert({ 11, CharacterStates::TURN });

	task2.insert({ 23, "Clark" });
	task2.insert({ 24, "I used to work there. But there was more \ngoing on than what they told me." });
	t2CharStates.insert({ 12, CharacterStates::TURN });

	task2.insert({ 25, "Clark" });
	task2.insert({ 26, "My old notebook should still be in my old \nmanager's desk. You bring that to me I'll \nexplain what the notes are about." });
	t2CharStates.insert({ 13, CharacterStates::TURN });

	task2.insert({ 27, "Clark" });
	task2.insert({ 28, "Keep your head down. You speak to \nno-one about this but me from here on out." });
	t2CharStates.insert({ 14, CharacterStates::TURN });

	task2.insert({ 29, "Clark" });
	task2.insert({ 30, "Now, before you go. I'm going to give you \nthis puzzle in my newspaper." });
	t2CharStates.insert({ 15, CharacterStates::TURN });

	task2.insert({ 31, "Clark" });
	task2.insert({ 32, "You are going to solve it, and then \ntell the bartender that's why I called \nyou over." });
	t2CharStates.insert({ 16, CharacterStates::TURN });
	
	task2.insert({ 33, "Clark" });
	task2.insert({ 34, "To simply help a man with his newspaper \npuzzle." });
	t2CharStates.insert({ 17, CharacterStates::NEUTRAL });

	task2.insert({ 35, "Clark" });
	task2.insert({ 36, "PUZZLE" });
	t2CharStates.insert({ 18, CharacterStates::TURN });

	task2.insert({ 37, "Clark" });
	task2.insert({ 38, "..." });
	t2CharStates.insert({ 19, CharacterStates::NEUTRAL });

	task2.insert({ 39, "Clark" });
	task2.insert({ 40, "Hmph. You've got a good head on you." });
	t2CharStates.insert({ 20, CharacterStates::TURN });

	task2.insert({ 41, "Clark" });
	task2.insert({ 42, "Now if you really want to go through \nwith this, go to woods and find that \nnotebook." });
	t2CharStates.insert({ 21, CharacterStates::NEUTRAL });

	task2.insert({ 43, "You" });
	task2.insert({ 44, "...?" });
	t2CharStates.insert({ 22, CharacterStates::BLANK });

	task2.insert({ 45, "You" });
	task2.insert({ 46, "(What just happened...?)" });
	t2CharStates.insert({ 23, CharacterStates::BLANK });

	task2.insert({ 47, "You" });
	task2.insert({ 48, "(Is this guy serious? It's gonna be pitch \nblack down there right now!)" });
	t2CharStates.insert({ 24, CharacterStates::BLANK });

	task2.insert({ 49, "You" });
	task2.insert({ 50, "(How am I gonna find a notebook even if I \nget into the building?)" });
	t2CharStates.insert({ 25, CharacterStates::BLANK });

	task2.insert({ 51, "You" });
	task2.insert({ 52, "(...)\n(Could he have been the one that guy \nsaid was following him yesterday?)" });
	t2CharStates.insert({ 26, CharacterStates::BLANK });

	task2.insert({ 53, "You" });
	task2.insert({ 54, "(This is too much. Is this really worth it?)" });
	t2CharStates.insert({ 27, CharacterStates::BLANK });

	task2.insert({ 55, "You" });
	task2.insert({ 56, "END" });
	t2CharStates.insert({ 28, CharacterStates::BLANK });

	task3.insert({ 1, "Clark" });
	task3.insert({ 2, "The forest is up towards the \nnorth-east of town." });
	t3CharStates.insert({ 1, CharacterStates::TURN });

	task3.insert({ 3, "Clark" });
	task3.insert({ 4, "Go there if you're serious about this." });
	t3CharStates.insert({ 2, CharacterStates::TURN });

	task3.insert({ 5, "You" });
	task3.insert({ 6, "END" });
	t3CharStates.insert({ 3, CharacterStates::TURN });

	dayDialogue4.insert({ 1, task1 });
	dayDialogue4.insert({ 2, task2 });
	dayDialogue4.insert({ 3, task3 });

	charStates4.insert({ 1, t1CharStates });
	charStates4.insert({ 2, t2CharStates });
	charStates4.insert({ 3, t3CharStates });

}

void BarflyText::initDay5()
{
	//This character has states neutral, angry, smile and thinking
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;


	task1.insert({ 1, "Clark" });
	task1.insert({ 2, "You're back." });
	t1CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task1.insert({ 3, "Clark" });
	task1.insert({ 4, "Did you find my notebook?" });
	t1CharStates.insert({ 2, CharacterStates::TURN });

	task1.insert({ 5, "You" });
	task1.insert({ 6, "Yeah, actually, At least i think so..." });
	t1CharStates.insert({ 3, CharacterStates::TURN });

	task1.insert({ 7, "You" });
	task1.insert({ 8, "What's the deal with this anyway? What is \nthis sketch supposed to be?" });
	t1CharStates.insert({ 4, CharacterStates::NEUTRAL });

	task1.insert({ 7, "Clark" });
	task1.insert({ 8, "..." });
	t1CharStates.insert({ 5, CharacterStates::NEUTRAL });

	task1.insert({ 9, "Clark" });
	task1.insert({ 10, "I worked on the construction project up \nthere." });
	t1CharStates.insert({ 6, CharacterStates::NEUTRAL });

	task1.insert({ 11, "Clark" });
	task1.insert({ 12, "A simple hydro power dam, the kind of \nthing I'd worked on before." });
	t1CharStates.insert({ 7, CharacterStates::NEUTRAL });

	task1.insert({ 13, "Clark" });
	task1.insert({ 14, "I worked on what I was asked to but there \nwas clearly a side project going on." });
	t1CharStates.insert({ 8, CharacterStates::NEUTRAL });

	task1.insert({ 15, "Clark" });
	task1.insert({ 16, "Something the superiors weren't willing to \ntalk about." });
	t1CharStates.insert({ 9, CharacterStates::TURN });

	task1.insert({ 17, "Clark" });
	task1.insert({ 18, "I tried to keep an eye on the other team, \nI kept asking questions and eventually..." });
	t1CharStates.insert({ 10, CharacterStates::TURN });

	task1.insert({ 19, "Clark" });
	task1.insert({ 20, "They let me go." });
	t1CharStates.insert({ 11, CharacterStates::NEUTRAL });

	task1.insert({ 21, "Clark" });
	task1.insert({ 22, "But I know there's something up there." });
	t1CharStates.insert({ 12, CharacterStates::THINKING });

	task1.insert({ 23, "Clark" });
	task1.insert({ 24, "Something that needs to be destroyed." });
	t1CharStates.insert({ 13, CharacterStates::THINKING });

	task1.insert({ 25, "You" });
	task1.insert({ 26, "Something to do with this other hole then?" });
	t1CharStates.insert({ 14, CharacterStates::THINKING });

	task1.insert({ 27, "Clark" });
	task1.insert({ 28, "..." });
	t1CharStates.insert({ 15, CharacterStates::NEUTRAL });

	task1.insert({ 29, "Clark" });
	task1.insert({ 30, "Don't go fishing tomorrow." });
	t1CharStates.insert({ 16, CharacterStates::TURN });

	task1.insert({ 31, "Clark" });
	task1.insert({ 32, "I know, you're friend loves it and would be \ndisappointed and blah, blah, blah..." });
	t1CharStates.insert({ 17, CharacterStates::TURN });

	task1.insert({ 33, "Clark" });
	task1.insert({ 34, "Don't go." });
	t1CharStates.insert({ 18, CharacterStates::NEUTRAL });

	task1.insert({ 35, "Clark" });
	task1.insert({ 36, "We can end this together, but I have some \npreparations to make before then." });
	t1CharStates.insert({ 19, CharacterStates::NEUTRAL });

	task1.insert({ 37, "You" });
	task1.insert({ 38, "..." });
	t1CharStates.insert({ 20, CharacterStates::NEUTRAL });

	task1.insert({ 39, "You" });
	task1.insert({ 40, "With all due respect, I don't even know you." });
	t1CharStates.insert({ 21, CharacterStates::NEUTRAL });

	task1.insert({ 41, "You" });
	task1.insert({ 42, "You keep playing vague after sending me \nall the way out to an abandoned building \nin the woods." });
	t1CharStates.insert({ 22, CharacterStates::NEUTRAL });

	task1.insert({ 43, "You" });
	task1.insert({ 44, "If you can't give me a reason to trust you \nmore than Dan then frankly I don't care." });
	t1CharStates.insert({ 23, CharacterStates::NEUTRAL });

	task1.insert({ 45, "Clark"});
	task1.insert({ 46, "..." });
	t1CharStates.insert({ 24, CharacterStates::NEUTRAL });

	task1.insert({ 47, "Clark" });
	task1.insert({ 48, "I see." });
	t1CharStates.insert({ 25, CharacterStates::NEUTRAL });

	task1.insert({ 49, "Clark" });
	task1.insert({ 50, "It sounds like you've already been taken \nin by the illusion." });
	t1CharStates.insert({ 26, CharacterStates::NEUTRAL });

	task1.insert({ 51, "Clark" });
	task1.insert({ 52, "I don't imagine we'll be speaking again." });
	t1CharStates.insert({ 27, CharacterStates::NEUTRAL });

	task1.insert({ 53, "Clark" });
	task1.insert({ 54, "Goodbye." });
	t1CharStates.insert({ 28, CharacterStates::NEUTRAL });

	task1.insert({ 55, "You" });
	task1.insert({ 56, "..." });
	t1CharStates.insert({ 29, CharacterStates::BLANK });

	task1.insert({ 57, "You" });
	task1.insert({ 58, "Whatever." });
	t1CharStates.insert({ 30, CharacterStates::BLANK });

	task1.insert({ 59, "You" });
	task1.insert({ 60, "This town is full of freaks." });
	t1CharStates.insert({ 31, CharacterStates::BLANK });

	task1.insert({ 61, "You" });
	task1.insert({ 62, "I'm going home." });
	t1CharStates.insert({ 32, CharacterStates::BLANK });

	task1.insert({ 63, "You" });
	task1.insert({ 64, "END" });
	t1CharStates.insert({ 33, CharacterStates::BLANK });

	dayDialogue5.insert({ 1, task1 });

	charStates5.insert({ 1, t1CharStates });
}

void BarflyText::initDay6()
{
	//This character has states neutral, angry, smile and thinking
	std::map<int, std::string> task;
	std::map<int, CharacterStates> charStates;

	task.insert({ 1, "You"});
	task.insert({ 2, "It's you! Please, you've gotta help me!"});
	charStates.insert({ 1, CharacterStates::NEUTRAL });

	task.insert({ 3, "You" });
	task.insert({ 4, "My friend's gone, and I think he's in trouble! \nI found a hand up there in the water and-!" });
	charStates.insert({ 2, CharacterStates::NEUTRAL });

	task.insert({ 5, "Clark" });
	task.insert({ 6, "It's too late. I told you." });
	charStates.insert({ 3, CharacterStates::TURN });

	task.insert({ 7, "You" });
	task.insert({ 8, "What?" });
	charStates.insert({ 4, CharacterStates::TURN });

	task.insert({ 9, "You" });
	task.insert({ 10, "Fuck you!" });
	charStates.insert({ 5, CharacterStates::NEUTRAL });

	task.insert({ 11, "Clark" });
	task.insert({ 12, "Calm down." });
	charStates.insert({ 6, CharacterStates::NEUTRAL });

	task.insert({ 13, "You" });
	task.insert({ 14, "No! I won't! You knew something was \nwrong! You knew-" });
	charStates.insert({ 7, CharacterStates::NEUTRAL });

	task.insert({ 15, "Clark" });
	task.insert({ 16, "Calm down, please." });
	charStates.insert({ 8, CharacterStates::TURN });

	task.insert({ 17, "Clark" });
	task.insert({ 18, "I'm sorry about your friend." });
	charStates.insert({ 9, CharacterStates::TURN });

	task.insert({ 19, "Clark" });
	task.insert({ 20, "But you're here, speaking to me." });
	charStates.insert({ 10, CharacterStates::NEUTRAL });

	task.insert({ 21, "Clark" });
	task.insert({ 22, "Which means it's not too late to save you." });
	charStates.insert({ 11, CharacterStates::THINKING });

	task.insert({ 23, "Clark" });
	task.insert({ 24, "We can make sure no-one else meets the \nsame fate as your friend." });
	charStates.insert({ 12, CharacterStates::TURN });

	task.insert({ 25, "You" });
	task.insert({ 26, "..." });
	charStates.insert({ 13, CharacterStates::TURN });

	task.insert({ 27, "You" });
	task.insert({ 28, "Tell me everything you know." });
	charStates.insert({ 14, CharacterStates::NEUTRAL });

	task.insert({ 29, "Clark" });
	task.insert({ 30, "..." });
	charStates.insert({ 15, CharacterStates::THINKING });

	task.insert({ 31, "Clark" });
	task.insert({ 32, "..." });
	charStates.insert({ 16, CharacterStates::THINKING });

	task.insert({ 33, "Clark" });
	task.insert({ 34, "I need to know I can trust you before-" });
	charStates.insert({ 17, CharacterStates::THINKING });

	task.insert({ 35, "You" });
	task.insert({ 36, "*I* need to know I can trust *YOU*!" });
	charStates.insert({ 18, CharacterStates::NEUTRAL });

	task.insert({ 37, "You" });
	task.insert({ 38, "Why on earth would I put my trust in \nyou when you've told me NOTHING?" });
	charStates.insert({ 19, CharacterStates::THINKING });

	task.insert({ 39, "Clark" });
	task.insert({ 40, "..." });
	charStates.insert({ 20, CharacterStates::NEUTRAL });

	task.insert({ 41, "Clark" });
	task.insert({ 42, "Yeah. Ok \nFine." });
	charStates.insert({ 21, CharacterStates::NEUTRAL });

	task.insert({ 43, "Clark" });
	task.insert({ 44, "But afterwards, I'll need your help\nWe can stop this together." });
	charStates.insert({ 22, CharacterStates::NEUTRAL });

	task.insert({ 45, "You" });
	task.insert({ 46, "..." });
	charStates.insert({ 23, CharacterStates::NEUTRAL });

	task.insert({ 47, "Clark" });
	task.insert({ 48, "Something resides deep in the \nwaters of that dam. Something that needs \nto be fed, and fed regularly." });
	charStates.insert({ 24, CharacterStates::TURN });

	task.insert({ 49, "Clark" });
	task.insert({ 50, "This entire dam project seems to have \nbeen a cover up to make a feeding trough \nfor a gargantuan beast." });
	charStates.insert({ 25, CharacterStates::TURN });

	task.insert({ 51, "Clark" });
	task.insert({ 52, "It seems like it has an ability to slowly \ninfluence those who get \ntoo close." });
	charStates.insert({ 26, CharacterStates::TURN });

	task.insert({ 53, "Clark" });
	task.insert({ 54, "Your friend was beyond saving once it \ngot a hold of his mind." });
	charStates.insert({ 27, CharacterStates::NEUTRAL });

	task.insert({ 55, "Clark" });
	task.insert({ 56, "But you're still here. And you clearly \nstill have some resistance to it." });
	charStates.insert({ 28, CharacterStates::THINKING });

	task.insert({ 57, "Clark" });
	task.insert({ 58, "The beast expects you." });
	charStates.insert({ 29, CharacterStates::NEUTRAL });

	task.insert({ 59, "Clark" });
	task.insert({ 60, "If it doesn't get you soon, it will \ngrow impatient." });
	charStates.insert({ 30, CharacterStates::NEUTRAL });

	task.insert({ 61, "Clark" });
	task.insert({ 62, "And here's where I need your help." });
	charStates.insert({ 31, CharacterStates::TURN });

	task.insert({ 63, "Clark" });
	task.insert({ 64, "Go back to the dam tomorrow. Same as \nevery previous day." });
	charStates.insert({ 32, CharacterStates::TURN });

	task.insert({ 65, "Clark" });
	task.insert({ 66, "But once you get there, bide your time." });
	charStates.insert({ 33, CharacterStates::TURN });

	task.insert({ 67, "Clark" });
	task.insert({ 68, "Don't get lured into the water. No matter \nwhat you see or feel, do not enter \nthe water." });
	charStates.insert({ 34, CharacterStates::TURN });

	task.insert({ 69, "Clark" });
	task.insert({ 70, "Hopefully, the beast will grow impatient \nand reach out to you. \nThat's when I'll strike." });
	charStates.insert({ 35, CharacterStates::TURN });

	task.insert({ 71, "Clark" });
	task.insert({ 72, "We'll sever the limb and it will feed \non this town no more." });
	charStates.insert({ 36, CharacterStates::TURN });

	task.insert({ 73, "Clark" });
	task.insert({ 74, "I'm trusting you here." });
	charStates.insert({ 37, CharacterStates::TURN });

	task.insert({ 75, "Clark" });
	task.insert({ 76, "Please." });
	charStates.insert({ 38, CharacterStates::TURN });

	task.insert({ 77, "Clark" });
	task.insert({ 78, "Trust me." });
	charStates.insert({ 39, CharacterStates::NEUTRAL });

	task.insert({ 79, "Clark" });
	task.insert({ 80, "END" });
	charStates.insert({ 40, CharacterStates::NEUTRAL });
	
	dayDialogue6.insert({ 1, task });

	charStates6.insert({ 1, charStates });

}

void BarflyText::initFinalDay()
{
	//This character has states neutral, angry, smile and thinking
	std::map<int, std::string> task;
	std::map<int, CharacterStates> charStates;

	task.insert({ 1, "Clark" });
	task.insert({ 2, "..." });
	charStates.insert({ 1, CharacterStates::NEUTRAL });

	task.insert({ 3, "Clark" });
	task.insert({ 4, "Thanks for your help. Luring it out \nallowed me to sever the limb with a \nwell timed detonation" });
	charStates.insert({ 2, CharacterStates::TURN });

	task.insert({ 5, "Clark" });
	task.insert({ 6, "The rubble blocking the hole wouldn't \nhave been enough, but thanks to you..." });
	charStates.insert({ 3, CharacterStates::TURN });

	task.insert({ 7, "Clark" });
	task.insert({ 8, "There's nothing left to try break back \nthrough." });
	charStates.insert({ 4, CharacterStates::NEUTRAL });

	task.insert({ 9, "You" });
	task.insert({ 10, "So... now what?" });
	charStates.insert({ 5, CharacterStates::NEUTRAL });

	task.insert({ 11, "Clark" });
	task.insert({ 12, "As far as you're concerned?" });
	charStates.insert({ 6, CharacterStates::TURN });

	task.insert({ 13, "Clark" });
	task.insert({ 14, "Nothing." });
	charStates.insert({ 7, CharacterStates::NEUTRAL });

	task.insert({ 15, "Clark" });
	task.insert({ 16, "It's over. We won. If I were you, \nI'd move on and forget this ever happened." });
	charStates.insert({ 8, CharacterStates::NEUTRAL });

	task.insert({ 17, "You" });
	task.insert({ 18, "What? That's it?" });
	charStates.insert({ 9, CharacterStates::NEUTRAL });

	task.insert({ 19, "Clark" });
	task.insert({ 20, "Of course. What more is there to say?" });
	charStates.insert({ 10, CharacterStates::TURN });

	task.insert({ 21, "Clark" });
	task.insert({ 22, "Tell no-one of this." });
	charStates.insert({ 11, CharacterStates::TURN });

	task.insert({ 23, "Clark" });
	task.insert({ 24, "Do not look further into any of this." });
	charStates.insert({ 12, CharacterStates::TURN });

	task.insert({ 25, "Clark" });
	task.insert({ 26, "We won't be meeting again. Goodbye." });
	charStates.insert({ 13, CharacterStates::TURN });

	task.insert({ 27, "You" });
	task.insert({ 28, "..." });
	charStates.insert({ 14, CharacterStates::BLANK });

	task.insert({ 29, "You" });
	task.insert({ 30, "What?" });
	charStates.insert({ 15, CharacterStates::BLANK });

	task.insert({ 31, "You" });
	task.insert({ 32, "END" });
	charStates.insert({ 16, CharacterStates::BLANK });

	dayDialogue9.insert({ 1, task });

	charStates9.insert({ 1, charStates });

}
