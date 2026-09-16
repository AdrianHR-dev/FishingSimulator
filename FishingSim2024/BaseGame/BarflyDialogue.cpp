#include "BarflyDialogue.h"

BarflyDialogue::BarflyDialogue()
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

BarflyDialogue::~BarflyDialogue()
{

}

CharacterStates BarflyDialogue::getCurrState(PlayerData* pd)
{
	if (progress == 1)
	{
		return barflyText.returnCharState(pd, progress);
	}

	else
	{
		return barflyText.returnCharState(pd, ((progress - 1) / 2) + 1); //((N-1)/2) + 1 eg. n = 3, input = 2; n = 7, input = 4
	}
}

bool BarflyDialogue::DialogueUpdate(PlayerData* pd)
{
	progress = progress + 2;

	if (pd->dayProgress < 4)
	{
		name.setString(barflyText.dayDialogue1.at(1).at(progress));
		dialogue.setString(barflyText.dayDialogue1.at(1).at(progress + 1));
	}

	else
	{
		switch (pd->dayProgress)
		{

		case(4):
		{
			name.setString(barflyText.dayDialogue4.at(pd->tasks).at(progress));
			dialogue.setString(barflyText.dayDialogue4.at(pd->tasks).at(progress + 1));

		};	break;

		case(5):
		{
			name.setString(barflyText.dayDialogue5.at(pd->tasks).at(progress));
			dialogue.setString(barflyText.dayDialogue5.at(pd->tasks).at(progress + 1));

		};	break;

		case(6):
		{
			name.setString(barflyText.dayDialogue6.at(1).at(progress));
			dialogue.setString(barflyText.dayDialogue6.at(1).at(progress + 1));

		};	break;


		case(9):
		{
			name.setString(barflyText.dayDialogue9.at(1).at(progress));
			dialogue.setString(barflyText.dayDialogue9.at(1).at(progress + 1));

		};	break;

		}
	}

	//Check for end of conversation
	if (dialogue.getString() == "END")
	{
		progress = -1;

		if (pd->dayProgress == 9)
		{
			pd->tasks = 10;
		}

		//increment player task count
	
			switch (pd->tasks)
			{
			case(1):
			{
				if (pd->dayProgress == 5)
				{
					pd->tasks = pd->tasks + 1;
				}

				if (pd->dayProgress == 6)
				{
					pd->tasks = 10;
				}

			};	break;

			case(2):
			{
				if (pd->dayProgress == 4)
				{
					pd->tasks = pd->tasks + 1;
				}
			};	break;

			}
	
		return true;
	}

	else if (dialogue.getString() == "PUZZLE")
	{
		progress = progress + 2;
		pd->currPuzzle = PuzzleNames::MAGICSQUARE;
		pd->puzzle = true;

		name.setString(barflyText.dayDialogue4.at(pd->tasks).at(progress));
		dialogue.setString(barflyText.dayDialogue4.at(pd->tasks).at(progress + 1));
	}

	return false;


}
