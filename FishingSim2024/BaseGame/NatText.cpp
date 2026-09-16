#include "NatText.h"

NatText::NatText()
{ 
	initDay1();
	initDay2();
	initDay3();
	initDay4();
}

NatText::~NatText()
{

}

void NatText::initDay1()
{
	//This character has states neutral angry thinking and smile

	std::map<int, std::string> day1;
	std::map<int, CharacterStates> day1CStates;

	//SECOND TASK
	day1.insert({ 1, "Nat" });
	day1.insert({ 2, "The last train of the night is never on \ntime..." });
	day1CStates.insert({ 1, CharacterStates::THINKING });

	day1.insert({ 3, "Nat" });
	day1.insert({ 4, "END" });
	day1CStates.insert({ 2, CharacterStates::THINKING });

	dayDialogue1.insert({ 1, day1 });

	charStates1.insert({ 1, day1CStates });


}

void NatText::initDay2()
{
	//This character has states neutral angry thinking and smile

	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task3;
	std::map<int, CharacterStates> t3CharStates;

	//SECOND NIGHT
	task1.insert({ 1, "Nat" });
	task1.insert({ 2, "..." });
	t1CharStates.insert({ 1, CharacterStates::THINKING });

	task1.insert({ 3, "Nat" });
	task1.insert({ 4, "I hope the train's on time tonight..." });
	t1CharStates.insert({ 2, CharacterStates::THINKING });

	task1.insert({ 5, "Nat" });
	task1.insert({ 6, "But I don't have high hopes." });
	t1CharStates.insert({ 3, CharacterStates::NEUTRAL });

	task1.insert({ 7, "Nat" });
	task1.insert({ 8, "END" });
	t1CharStates.insert({ 4, CharacterStates::NEUTRAL });

	//Dialogue 2

	task2.insert({ 1, "Nat" });
	task2.insert({ 2, "You're looking for a set of keys?" });
	t2CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task2.insert({ 3, "Nat" });
	task2.insert({ 4, "I'm afraid I can't help you, I haven't \nseen any around here." });
	t2CharStates.insert({ 2, CharacterStates::NEUTRAL });

	task2.insert({ 5, "Nat" });
	task2.insert({ 6, "But if you're waiting for the train, I \nwouldn't worry about missing it." });
	t2CharStates.insert({ 3, CharacterStates::THINKING });

	task2.insert({ 7, "Nat" });
	task2.insert({ 8, "It's always late" });
	t2CharStates.insert({ 4, CharacterStates::SMILE });

	task2.insert({ 9, "Nat" });
	task2.insert({ 10, "END" });
	t2CharStates.insert({ 5, CharacterStates::ANGRY });

	task3.insert({ 1, "Nat" });
	task3.insert({ 2, "Did you find what you were looking for?" });
	t3CharStates.insert({ 1, CharacterStates::SMILE });

	task3.insert({ 3, "Nat" });
	task3.insert({ 4, "END" });
	t3CharStates.insert({ 2, CharacterStates::THINKING });

	dayDialogue2.insert({ 1, task1 });
	dayDialogue2.insert({ 2, task2 });
	dayDialogue2.insert({ 3, task3 });

	charStates2.insert({ 1, t1CharStates });
	charStates2.insert({ 2, t2CharStates });
	charStates2.insert({ 3, t3CharStates });


}

