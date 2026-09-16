#include "NatDialogue.h"

NatDialogue::NatDialogue()
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

NatDialogue::~NatDialogue()
{

}

bool NatDialogue::DialogueUpdate(PlayerData* pd)
{
	progress = progress + 2;

	switch (pd->dayProgress)
	{

	case(1):
	{
		name.setString(natText.dayDialogue1.at(1).at(progress));
		dialogue.setString(natText.dayDialogue1.at(1).at(progress + 1));

	};	break;

	case(2):
	{
		if (pd->tasks < 3)
		{
			name.setString(natText.dayDialogue2.at(1).at(progress));
			dialogue.setString(natText.dayDialogue2.at(1).at(progress + 1));
		}

		else
		{
			name.setString(natText.dayDialogue2.at(pd->tasks-1).at(progress));
			dialogue.setString(natText.dayDialogue2.at(pd->tasks-1).at(progress + 1));
		}

	};	break;

	case(3):
	{
		name.setString(natText.dayDialogue3.at(pd->tasks).at(progress));
		dialogue.setString(natText.dayDialogue3.at(pd->tasks).at(progress + 1));

	};	break;

	case(4):
	{
		name.setString(natText.dayDialogue4.at(1).at(progress));
		dialogue.setString(natText.dayDialogue4.at(1).at(progress + 1));

	};	break;

	case(5):
	{
		name.setString(natText.dayDialogue4.at(1).at(progress));
		dialogue.setString(natText.dayDialogue4.at(1).at(progress + 1));

	};	break;

	}

	//Check for end of conversation
	if (dialogue.getString() == "END")
	{
		progress = -1;

		if (pd->dayProgress == 3)
		{
			if (pd->tasks == 2)
			{
				pd->tasks = pd->tasks + 1;
			}

			else if (pd->tasks == 4)
			{
				pd->tasks = 10;
			}
		}

		return true;
		
	}

	return false;

}

CharacterStates NatDialogue::getCurrState(PlayerData* pd)
{
	if (progress == 1)
	{
		return natText.returnCharState(pd, progress);
	}

	else
	{
		return natText.returnCharState(pd, ((progress - 1) / 2) + 1); //((N-1)/2) + 1 eg. n = 3, input = 2; n = 7, input = 4
	}
}



