#include "FishermanDialogue.h"

FishermanDialogue::FishermanDialogue()
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

FishermanDialogue::~FishermanDialogue()
{

}

CharacterStates FishermanDialogue::getCurrState(PlayerData* pd)
{
	if (progress == 1)
	{
		return fishermanText.returnCharState(pd, progress);
	}

	else
	{
		return fishermanText.returnCharState(pd, ((progress - 1) / 2) + 1); //((N-1)/2) + 1 eg. n = 3, input = 2; n = 7, input = 4
	}
}

bool FishermanDialogue::DialogueUpdate(PlayerData* pd)
{
	progress = progress + 2;

	switch (pd->dayProgress)
	{

	case(2):
	{
		name.setString(fishermanText.dayDialogue1.at(pd->tasks-1).at(progress));
		dialogue.setString(fishermanText.dayDialogue1.at(pd->tasks-1).at(progress + 1));

	};	break;

	case(3):
	{
		name.setString(fishermanText.dayDialogue2.at(1).at(progress));
		dialogue.setString(fishermanText.dayDialogue2.at(1).at(progress + 1));

	};	break;

	}

	//Check for end of conversation
	if (dialogue.getString() == "END")
	{
		progress = -1;

		//increment player task count
		switch (pd->dayProgress)
		{

		case(2):
		{
			if (pd->tasks == 2)
			{
				pd->tasks = pd->tasks + 1;
			}

			if (pd->tasks == 4)
			{
				pd->tasks = 10;
			}

		};	break;

		}
		return true;
	}

	return false;


}