void NatText::initDay3()
{
	//This character has states neutral angry thinking and smile

	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task4;
	std::map<int, CharacterStates> t4CharStates;

	//THIRD NIGHT
	task1.insert({ 1, "Nat" });
	task1.insert({ 2, "..." });
	t1CharStates.insert({ 1, CharacterStates::THINKING });

	task1.insert({ 3, "Nat" });
	task1.insert({ 4, "The last train of the night is never on \ntime..." });
	t1CharStates.insert({ 2, CharacterStates::SMILE });

	task1.insert({ 5, "Nat" });
	task1.insert({ 6, "END"});
	t1CharStates.insert({ 3, CharacterStates::THINKING });

	//TASK 2

	task2.insert({ 1, "Nat" });
	task2.insert({ 2, "..." });
	t2CharStates.insert({ 1, CharacterStates::THINKING });

	task2.insert({ 3, "You" });
	task2.insert({ 4, "Hey! Sorry to bother you, do you have \ntime for a quick chat?" });
	t2CharStates.insert({ 2, CharacterStates::THINKING });

	task2.insert({ 5, "Nat" });
	task2.insert({ 6, "About what? Do you know something?" });
	t2CharStates.insert({ 3, CharacterStates::SMILE });

	task2.insert({ 7, "Nat" });
	task2.insert({ 8, "Are you the one tailing me?" });
	t2CharStates.insert({ 4, CharacterStates::ANGRY });

	task2.insert({ 9, "You" });
	task2.insert({ 10, "Woah, what? No, no!" });
	t2CharStates.insert({ 5, CharacterStates::ANGRY });

	task2.insert({ 11, "Nat" });
	task2.insert({ 12, "You're an agent of 'Big Small', I know it!" });
	t2CharStates.insert({ 6, CharacterStates::ANGRY });

	task2.insert({ 13, "You" });
	task2.insert({ 14, "No, I'm not! I don't even know what \nyou're talking about, slow down!" });
	t2CharStates.insert({ 7, CharacterStates::ANGRY });

	task2.insert({ 15, "Nat" });
	task2.insert({ 16, "..." });
	t2CharStates.insert({ 8, CharacterStates::NEUTRAL });

	task2.insert({ 17, "Nat" });
	task2.insert({ 18, "'Big big'?" });
	t2CharStates.insert({ 9, CharacterStates::ANGRY });

	task2.insert({ 19, "You" });
	task2.insert({ 20, "No! 'Big' nothing! I just want to ask \nif you know about the dam rumours!" });
	t2CharStates.insert({ 10, CharacterStates::NEUTRAL });

	task2.insert({ 21, "Nat" });
	task2.insert({ 22, "Oh, you think I'm gonna speak to \nan agent of 'Big Nothing'? Fat chance!" });
	t2CharStates.insert({ 11, CharacterStates::ANGRY });

	task2.insert({ 23, "You" });
	task2.insert({ 24, "(This is going to be harder than I \nthought.)" });
	t2CharStates.insert({ 12, CharacterStates::ANGRY });

	task2.insert({ 25, "You" });
	task2.insert({ 26, "Ok, listen. I'm not an agent of ANY \norganisation, ok? I have no idea what \nyou're talking about!" });
	t2CharStates.insert({ 13, CharacterStates::ANGRY });

	task2.insert({ 27, "You" });
	task2.insert({ 28, "I just heard that you might be able to \nhelp me learn something about the dam \noutside of town" });
	t2CharStates.insert({ 14, CharacterStates::SMILE });

	task2.insert({ 29, "Nat" });
	task2.insert({ 30, "..." });
	t2CharStates.insert({ 15, CharacterStates::SMILE });

	task2.insert({ 31, "Nat" });
	task2.insert({ 32, "The dam...? Yeah, I know a thing or \ntwo..." });
	t2CharStates.insert({ 16, CharacterStates::SMILE });

	task2.insert({ 33, "Nat" });
	task2.insert({ 34, "But I need to know I can trust you with \nthis." });
	t2CharStates.insert({ 17, CharacterStates::SMILE });

	task2.insert({ 35, "You" });
	task2.insert({ 36, "(Alright, now we're getting somewhere.)" });
	t2CharStates.insert({ 18, CharacterStates::SMILE });

	task2.insert({ 37, "Nat" });
	task2.insert({ 38, "..." });
	t2CharStates.insert({ 19, CharacterStates::THINKING });

	task2.insert({ 39, "Nat" });
	task2.insert({ 40, "Tell you what, I don't suppose you could \ndo me a favour?" });
	t2CharStates.insert({ 20, CharacterStates::NEUTRAL });

	task2.insert({ 41, "Nat" });
	task2.insert({ 42, "See I've been investigating a few \nstrange incidents in this town over the \nyears... " });
	t2CharStates.insert({ 21, CharacterStates::SMILE });

	task2.insert({ 43, "Nat" });
	task2.insert({ 44, "There's something big going on here... \nAnd I'm working tirelessly to find out \nwhat!" });
	t2CharStates.insert({ 22, CharacterStates::SMILE });

	task2.insert({ 45, "Nat" });
	task2.insert({ 46, "But it's a thankless task... and I'm \nshort of money so..." });
	t2CharStates.insert({ 23, CharacterStates::SMILE });

	task2.insert({ 47, "Nat" });
	task2.insert({ 48, "I bumped this newspaper off some guy \nat the pub.\nFor research." });
	t2CharStates.insert({ 24, CharacterStates::NEUTRAL });

	task2.insert({ 49, "Nat" });
	task2.insert({ 50, "Any chance you could find the guy and \nreturn it to him?" });
	t2CharStates.insert({ 25, CharacterStates::NEUTRAL });

	task2.insert({ 51, "Nat" });
	task2.insert({ 52, "If they find out I'm stealing things from \ntheir customers they'll probably bar me \nand I like that pub." });
	t2CharStates.insert({ 26, CharacterStates::NEUTRAL });

	task2.insert({ 53, "Nat" });
	task2.insert({ 54, "So now that I'm done with it you'd best \nreturn before anyone notices. \nThanks, bye!" });
	t2CharStates.insert({ 27, CharacterStates::SMILE });

	task2.insert({ 55, "You" });
	task2.insert({ 56, "...\nHuh? You're joking me..." });
	t2CharStates.insert({ 28, CharacterStates::BLANK });

	task2.insert({ 57, "You" });
	task2.insert({ 58, "END" });
	t2CharStates.insert({ 29, CharacterStates::SMILE });

	//TASK 4

	task4.insert({ 1, "Nat" });
	task4.insert({ 2, "Oh. You're back. I uhh...\nI had kinda hoped you wouldn't make \nit back before my train." });
	t4CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task4.insert({ 3, "You" });
	task4.insert({ 4, "Seriously? I've been nothing but \nhelpful, I don't get why you couldn't do \nthat yourself but I still did it!" });
	t4CharStates.insert({ 2, CharacterStates::NEUTRAL });

	task4.insert({ 5, "You" });
	task4.insert({ 6, "And now you tell me you were just \ngonna try run away without helping me?" });
	t4CharStates.insert({ 3, CharacterStates::NEUTRAL });

	task4.insert({ 7, "Nat" });
	task4.insert({ 8, "Listen, I'm just paranoid ok? I told you \nI've been getting tailed recently right...?" });
	t4CharStates.insert({ 4, CharacterStates::THINKING });

	task4.insert({ 9, "You" });
	task4.insert({ 10, "(...)" });
	t4CharStates.insert({ 5, CharacterStates::THINKING });

	task4.insert({ 11, "You" });
	task4.insert({ 12, "(I find it hard to believe this guy could \nhave ANY information that would lead to \nhim being followed...)" });
	t4CharStates.insert({ 6, CharacterStates::THINKING });

	task4.insert({ 13, "You" });
	task4.insert({ 14, "(All this just to find out what he thinks \nabout the dam rumours...)" });
	t4CharStates.insert({ 7, CharacterStates::THINKING });

	task4.insert({ 15, "You" });
	task4.insert({ 16, "Ok, sorry. I understand that, but you're \nstill here nonetheless" });
	t4CharStates.insert({ 8, CharacterStates::THINKING });

	task4.insert({ 17, "You" });
	task4.insert({ 18, "So I don't suppose you could help me \nout with my question now?" });
	t4CharStates.insert({ 9, CharacterStates::THINKING });

	task4.insert({ 19, "Nat" });
	task4.insert({ 20, "..." });
	t4CharStates.insert({ 10, CharacterStates::SMILE });

	task4.insert({ 21, "Nat" });
	task4.insert({ 22, "Sure... I suppose it's only fair. But be \nwarned... Once I tell you this they might \nstart coming for you too." });
	t4CharStates.insert({ 11, CharacterStates::NEUTRAL });

	task4.insert({ 23, "You" });
	task4.insert({ 24, "(This guy is a nutcase. I'm wasting \nmy time.)" });
	t4CharStates.insert({ 12, CharacterStates::NEUTRAL });

	task4.insert({ 25, "Nat" });
	task4.insert({ 26, "That newspaper I gave you. Did you \nread it?" });
	t4CharStates.insert({ 13, CharacterStates::SMILE });

	task4.insert({ 27, "You" });
	task4.insert({ 28, "Huh? Oh, no, I didn't bother." });
	t4CharStates.insert({ 14, CharacterStates::SMILE });

	task4.insert({ 29, "Nat" });
	task4.insert({ 30, "Well... there was an important article in \nthere. Which is why I just HAD to get my \nhands on it." });
	t4CharStates.insert({ 15, CharacterStates::SMILE });

	task4.insert({ 31, "Nat" });
	task4.insert({ 32, "You see... we've had a string of \nmysterious disappearances up in those \nhills  recently..." });
	t4CharStates.insert({ 16, CharacterStates::SMILE });

	task4.insert({ 33, "Nat" });
	task4.insert({ 34, "And that paper was reporting on \nanother one! I need all the information I \ncan get right now..." });
	t4CharStates.insert({ 17, CharacterStates::SMILE });

	task4.insert({ 35, "Nat" });
	task4.insert({ 36, "That dam you're talking about... \nI believe it's a major point of \nsignificance in this mystery!" });
	t4CharStates.insert({ 18, CharacterStates::SMILE });

	task4.insert({ 37, "Nat" });
	task4.insert({ 38, "There's something going on in those \nhills... and it's all to do with that dam! \nI know it!" });
	t4CharStates.insert({ 19, CharacterStates::SMILE });

	task4.insert({ 39, "You" });
	task4.insert({ 40, "(Could this guy actually be on to \nsomething? Does Dan know about \nthese disappearances?)" });
	t4CharStates.insert({ 20, CharacterStates::SMILE });

	task4.insert({ 41, "Nat" });
	task4.insert({ 42, "Aliens." });
	t4CharStates.insert({ 21, CharacterStates::ANGRY });

	task4.insert({ 43, "You" });
	task4.insert({ 44, "What?" });
	t4CharStates.insert({ 22, CharacterStates::ANGRY });

	task4.insert({ 45, "Nat" });
	task4.insert({ 46, "Aliens in the hills." });
	t4CharStates.insert({ 23, CharacterStates::ANGRY });

	task4.insert({ 47, "You" });
	task4.insert({ 48, "..." });
	t4CharStates.insert({ 24, CharacterStates::ANGRY });

	task4.insert({ 49, "Nat" });
	task4.insert({ 50, "..." });
	t4CharStates.insert({ 25, CharacterStates::ANGRY });

	task4.insert({ 51, "Nat" });
	task4.insert({ 52, "Like they're coming down and\nabducting people and-" });
	t4CharStates.insert({ 26, CharacterStates::NEUTRAL });

	task4.insert({ 53, "You" });
	task4.insert({ 54, "Yeah, yeah I know, aliens, right. \nHave you seen one or...?" });
	t4CharStates.insert({ 27, CharacterStates::NEUTRAL });

	task4.insert({ 55, "Nat" });
	task4.insert({ 56, "No... but what else could it be! \nThe dam must hold a beacon of some \nsort!" });
	t4CharStates.insert({ 28, CharacterStates::NEUTRAL });

	task4.insert({ 57, "You" });
	task4.insert({ 58, "(...\nI knew I was wasting my time here. \nThis guys just saying words at me)." });
	t4CharStates.insert({ 29, CharacterStates::NEUTRAL });

	task4.insert({ 59, "You" });
	task4.insert({ 60, "Right... Well... Thanks for your... Help... \nI guess..." });
	t4CharStates.insert({ 30, CharacterStates::NEUTRAL });

	task4.insert({ 61, "Nat" });
	task4.insert({ 62, "No problem. Me and you? We're gonna \nsee this through, trust me! We'll show \neveryone!" });
	t4CharStates.insert({ 31, CharacterStates::SMILE });

	task4.insert({ 63, "You" });
	task4.insert({ 64, "Yes well... I'd best be leaving now.." });
	t4CharStates.insert({ 32, CharacterStates::SMILE });

	task4.insert({ 65, "You" });
	task4.insert({ 66, "(...\nThat guy is a nutjob... but...)" });
	t4CharStates.insert({ 33, CharacterStates::BLANK });

	task4.insert({ 67, "You" });
	task4.insert({ 68, "(People are going missing, that can't \nbe ignored.)" });
	t4CharStates.insert({ 34, CharacterStates::BLANK });

	task4.insert({ 69, "You" });
	task4.insert({ 70, "(Is there really something happening up \nthere?)" });
	t4CharStates.insert({ 35, CharacterStates::BLANK });

	task4.insert({ 71, "You" });
	task4.insert({ 72, "(I feel like Dan would've mentioned \nsomething...)" });
	t4CharStates.insert({ 36, CharacterStates::BLANK });

	task4.insert({ 73, "You" });
	task4.insert({ 74, "(Well... Nothing's gone wrong yet... \nI'll head home for the night.)" });
	t4CharStates.insert({ 37, CharacterStates::BLANK });

	task4.insert({ 75, "You" });
	task4.insert({ 76, "END" });
	t4CharStates.insert({ 38, CharacterStates::BLANK });

	dayDialogue3.insert({ 1, task1 });
	dayDialogue3.insert({ 2, task2 });
	dayDialogue3.insert({ 4, task4 });

	charStates3.insert({ 1, t1CharStates });
	charStates3.insert({ 2, t2CharStates });
	charStates3.insert({ 4, t4CharStates });
}

