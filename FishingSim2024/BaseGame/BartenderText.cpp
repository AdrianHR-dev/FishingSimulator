#include "BartenderText.h"

BartenderText::BartenderText()
{
	initDay1();
	initDay2();
	initDay3();
	initDay4();
	initDay5();
}

BartenderText::~BartenderText()
{

}

CharacterStates BartenderText::returnCharState(PlayerData* pd, int prog)
{
	switch (pd->dayProgress)
	{

	case(1):
	{
		return charStates1.at(pd->tasks).at(prog);

	};	break;

	case(2):
	{
		return charStates2.at(pd->tasks).at(prog);

	};	break;

	case(3):
	{
		return charStates3.at(pd->tasks).at(prog);

	};	break;

	case(4):
	{
		return charStates4.at(pd->tasks).at(prog);

	};	break;

	case(5):
	{
		if (pd->drink < 3)
		{
			return charStates5.at(1).at(prog);
		}

		else if (pd->drink < 5)
		{
			return charStates5.at(2).at(prog);
		}

		else
		{
			return charStates5.at(3).at(prog);
		}


	};	break;

	}
}

void BartenderText::initDay1()
{
	//This character has states neutral, angry, smile and thinking
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

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

	task1.insert({ 1, "Bartender" });
	task1.insert({ 2, "What can I get for you, mate?" });
	t1CharStates.insert({ 1, CharacterStates::THINKING });

	task1.insert({ 3, "Bartender" });
	task1.insert({ 4, "Pint of Dreggents? Sure." });
	t1CharStates.insert({ 2, CharacterStates::THINKING });

	task1.insert({ 5, "Bartender" });
	task1.insert({ 6, "So, been up to much today?" });
	t1CharStates.insert({ 3, CharacterStates::NEUTRAL });

	task1.insert({ 7, "Bartender" });
	task1.insert({ 8, "Fishing? Seems like everyone's fishing \nnowadays. Though I don't often hear of \nsomeone fishing up by the dam." });
	t1CharStates.insert({ 4, CharacterStates::SMILE });

	task1.insert({ 9, "Bartender" });
	task1.insert({ 10, "Anyway, here's your pint mate. Enjoy." });
	t1CharStates.insert({ 5, CharacterStates::THINKING });

	task1.insert({ 11, "Bartender" });
	task1.insert({ 12, "Oh, actually... Can you do me a favour?" });
	t1CharStates.insert({ 6, CharacterStates::THINKING });

	task1.insert({ 13, "Bartender" });
	task1.insert({ 14, "Whenever you leave, could you just check \nup on the guy outside?" });
	t1CharStates.insert({ 7, CharacterStates::THINKING });

	task1.insert({ 15, "Bartender" });
	task1.insert({ 16, "I had to throw him out for being off his nut \nearlier, and I don't really care what state \nhe's in..." });
	t1CharStates.insert({ 8, CharacterStates::SMILE });

	task1.insert({ 17, "Bartender" });
	task1.insert({ 18, "...but if he needs an ambulance I should \nprobably call one. Don't rush yourself \nthough, It's really not your issue... " });
	t1CharStates.insert({ 9, CharacterStates::NEUTRAL });

	task1.insert({ 19, "Bartender" });
	task1.insert({ 20, "Or mine." });
	t1CharStates.insert({ 10, CharacterStates::ANGRY });

	task1.insert({ 21, "Bartender" });
	task1.insert({ 22, "END" });
	t1CharStates.insert({ 11, CharacterStates::NEUTRAL });

	//TASK 2 
	task2.insert({ 1, "Bartender" });
	task2.insert({ 2, "I swear, I have to kick that guy out atleast \nonce a week." });
	t2CharStates.insert({ 1, CharacterStates::ANGRY });

	task2.insert({ 3, "Bartender" });
	task2.insert({ 4, "END" });
	t2CharStates.insert({ 2, CharacterStates::NEUTRAL });

	//TASK 3

	task3.insert({ 1, "Bartender" });
	task3.insert({ 2, "A glass of water? Listen, as long as the \nguy is alive, I'm not getting involved..." });
	t3CharStates.insert({ 1, CharacterStates::SMILE });

	task3.insert({ 3, "Bartender" });
	task3.insert({ 4, "My boss is VERY strict about keeping all \nthe glasses INSIDE the building." });
	t3CharStates.insert({ 2, CharacterStates::ANGRY });

	task3.insert({ 5, "Bartender" });
	task3.insert({ 6, "Go get some yourself." });
	t3CharStates.insert({ 3, CharacterStates::ANGRY });

	task3.insert({ 7, "Bartender" });
	task3.insert({ 8, "END" });
	t3CharStates.insert({ 4, CharacterStates::NEUTRAL });

	//TASK 4

	task4.insert({ 1, "Bartender" });
	task4.insert({ 2, "He still out there? I don't know why \nyou're so insistent on hanging out with \nhim." });
	t4CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task4.insert({ 3, "Bartender" });
	task4.insert({ 4, "END" });
	t4CharStates.insert({ 2, CharacterStates::NEUTRAL });

	//TASK 5

	task5.insert({ 1, "Bartender" });
	task5.insert({ 2, "Oh, you're back. Just in time for last \norders! Can i get you anything?" });
	t5CharStates.insert({ 1, CharacterStates::THINKING });

	task5.insert({ 3, "You" });
	task5.insert({ 4, "(I need to trick that guy outside into \ndrinking water... Hmmm... I have an \nidea.)" });
	t5CharStates.insert({ 2, CharacterStates::THINKING });


	task5.insert({ 5, "You" });
	task5.insert({ 6, "Uhh, yeah... Can I get one of your \ncocktail pitchers? Maybe the... Muddy \nSwamp Water?" });
	t5CharStates.insert({ 3, CharacterStates::THINKING });

	task5.insert({ 7, "Bartender" });
	task5.insert({ 8, "..." });
	t5CharStates.insert({ 4, CharacterStates::ANGRY });

	task5.insert({ 9, "Bartender" });
	task5.insert({ 10, "Are you fucking serious ? I'm about \nto close and you order  an entire \npitcher?" });
	t5CharStates.insert({ 5, CharacterStates::ANGRY });

	task5.insert({ 11, "You" });
	task5.insert({ 12, "Uhhh..." });
	t5CharStates.insert({ 6, CharacterStates::ANGRY });

	task5.insert({ 13, "Bartender" });
	task5.insert({ 14, "Whatever. Give me a few minutes." });
	t5CharStates.insert({ 7, CharacterStates::ANGRY });

	task5.insert({ 15, "You" });
	task5.insert({ 16, "..." });
	t5CharStates.insert({ 8, CharacterStates::BLANK });

	task5.insert({ 17, "Bartender" });
	task5.insert({ 18, "(You know, I'm probably putting in too \nmuch for effort for some random drunk \nguy I just met.)" });
	t5CharStates.insert({ 9, CharacterStates::BLANK });

	task5.insert({ 19, "You" });
	task5.insert({ 20, "..." });
	t5CharStates.insert({ 10, CharacterStates::BLANK });

	task5.insert({ 21, "Bartender" });
	task5.insert({ 22, "Alright, there you go." });
	t5CharStates.insert({ 11, CharacterStates::THINKING });

	task5.insert({ 23, "Bartender" });
	task5.insert({ 24, "Just bear in mind you'll have to \ndrink it quick, I'm trying to close up \nhere." });
	t5CharStates.insert({ 12, CharacterStates::NEUTRAL });

	task5.insert({ 25, "You" });
	task5.insert({ 26, "..." });
	t5CharStates.insert({ 13, CharacterStates::BLANK });

	task5.insert({ 27, "You" });
	task5.insert({ 28, "I don't want this. I'll just sneak to the \nbathroom when he isn't looking, and fill \nthe pitcher with water..." });
	t5CharStates.insert({ 14, CharacterStates::BLANK });

	task5.insert({ 29, "You" });
	task5.insert({ 30, "..." });
	t5CharStates.insert({ 15, CharacterStates::BLANK });

	task5.insert({ 31, "Bartender" });
	task5.insert({ 32, "..." });
	t5CharStates.insert({ 16, CharacterStates::DISTANCE });

	task5.insert({ 33, "You" });
	task5.insert({ 34, "(He won't notice one little missing \npitcher... I hope...)" });
	t5CharStates.insert({ 17, CharacterStates::DISTANCE });

	task5.insert({ 35, "You" });
	task5.insert({ 36, "END" });
	t5CharStates.insert({ 18, CharacterStates::DISTANCE });

	//TASK 6
	task6.insert({ 1, "Bartender" });
	task6.insert({ 2, "..." });
	t6CharStates.insert({ 1, CharacterStates::DISTANCE });

	task6.insert({ 3, "You" });
	task6.insert({ 4, "I shouldn't distract him..." });
	t6CharStates.insert({ 2, CharacterStates::DISTANCE });

	task6.insert({ 5, "You" });
	task6.insert({ 6, "I don't want him to see me sneaking out \nthis pitcher..." });
	t6CharStates.insert({ 3, CharacterStates::DISTANCE });

	task6.insert({ 7, "You" });
	task6.insert({ 8, "END" });
	t6CharStates.insert({ 4, CharacterStates::DISTANCE });

	dayDialogue1.insert({ 1, task1 });
	dayDialogue1.insert({ 2, task2 });
	dayDialogue1.insert({ 3, task3 });
	dayDialogue1.insert({ 4, task4 });
	dayDialogue1.insert({ 5, task5 });
	dayDialogue1.insert({ 6, task6 });

	charStates1.insert({ 1, t1CharStates });
	charStates1.insert({ 2, t2CharStates });
	charStates1.insert({ 3, t3CharStates });
	charStates1.insert({ 4, t4CharStates });
	charStates1.insert({ 5, t5CharStates });
	charStates1.insert({ 6, t6CharStates });
}

