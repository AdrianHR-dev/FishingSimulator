#include "SocksText.h"

SocksText::SocksText()
{
	initText();
}

SocksText::~SocksText()
{

}

void SocksText::initText()
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

	std::map<int, std::string> progress6;
	std::map<int, CharacterStates> p6CharStates;

	std::map<int, std::string> progress7;
	std::map<int, CharacterStates> p7CharStates;

	std::map<int, std::string> progress8;
	std::map<int, CharacterStates> p8CharStates;

	std::map<int, std::string> progress9;
	std::map<int, CharacterStates> p9CharStates;

	task1.insert({ 1, "You" });
	task1.insert({ 2, "(There's a cat here... I wonder what \nhe's up to...)" });
	t1CharStates.insert({ 1, CharacterStates::DISTANCE });

	task1.insert({ 3, "Socks" });
	task1.insert({ 4, "Mrrrp?" });
	t1CharStates.insert({ 2, CharacterStates::THINKING });

	task1.insert({ 5, "Socks" });
	task1.insert({ 6, "..." });
	t1CharStates.insert({ 3, CharacterStates::BLANK });

	task1.insert({ 7, "You" });
	task1.insert({ 8, "(It ran away... What a shame...)" });
	t1CharStates.insert({ 4, CharacterStates::BLANK });

	task1.insert({ 9, "You" });
	task1.insert({ 10, "END" });
	t1CharStates.insert({ 5, CharacterStates::BLANK });

	task2.insert({ 1, "You" });
	task2.insert({ 2, "(...!)" });
	t2CharStates.insert({ 1, CharacterStates::DISTANCE });

	task2.insert({ 3, "You" });
	task2.insert({ 4, "(It's that same cat from earlier... \nMaybe if I'm a little quieter this time...)" });
	t2CharStates.insert({ 2, CharacterStates::DISTANCE });

	task2.insert({ 5, "Socks" });
	task2.insert({ 6, "...!" });
	t2CharStates.insert({ 3, CharacterStates::THINKING });

	task2.insert({ 7, "Socks" });
	task2.insert({ 8, "..." });
	t2CharStates.insert({ 4, CharacterStates::ANGRY });

	task2.insert({ 9, "You" });
	task2.insert({ 10, "...\nI guess he's a little shy..." });
	t2CharStates.insert({ 5, CharacterStates::BLANK });

	task2.insert({ 11, "You" });
	task2.insert({ 12, "END" });
	t2CharStates.insert({ 6, CharacterStates::BLANK });

	task3.insert({ 1, "You" });
	task3.insert({ 2, "(Hey! It's that cat from the other day!)" });
	t3CharStates.insert({ 1, CharacterStates::DISTANCE });

	task3.insert({ 3, "You" });
	task3.insert({ 4, "(I don't want to scare him off again...\nHow can I gain it's trust...)" });
	t3CharStates.insert({ 2, CharacterStates::DISTANCE });

	task3.insert({ 5, "You" });
	task3.insert({ 6, "(Oh! I could give him the fish I caught\nearlier! That should make him want to \nbe friends!)" });
	t3CharStates.insert({ 3, CharacterStates::DISTANCE });

	task3.insert({ 7, "You" });
	task3.insert({ 8, "Psst! Here kitty! Look what I've got!" });
	t3CharStates.insert({ 4, CharacterStates::DISTANCE });

	task3.insert({ 9, "Socks" });
	task3.insert({ 10, "Mrrp?" });
	t3CharStates.insert({ 5, CharacterStates::THINKING });

	task3.insert({ 11, "Socks" });
	task3.insert({ 12, "Mrroow!" });
	t3CharStates.insert({ 6, CharacterStates::SMILE });

	task3.insert({ 13, "You" });
	task3.insert({ 14, "Awwww, you must've been hungry! \nThere you go, it's all yours buddy."});
	t3CharStates.insert({ 7, CharacterStates::SMILE });

	task3.insert({ 15, "Socks" });
	task3.insert({ 16, "Meowww!" });
	t3CharStates.insert({ 8, CharacterStates::SMILE });

	task3.insert({ 17, "You" });
	task3.insert({ 18, "END" });
	t3CharStates.insert({ 9, CharacterStates::SMILE });

	task4.insert({ 1, "Socks" });
	task4.insert({ 2, "Mrroow!" });
	t4CharStates.insert({ 1, CharacterStates::SMILE });

	task4.insert({ 3, "You" });
	task4.insert({ 4, "I think he likes me now!" });
	t4CharStates.insert({ 2, CharacterStates::SMILE });

	task4.insert({ 5, "You" });
	task4.insert({ 6, "END" });
	t4CharStates.insert({ 3, CharacterStates::SMILE });

	progress6.insert({ 1, "Socks" });
	progress6.insert({ 2, "Mrrp!" });
	p6CharStates.insert({ 1, CharacterStates::SMILE });

	progress6.insert({ 3, "You" });
	progress6.insert({ 4, "Oh! Hello again!" });
	p6CharStates.insert({ 2, CharacterStates::SMILE });

	progress6.insert({ 5, "Socks" });
	progress6.insert({ 6, "Meowww!" });
	p6CharStates.insert({ 3, CharacterStates::ANGRY });

	progress6.insert({ 7, "You" });
	progress6.insert({ 8, "Does he want me to follow him?" });
	p6CharStates.insert({ 4, CharacterStates::BLANK });

	progress6.insert({ 9, "You" });
	progress6.insert({ 10, "END" });
	p6CharStates.insert({ 5, CharacterStates::BLANK });

	progress7.insert({ 1, "Socks" });
	progress7.insert({ 2, "Mrroowww!" });
	p7CharStates.insert({ 1, CharacterStates::SMILE });

	progress7.insert({ 3, "Socks" });
	progress7.insert({ 4, "..." });
	p7CharStates.insert({ 2, CharacterStates::ANGRY });

	progress7.insert({ 5, "You" });
	progress7.insert({ 6, "Where is he taking me?" });
	p7CharStates.insert({ 3, CharacterStates::BLANK });

	progress7.insert({ 7, "You" });
	progress7.insert({ 8, "END" });
	p7CharStates.insert({ 4, CharacterStates::BLANK });

	progress8.insert({ 1, "Socks" });
	progress8.insert({ 2, "Mrrp." });
	p8CharStates.insert({ 1, CharacterStates::SMILE });

	progress8.insert({ 3, "You" });
	progress8.insert({ 4, "(He's dug a hole in the dirt by the gate...)" });
	p8CharStates.insert({ 2, CharacterStates::BLANK });

	progress8.insert({ 5, "You" });
	progress8.insert({ 6, "(What's this? There's a box in here...)" });
	p8CharStates.insert({ 3, CharacterStates::THINKING });

	progress8.insert({ 7, "You" });
	progress8.insert({ 8, "(There's an odd locking mechanism on it... \nLet's see if I can figure it out.)" });
	p8CharStates.insert({ 4, CharacterStates::THINKING });

	progress8.insert({ 9, "Socks" });
	progress8.insert({ 10, "Meowww!" });
	p8CharStates.insert({ 5, CharacterStates::SMILE });

	progress8.insert({ 11, "Socks" });
	progress8.insert({ 12, "PUZZLE" });
	p8CharStates.insert({ 6, CharacterStates::THINKING });

	progress8.insert({ 13, "Socks" });
	progress8.insert({ 14, "..." });
	p8CharStates.insert({ 7, CharacterStates::THINKING });

	progress8.insert({ 15, "Socks" });
	progress8.insert({ 16, "mrrow..." });
	p8CharStates.insert({ 8, CharacterStates::ANGRY });

	progress8.insert({ 17, "You" });
	progress8.insert({ 18, "(He seems disappointed in me...)" });
	p8CharStates.insert({ 9, CharacterStates::BLANK });

	progress8.insert({ 19, "Socks" });
	progress8.insert({ 20, "END" });
	p8CharStates.insert({ 10, CharacterStates::SMILE });

	progress9.insert({ 1, "Socks" });
	progress9.insert({ 2, "Mroww!" });
	p9CharStates.insert({ 1, CharacterStates::SMILE });

	progress9.insert({ 3, "Socks" });
	progress9.insert({ 4, "END" });
	p9CharStates.insert({ 2, CharacterStates::SMILE });

	progress9.insert({ 15, "Socks" });
	progress9.insert({ 16, "Mroww!" });
	p9CharStates.insert({ 8, CharacterStates::SMILE });

	progress9.insert({ 17, "You" });
	progress9.insert({ 18, "Alright, let's see what we've got..." });
	p9CharStates.insert({ 9, CharacterStates::SMILE });

	progress9.insert({ 19, "You" });
	progress9.insert({ 20, "It's... a map of Scotland?" });
	p9CharStates.insert({ 10, CharacterStates::ITEM });

	progress9.insert({ 21, "You" });
	progress9.insert({ 22, "A few towns have been marked out with \nred dots..." });
	p9CharStates.insert({ 11, CharacterStates::ITEM });

	progress9.insert({ 23, "You" });
	progress9.insert({ 24, "Hey, wait! Dregden's on here! What is \nthis for?" });
	p9CharStates.insert({ 12, CharacterStates::ITEM });

	progress9.insert({ 25, "Socks" });
	progress9.insert({ 26, "Mrrp!" });
	p9CharStates.insert({ 13, CharacterStates::SMILE });

	progress9.insert({ 27, "You" });
	progress9.insert({ 28, "Hmmm... how interesting..." });
	p9CharStates.insert({ 14, CharacterStates::SMILE });

	progress9.insert({ 29, "You" });
	progress9.insert({ 30, "END" });
	p9CharStates.insert({ 15, CharacterStates::ITEM });


	socksSpeech.insert({ 1, task1 });
	socksSpeech.insert({ 2, task2 });
	socksSpeech.insert({ 3, task3 });
	socksSpeech.insert({ 4, task4  });
	socksSpeech.insert({ 5, progress6 });
	socksSpeech.insert({ 6, progress7 });
	socksSpeech.insert({ 7, progress8 });
	socksSpeech.insert({ 8, progress9 });

	socksStates.insert({ 1, t1CharStates });
	socksStates.insert({ 2, t2CharStates });
	socksStates.insert({ 3, t3CharStates });
	socksStates.insert({ 4, t4CharStates });
	socksStates.insert({ 5, p6CharStates });
	socksStates.insert({ 6, p7CharStates });
	socksStates.insert({ 7, p8CharStates });
	socksStates.insert({ 8, p9CharStates });
}

CharacterStates SocksText::returnCharState(PlayerData* pd, int prog)
{
	if (pd->socksTasks < 3)
	{
		return socksStates.at(pd->socksTasks).at(prog);
	}

	else
	{
		return socksStates.at(pd->socksTasks-1).at(prog);
	}

}
