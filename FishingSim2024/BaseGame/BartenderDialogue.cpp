#include "BartenderDialogue.h"

BartenderDialogue::BartenderDialogue()
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

BartenderDialogue::~BartenderDialogue()
{

}

CharacterStates BartenderDialogue::getCurrState(PlayerData* pd)
{
	if (progress == 1)
	{
		return bartenderText.returnCharState(pd, progress);
	}

	else
	{
		return bartenderText.returnCharState(pd, ((progress - 1) / 2) + 1); //((N-1)/2) + 1 eg. n = 3, input = 2; n = 7, input = 4
	}
}

bool BartenderDialogue::DialogueUpdate(PlayerData* pd)
{
	progress = progress + 2;

	switch (pd->dayProgress)
	{

	case(1):
	{
		name.setString(bartenderText.dayDialogue1.at(pd->tasks).at(progress));
		dialogue.setString(bartenderText.dayDialogue1.at(pd->tasks).at(progress + 1));

	};	break;

	case(2):
	{
		name.setString(bartenderText.dayDialogue2.at(pd->tasks).at(progress));
		dialogue.setString(bartenderText.dayDialogue2.at(pd->tasks).at(progress + 1));

	};	break;

	case(3):
	{
		name.setString(bartenderText.dayDialogue3.at(pd->tasks).at(progress));
		dialogue.setString(bartenderText.dayDialogue3.at(pd->tasks).at(progress + 1));

	};	break;

	case(4):
	{
		name.setString(bartenderText.dayDialogue4.at(pd->tasks).at(progress));
		dialogue.setString(bartenderText.dayDialogue4.at(pd->tasks).at(progress + 1));

	};	break;

	case(5):
	{
		if (pd->drink < 3)
		{
			name.setString(bartenderText.dayDialogue5.at(1).at(progress));
			dialogue.setString(bartenderText.dayDialogue5.at(1).at(progress + 1));
		}

		else if(pd->drink < 6)
		{
			name.setString(bartenderText.dayDialogue5.at(2).at(progress));
			dialogue.setString(bartenderText.dayDialogue5.at(2).at(progress + 1));
		}

		else
		{
			name.setString(bartenderText.dayDialogue5.at(3).at(progress));
			dialogue.setString(bartenderText.dayDialogue5.at(3).at(progress + 1));
		}

	};	break;

	}

	//Check for end of conversation
	if (dialogue.getString() == "END")
	{
		progress = -1;

		//increment player task count
		switch (pd->tasks)
		{

		case(1):
		{
			if (pd->dayProgress != 5)
			{
				pd->tasks = pd->tasks + 1;
			}
		};	break;

		case(5):
		{
			if (pd->dayProgress == 1)
			{
				pd->tasks = pd->tasks + 1;
			}
		};	break;

		}

		if (pd->dayProgress == 5)
		{
			pd->drink = pd->drink + 1;
		}

		return true;
	}

	else if (dialogue.getString() == "PUZZLE")
	{
		progress = progress + 2;
		pd->currPuzzle = PuzzleNames::TESTPUZZLE;
		pd->puzzle = true;

		name.setString(bartenderText.dayDialogue4.at(pd->tasks).at(progress));
		dialogue.setString(bartenderText.dayDialogue4.at(pd->tasks).at(progress + 1));
	}

	return false;


}