void BartenderText::initDay2()
{
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task3;
	std::map<int, CharacterStates> t3CharStates;

	std::map<int, std::string> task4;
	std::map<int, CharacterStates> t4CharStates;

	task1.insert({ 1, "Bartender" });
	task1.insert({ 2, "..." });
	t1CharStates.insert({ 1, CharacterStates::ANGRY });

	task1.insert({ 3, "Bartender" });
	task1.insert({ 4, "You have some pair of balls to show \nyour face in front of me again after \nthat stunt the other night." });
	t1CharStates.insert({ 2, CharacterStates::ANGRY });

	task1.insert({ 5, "You" });
	task1.insert({ 6, "Haha... ha... Um... Well... Here's \nyour pitcher back! So... uh... \nWe're good right?" });
	t1CharStates.insert({ 3, CharacterStates::ANGRY });

	task1.insert({ 7, "Bartender" });
	task1.insert({ 8, "...\nThanks." });
	t1CharStates.insert({ 4, CharacterStates::ANGRY });

	task1.insert({ 9, "Bartender" });
	task1.insert({10, "..." });
	t1CharStates.insert({ 5, CharacterStates::DISTANCE });

	task1.insert({ 11, "Bartender" });
	task1.insert({ 12, "Pint of Dreggents again, then?" });
	t1CharStates.insert({ 6, CharacterStates::THINKING });

	task1.insert({ 13, "You" });
	task1.insert({ 14, "Ah, yes please!" });
	t1CharStates.insert({ 7, CharacterStates::THINKING });

	task1.insert({ 15, "Bartender" });
	task1.insert({ 16, "Right... \nSo, you been fishing up the hills again \ntoday?" });
	t1CharStates.insert({ 8, CharacterStates::THINKING });

	task1.insert({ 17, "Bartender" });
	task1.insert({ 18, "You know, I got a friend who's really \ninto fishing too. Although he swears off \ngoing near that dam." });
	t1CharStates.insert({ 9, CharacterStates::NEUTRAL });

	task1.insert({ 19, "Bartender" });
	task1.insert({ 20, "He's never told me why..." });
	t1CharStates.insert({ 10, CharacterStates::THINKING });

	task1.insert({ 21, "You" });
	task1.insert({ 22, "Really? I wonder why he'd think that?" });
	t1CharStates.insert({ 11, CharacterStates::THINKING });

	task1.insert({ 23, "Bartender" });
	task1.insert({ 24, "Yeah, well, you could probably ask him. \nI know he's fishing down the front today, \nhe's probably just packing up now." });
	t1CharStates.insert({ 12, CharacterStates::THINKING });

	task1.insert({ 25, "You" });
	task1.insert({ 26, "Interesting... Yeah, I might see if I can \nchat with him.." });
	t1CharStates.insert({ 13, CharacterStates::THINKING });

	task1.insert({ 27, "Bartender" });
	task1.insert({ 28, "Keeps you from causing me any more \ntrouble..." });
	t1CharStates.insert({ 14, CharacterStates::ANGRY });

	task1.insert({ 29, "You" });
	task1.insert({ 30, "What?" });
	t1CharStates.insert({ 15, CharacterStates::ANGRY });

	task1.insert({ 31, "Bartender" });
	task1.insert({ 32, "Oh, nothing." });
	t1CharStates.insert({ 16, CharacterStates::SMILE });

	task1.insert({ 33, "Bartender" });
	task1.insert({ 34, "But you better make sure I see \nan empty glass put on the bar before \nyou leave." });
	t1CharStates.insert({ 17, CharacterStates::ANGRY });

	task1.insert({ 35, "Bartender" });
	task1.insert({ 36, "Or else." });
	t1CharStates.insert({ 18, CharacterStates::ANGRY });

	task1.insert({ 37, "You" });
	task1.insert({ 38, "*gulp*\nOf course... Sorry..." });
	t1CharStates.insert({ 19, CharacterStates::ANGRY });

	task1.insert({ 39, "You" });
	task1.insert({ 40, "END" });
	t1CharStates.insert({ 20, CharacterStates::NEUTRAL });

	//TASK 2

	task2.insert({ 1, "Bartender" });
	task2.insert({ 2, "I've got my eye on you." });
	t2CharStates.insert({ 1, CharacterStates::ANGRY });

	task2.insert({ 3, "You" });
	task2.insert({ 4, "(I didn't think it would be *THAT* big \nof a deal. Whoops...)" });
	t2CharStates.insert({ 2, CharacterStates::ANGRY });

	task2.insert({ 5, "You" });
	task2.insert({ 6, "END" });
	t2CharStates.insert({ 3, CharacterStates::ANGRY });

	//TASK 3

	task3.insert({ 1, "Bartender" });
	task3.insert({ 2, "So, did you find him?" });
	t3CharStates.insert({ 1, CharacterStates::THINKING });

	task3.insert({ 3, "You" });
	task3.insert({ 4, "Yeah, but he's lost his keys so I \nthought I'd help him out." });
	t3CharStates.insert({ 2, CharacterStates::THINKING });

	task3.insert({ 5, "Bartender" });
	task3.insert({ 6, "Oh, he's always losing something or \nother. This has happened like 5 times \nalready." });
	t3CharStates.insert({ 3, CharacterStates::SMILE });

	task3.insert({ 7, "Bartender" });
	task3.insert({ 8, "Well, good luck with your little hunt." });
	t3CharStates.insert({ 4, CharacterStates::NEUTRAL });

	task3.insert({ 9, "Bartender" });
	task3.insert({ 10, "END" });
	t3CharStates.insert({ 5, CharacterStates::THINKING });

	task4.insert({ 1, "Bartender" });
	task4.insert({ 2, "Oh, you got his keys?" });
	t4CharStates.insert({ 1, CharacterStates:: THINKING });

	task4.insert({ 3, "Bartender" });
	task4.insert({ 4, "Good for you, I'm sure he'll \nappreciate it." });
	t4CharStates.insert({ 2, CharacterStates::THINKING });

	task4.insert({ 5, "Bartender" });
	task4.insert({ 6, "END" });
	t4CharStates.insert({ 3, CharacterStates::NEUTRAL });


	dayDialogue2.insert({ 1, task1 });
	dayDialogue2.insert({ 2, task2 });
	dayDialogue2.insert({ 3, task3 });
	dayDialogue2.insert({ 4, task4 });

	charStates2.insert({ 1, t1CharStates });
	charStates2.insert({ 2, t2CharStates });
	charStates2.insert({ 3, t3CharStates });
	charStates2.insert({ 4, t4CharStates });
}

