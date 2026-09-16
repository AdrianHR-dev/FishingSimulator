#include "DanDialogue.h"

DanDialogue::DanDialogue()
{
	//This can be changed if different characters are to have different text boxes,
	//tho there will have to be a way to set players textbox aswell
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

DanDialogue::~DanDialogue()
{

}

CharacterStates DanDialogue::getCurrState(PlayerData* pd)
{
	if (progress == 1)
	{
		return danText.returnCharState(pd, progress);
	}

	else
	{
		return danText.returnCharState(pd, ((progress - 1) / 2) + 1); //((N-1)/2) + 1 eg. n = 3, input = 2; n = 7, input = 4
	}
}

bool DanDialogue::DialogueUpdate(PlayerData* pd)
{
	progress = progress + 2;

	switch (pd->day)
	{

	case(1):
	{
		name.setString(danText.dayDialogue1.at(1).at(progress));
		dialogue.setString(danText.dayDialogue1.at(1).at(progress + 1));

	};	break;

	case(2):
	{
		name.setString(danText.dayDialogue2.at(1).at(progress));
		dialogue.setString(danText.dayDialogue2.at(1).at(progress + 1));

	};	break;

	case(3):
	{
		name.setString(danText.dayDialogue3.at(1).at(progress));
		dialogue.setString(danText.dayDialogue3.at(1).at(progress + 1));

	};	break;


	case(4):
	{
		name.setString(danText.dayDialogue4.at(1).at(progress));
		dialogue.setString(danText.dayDialogue4.at(1).at(progress + 1));

	};	break;

	case(5):
	{
		if (pd->isDay)
		{
			name.setString(danText.dayDialogue5.at(1).at(progress));
			dialogue.setString(danText.dayDialogue5.at(1).at(progress + 1));
		}

		else
		{ 
			name.setString(danText.dayDialogue5.at(2).at(progress));
			dialogue.setString(danText.dayDialogue5.at(2).at(progress + 1));
		}

	};	break;

	case(6):
	{
		name.setString(danText.dayDialogue6.at(1).at(progress));
		dialogue.setString(danText.dayDialogue6.at(1).at(progress + 1));

	};	break;

	case(7):
	{
		name.setString(danText.dayDialogue7.at(1).at(progress));
		dialogue.setString(danText.dayDialogue7.at(1).at(progress + 1));

	};	break;

	}

	//Check for end of conversation
	if (dialogue.getString() == "END")
	{
		progress = -1;
	
		if (pd->isDay && pd->day < 7)
		{
			//Player will also commence fishing after a Dan conversation in the day
			pd->fishing = true;
		}

		else if(pd->isDay == false)
		{
			pd->tasks = 10;
		}

		else
		{
			pd->tasks = 5;
		}

		return true;
	}

	return false;


}

