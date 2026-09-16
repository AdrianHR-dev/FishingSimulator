#include "SocksDialogue.h"

SocksDialogue::SocksDialogue()
{
	textBox.loadFromFile("gfx/TextBox.png");
	setTexture(&textBox);

	//Text box details set
	setPosition(sf::Vector2f(0.0f, 450.0f));
	setSize(sf::Vector2f(800.0f, 250.0f));

	font.loadFromFile("font/arial.ttf");

	name.setFont(font);
	name.setFillColor(sf::Color::Yellow);
	name.setCharacterSize(48);
	name.setPosition(sf::Vector2f(10.0f, 450.0f));


	dialogue.setFont(font);
	dialogue.setCharacterSize(36);
	dialogue.setPosition(sf::Vector2f(5.0f, 520.0f));

	progress = -1;

	name.setString("");
	dialogue.setString("");
}

SocksDialogue::~SocksDialogue()
{

}

bool SocksDialogue::DialogueUpdate(PlayerData* pd)
{
	progress = progress + 2;

	if (pd->socksTasks < 3)
	{
		name.setString(socksText.socksSpeech.at(pd->socksTasks).at(progress));
		dialogue.setString(socksText.socksSpeech.at(pd->socksTasks).at(progress + 1));
	}

	//TASKS OFFSET BETWEEN DAYS, ACCOUNTING FOR THIS HERE
	else 
	{
		name.setString(socksText.socksSpeech.at(pd->socksTasks-1).at(progress));
		dialogue.setString(socksText.socksSpeech.at(pd->socksTasks-1).at(progress + 1));
	}


	//Check for end of conversation
	if (dialogue.getString() == "END")
	{
		progress = -1;

		if (pd->socksTasks == 1 || pd->socksTasks == 2 || pd->socksTasks == 4 || pd->socksTasks == 6 || pd->socksTasks == 7)
		{
			pd->socksTasks = pd->socksTasks + 1;
		}


		return true;

	}

	else if (dialogue.getString() == "PUZZLE")
	{
		progress = progress + 2;
		
		pd->currPuzzle = PuzzleNames::SLIDE;
		pd->puzzle = true;

		name.setString(socksText.socksSpeech.at(pd->socksTasks - 1).at(progress));
		dialogue.setString(socksText.socksSpeech.at(pd->socksTasks - 1).at(progress + 1));

	}

	return false;

}

CharacterStates SocksDialogue::getCurrState(PlayerData* pd)
{
	if (progress == 1)
	{
		return socksText.returnCharState(pd, progress);
	}

	else
	{
		return socksText.returnCharState(pd, ((progress - 1) / 2) + 1); //((N-1)/2) + 1 eg. n = 3, input = 2; n = 7, input = 4
	}
}