void BartenderText::initDay3()
{
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task3;
	std::map<int, CharacterStates> t3CharStates;

	std::map<int, std::string> task4;
	std::map<int, CharacterStates> t4CharStates;

	//TASK 1

	task1.insert({ 1, "Bartender" });
	task1.insert({ 2, "Oh, you again. How'd your chat go \nyesterday?" });
	t1CharStates.insert({ 1, CharacterStates::THINKING });

	task1.insert({ 3, "You" });
	task1.insert({ 4, "I didn't get much out of it to be honest. \nHe mentioned 'rumours' and then ran \noff for his train!" });
	t1CharStates.insert({ 2, CharacterStates::THINKING });

	task1.insert({ 5, "Bartender" });
	task1.insert({ 6, "Guess he must've been in a rush." });
	t1CharStates.insert({ 3, CharacterStates::THINKING });

	task1.insert({ 7, "Bartender" });
	task1.insert({ 8, "Can I get you a Dreggents again \nthen?" });
	t1CharStates.insert({ 4, CharacterStates::NEUTRAL });

	task1.insert({ 9, "You" });
	task1.insert({ 10, "Yes, please." });
	t1CharStates.insert({ 5, CharacterStates::NEUTRAL });

	task1.insert({ 11, "Bartender" });
	task1.insert({ 12, "Coming right up!" });
	t1CharStates.insert({ 6, CharacterStates::THINKING });

	task1.insert({ 13, "Bartender" });
	task1.insert({ 14, "So, rumours huh? Nothing specific?" });
	t1CharStates.insert({ 7, CharacterStates::THINKING });

	task1.insert({ 15, "You" });
	task1.insert({ 16, "No, nothing really. I don't suppose \nyou've heard anything about them?" });
	t1CharStates.insert({ 8, CharacterStates::SMILE });

	task1.insert({ 17, "Bartender" });
	task1.insert({ 18, "Me? Nah, I couldn't care less about \nfishing, so I haven't heard any of their \nwild tales." });
	t1CharStates.insert({ 9, CharacterStates::SMILE });

	task1.insert({ 19, "Bartender" });
	task1.insert({ 20, "Of course, I'm aware that a decent \nnumber of people have gotten lost \nup in those hills..." });
	t1CharStates.insert({ 10, CharacterStates::THINKING });

	task1.insert({ 21, "Bartender" });
	task1.insert({ 22, "But I don't know that they're necessarily \nrelated to the dam." });
	t1CharStates.insert({ 11, CharacterStates::THINKING });

	task1.insert({ 23, "Bartender" });
	task1.insert({ 24, "I suspect that's probably where the \nrumours come from though." });
	t1CharStates.insert({ 12, CharacterStates::NEUTRAL });

	task1.insert({ 25, "You" });
	task1.insert({ 26, "Interesting... I didn't know about that." });
	t1CharStates.insert({ 13, CharacterStates::NEUTRAL });

	task1.insert({ 27, "Bartender" });
	task1.insert({ 28, "If my friend wasn't of any help to you then \nthere's someone else who might be \nable to help you." });
	t1CharStates.insert({ 14, CharacterStates::THINKING });

	task1.insert({ 29, "Bartender" });
	task1.insert({ 30, "You just missed him actually, there's this \nconspiracy nut who always comes in, \ntalking about whatever new tale he has." });
	t1CharStates.insert({ 15, CharacterStates::THINKING });

	task1.insert({ 31, "Bartender" });
	task1.insert({ 32, "I never really pay attention to what he's \nsaying, but he might've mentioned the \ndam once or twice." });
	t1CharStates.insert({ 16, CharacterStates::THINKING });

	task1.insert({ 33, "Bartender" });
	task1.insert({ 34, "I think he was in a red jacket today, \nif you're quick you might catch up to \nhim." });
	t1CharStates.insert({ 17, CharacterStates::NEUTRAL });

	task1.insert({ 35, "You" });
	task1.insert({ 36, "Sure, I might go see if I can find him \nanywhere when I leave." });
	t1CharStates.insert({ 18, CharacterStates::NEUTRAL });

	task1.insert({ 37, "Bartender" });
	task1.insert({ 38, "END" });
	t1CharStates.insert({ 19, CharacterStates::THINKING });

	//TASK 2

	task2.insert({ 1, "Bartender" });
	task2.insert({ 2, "I'm pretty sure he had a red jacket on." });
	t2CharStates.insert({ 1, CharacterStates::THINKING });

	task2.insert({ 3, "Bartender" });
	task2.insert({ 4, "END" });
	t2CharStates.insert({ 2, CharacterStates::THINKING });

	//TASK 3

	task3.insert({ 1, "Bartender" });
	task3.insert({ 2, "What's that? You think someone here \nleft a newspaper behind?" });
	t3CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task3.insert({ 3, "Bartender" });
	task3.insert({ 4, "I think one of our regulars were reading \none..." });
	t3CharStates.insert({ 2, CharacterStates::THINKING });

	task3.insert({ 5, "Bartender" });
	task3.insert({ 6, "Before I had to kick him out." });
	t3CharStates.insert({ 3, CharacterStates::ANGRY });

	task3.insert({ 7, "Bartender" });
	task3.insert({ 8, "AGAIN." });
	t3CharStates.insert({ 4, CharacterStates::ANGRY });

	task3.insert({ 9, "Bartender" });
	task3.insert({ 10, "END" });
	t3CharStates.insert({ 5, CharacterStates::THINKING });

	//Task 4

	task4.insert({ 1, "Bartender" });
	task4.insert({ 2, "Sorry mate, you've missed last orders." });
	t4CharStates.insert({ 1, CharacterStates::NEUTRAL });

	task4.insert({ 3, "Bartender" });
	task4.insert({ 4, "You're gonna have to leave, I'm \nclosing up here." });
	t4CharStates.insert({ 2, CharacterStates::NEUTRAL });

	task4.insert({ 5, "Bartender" });
	task4.insert({ 6, "END" });
	t4CharStates.insert({ 3, CharacterStates::NEUTRAL });

	dayDialogue3.insert({ 1, task1 });
	dayDialogue3.insert({ 2, task2 });
	dayDialogue3.insert({ 3, task3 });
	dayDialogue3.insert({ 4, task4 });

	charStates3.insert({ 1, t1CharStates });
	charStates3.insert({ 2, t2CharStates });
	charStates3.insert({ 3, t3CharStates });
	charStates3.insert({ 4, t4CharStates });
}

