#include "DrunkardDialogue.h"

DrunkardDialogue::DrunkardDialogue()
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

DrunkardDialogue::~DrunkardDialogue()
{

}

bool DrunkardDialogue::DialogueUpdate(PlayerData* pd)
{
	progress = progress + 2;

	switch (pd->dayProgress)
	{

	case(1):
	{
		name.setString(drunkardText.dayDialogue1.at(pd->tasks).at(progress));
		dialogue.setString(drunkardText.dayDialogue1.at(pd->tasks).at(progress + 1));

	};	break;

	case(3):
	{
		name.setString(drunkardText.dayDialogue3.at(pd->tasks).at(progress));
		dialogue.setString(drunkardText.dayDialogue3.at(pd->tasks).at(progress + 1));

	};	break;

	case(5):
	{
		name.setString(drunkardText.dayDialogue5.at(1).at(progress));
		dialogue.setString(drunkardText.dayDialogue5.at(1).at(progress + 1));

	};	break;

	}

	//Check for end of conversation
	if (dialogue.getString() == "END")
	{
		progress = -1;

		switch(pd->dayProgress)
		{
		case(1):
		{
			//increment player task count
			switch (pd->tasks)
			{

			case(2):
			{
				pd->tasks = pd->tasks + 1;
			};	break;


			case(4):
			{
				pd->tasks = pd->tasks + 1;
			};	break;

			case(6):
			{
				pd->tasks = 10;
			};	break;

			}

		};	break;

		case(3):
		{
			//increment player task count
			if (pd->tasks == 3)
			{
				pd->tasks = pd->tasks + 1;
			}

		};	break;

		}

		return true;
	}

	return false;

}

CharacterStates DrunkardDialogue::getCurrState(PlayerData* pd)
{
	if (progress == 1)
	{
		return drunkardText.returnCharState(pd, progress);
	}

	else
	{
		return drunkardText.returnCharState(pd, ((progress - 1) / 2) + 1); //((N-1)/2) + 1 eg. n = 3, input = 2; n = 7, input = 4
	}
}