void NatText::initDay4()
{
	//This character has states neutral angry thinking and smile

	std::map<int, std::string> day4;
	std::map<int, CharacterStates> day4CStates;

	//SECOND TASK
	day4.insert({ 1, "Nat" });
	day4.insert({ 2, "You and I are in this together now." });
	day4CStates.insert({ 1, CharacterStates::NEUTRAL });

	day4.insert({ 3, "Nat" });
	day4.insert({ 4, "We're in for the long haul!" });
	day4CStates.insert({ 2, CharacterStates::ANGRY });

	day4.insert({ 5, "Nat" });
	day4.insert({ 6, "END" });
	day4CStates.insert({ 3, CharacterStates::THINKING });

	dayDialogue4.insert({ 1, day4 });

	charStates4.insert({ 1, day4CStates });


}

CharacterStates NatText::returnCharState(PlayerData* pd, int prog)
{
	switch (pd->dayProgress)
	{

	case(1):
	{
		return charStates1.at(1).at(prog);

	};	break;

	case(2):
	{
		if (pd->tasks < 3)
		{
			return charStates2.at(1).at(prog);
		}

		else
		{
			return charStates2.at(pd->tasks-1).at(prog);
		}
	

	};	break;

	case(3):
	{
		return charStates3.at(pd->tasks).at(prog);

	};	break;

	case(4):
	{
		return charStates4.at(1).at(prog);

	};	break;

	case(5):
	{
		return charStates4.at(1).at(prog);

	};	break;

	}
}