void BartenderText::initDay4()
{
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task3;
	std::map<int, CharacterStates> t3CharStates;

	task1.insert({ 1, "Bartender" });
	task1.insert({ 2, "Welcome back. Dreggents?" });
	t1CharStates.insert({ 1, CharacterStates::THINKING });

	task1.insert({ 3, "You" });
	task1.insert({ 4, "Yes please." });
	t1CharStates.insert({ 2, CharacterStates::THINKING });

	task1.insert({ 5, "Bartender" });
	task1.insert({ 6, "Sure." });
	t1CharStates.insert({ 3, CharacterStates::THINKING });

	task1.insert({ 7, "Bartender" });
	task1.insert({ 8, "Did you find that guy I told you about \nyesterday?" });
	t1CharStates.insert({ 4, CharacterStates::NEUTRAL });

	task1.insert({ 9, "You" });
	task1.insert({ 10, "Oh, yeah... He thinks there are aliens \nin the hill." });
	t1CharStates.insert({ 5, CharacterStates::THINKING });

	task1.insert({ 11, "Bartender" });
	task1.insert({ 12, "Well, there you go! Mystery solved." });
	t1CharStates.insert({ 6, CharacterStates::SMILE });

	task1.insert({ 13, "You" });
	task1.insert({ 14, "Yeah... I'm not so sure I agree with him... \nbut something seems to happening up \nthere." });
	t1CharStates.insert({ 7, CharacterStates::SMILE });

	task1.insert({ 15, "Bartender" });
	task1.insert({ 16, "Well, I don't know where else to point you \nI'm afraid. I can't just send you towards \neveryone in town." });
	t1CharStates.insert({ 8, CharacterStates::THINKING });

	task1.insert({ 17, "Bartender" });
	task1.insert({ 18, "But if you're so concerned, why not just \nstop fishing up there?" });
	t1CharStates.insert({ 9, CharacterStates::NEUTRAL });

	task1.insert({ 19, "You" });
	task1.insert({ 20, "..." });
	t1CharStates.insert({ 10, CharacterStates::NEUTRAL });

	task1.insert({ 21, "Bartender" });
	task1.insert({ 22, "Here's your pint, mate." });
	t1CharStates.insert({ 11, CharacterStates::THINKING });

	task1.insert({ 23, "You" });
	task1.insert({ 24, "Thanks." });
	t1CharStates.insert({ 12, CharacterStates::THINKING });

	task1.insert({ 25, "You" });
	task1.insert({ 26, "(...)" });
	t1CharStates.insert({ 13, CharacterStates::BLANK });

	task1.insert({ 27, "You" });
	task1.insert({ 28, "(I'm not going to stop going, I don't want to \ndisappoint Dan...)" });
	t1CharStates.insert({ 14, CharacterStates::BLANK });

	task1.insert({ 29, "You" });
	task1.insert({ 30, "(Maybe there really isn't anything deeper to \nlook into here. Maybe I should just drop \nit.)" });
	t1CharStates.insert({ 15, CharacterStates::BLANK });

	task1.insert({ 31, "???" });
	task1.insert({ 32, "Psst. Over here." });
	t1CharStates.insert({ 16, CharacterStates::BLANK });

	task1.insert({ 33, "You"});
	task1.insert({ 34, "(Huh? Who said that?)" });
	t1CharStates.insert({ 17, CharacterStates::BLANK });

	task1.insert({ 35, "You" });
	task1.insert({ 36, "END" });
	t1CharStates.insert({ 18, CharacterStates::BLANK });

	//TASK 2

	task2.insert({ 1, "Bartender" });
	task2.insert({ 2, "Why don't you find somewhere else to go \nfishing?" });
	t2CharStates.insert({ 1, CharacterStates::THINKING });

	task2.insert({ 3, "Bartender" });
	task2.insert({ 4, "END" });
	t2CharStates.insert({ 2, CharacterStates::THINKING });

	task3.insert({ 1, "Bartender" });
	task3.insert({ 2, "Nice of you to help that guy with his \npuzzle." });
	t3CharStates.insert({ 1, CharacterStates::THINKING });

	task3.insert({ 3, "Bartender" });
	task3.insert({ 4, "Good to see you've been able to take \nyour mind off all that fishing talk." });
	t3CharStates.insert({ 2, CharacterStates::THINKING });

	task3.insert({ 5, "Bartender" });
	task3.insert({ 6, "END" });
	t3CharStates.insert({ 3, CharacterStates::THINKING });

	dayDialogue4.insert({ 1, task1 });
	dayDialogue4.insert({ 2, task2});
	dayDialogue4.insert({ 3, task3});

	charStates4.insert({ 1, t1CharStates });
	charStates4.insert({ 2, t2CharStates });
	charStates4.insert({ 3, t3CharStates });
}

