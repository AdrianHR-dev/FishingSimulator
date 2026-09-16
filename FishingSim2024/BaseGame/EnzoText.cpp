#include "EnzoText.h"

EnzoText::EnzoText()
{
	initText();
}

EnzoText::~EnzoText()
{

}

void EnzoText::initText()
{
	//This character has states neutral angry thinking and smile

	std::map<int, std::string> enzo;
	std::map<int, CharacterStates> enzoCStates;

	//SECOND TASK
	enzo.insert({ 1, "You" });
	enzo.insert({ 2, "(There's a cat here... I wonder if he's \nfriendly...)" });
	enzoCStates.insert({ 1, CharacterStates::DISTANCE });

	enzo.insert({ 3, "Enzo" });
	enzo.insert({ 4, "Meow!" });
	enzoCStates.insert({ 2, CharacterStates::NEUTRAL });

	enzo.insert({ 5, "You" });
	enzo.insert({ 6, "(Wow... he's so friendly... What a cool \nlittle guy...)" });
	enzoCStates.insert({ 3, CharacterStates::NEUTRAL });

	enzo.insert({ 7, "Enzo" });
	enzo.insert({ 8, "END" });
	enzoCStates.insert({ 4, CharacterStates::NEUTRAL });

	enzoSpeech.insert({ 1, enzo });

	enzoStates.insert({ 1, enzoCStates });


}

CharacterStates EnzoText::returnCharState(PlayerData* pd, int prog)
{

	return enzoStates.at(1).at(prog);

}