void BartenderText::initDay5()
{
	//This character has states neutral, angry, smile and thinking
	std::map<int, std::string> task1;
	std::map<int, CharacterStates> t1CharStates;

	std::map<int, std::string> task2;
	std::map<int, CharacterStates> t2CharStates;

	std::map<int, std::string> task3;
	std::map<int, CharacterStates> t3CharStates;

	task1.insert({ 1, "Bartender" });
	task1.insert({ 2, "Another Dreggents then?" });
	t1CharStates.insert({ 1, CharacterStates::SMILE });

	task1.insert({ 3, "Bartender" });
	task1.insert({ 4, "Here you go!" });
	t1CharStates.insert({ 2, CharacterStates::SMILE });

	task1.insert({ 5, "Bartender" });
	task1.insert({ 6, "END" });
	t1CharStates.insert({ 3, CharacterStates::THINKING });

	task2.insert({ 1, "Bartender" });
	task2.insert({ 2, "You want another?" });
	t2CharStates.insert({ 1, CharacterStates::THINKING });

	task2.insert({ 3, "Bartender" });
	task2.insert({ 4, "Sure, here you go." });
	t2CharStates.insert({ 2, CharacterStates::THINKING });

	task2.insert({ 5, "Bartender" });
	task2.insert({ 6, "Maybe just take it easy though, yeah?" });
	t2CharStates.insert({ 3, CharacterStates::ANGRY });

	task2.insert({ 7, "Bartender" });
	task2.insert({ 8, "END" });
	t2CharStates.insert({ 4, CharacterStates::ANGRY });

	task3.insert({ 1, "You" });
	task3.insert({ 2, "unghhh...." });
	t3CharStates.insert({ 1, CharacterStates::NEUTRAL});

	task3.insert({ 3, "You" });
	task3.insert({ 4, "and nother beeerrrr" });
	t3CharStates.insert({ 2, CharacterStates::NEUTRAL });

	task3.insert({ 5, "Bartender" });
	task3.insert({ 6, "..." });
	t3CharStates.insert({ 3, CharacterStates::ANGRY });

	task3.insert({ 7, "Bartender" });
	task3.insert({ 8, "No." });
	t3CharStates.insert({ 4, CharacterStates::ANGRY });

	task3.insert({ 9, "Bartender" });
	task3.insert({ 10, "END" });
	t3CharStates.insert({ 5, CharacterStates::ANGRY });

	dayDialogue5.insert({ 1, task1 });
	dayDialogue5.insert({ 2, task2 });
	dayDialogue5.insert({ 3, task3 });

	charStates5.insert({ 1, t1CharStates });
	charStates5.insert({ 2, t2CharStates });
	charStates5.insert({ 3, t3CharStates });
}