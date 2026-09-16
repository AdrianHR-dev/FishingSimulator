#include "DoorDialogue.h"

DoorDialogue::DoorDialogue()
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

DoorDialogue::~DoorDialogue()
{

}

bool DoorDialogue::DialogueUpdate(PlayerData* pd)
{
	progress = progress + 2;

	name.setString(doorText.doorDialogue.at(1).at(progress));
	dialogue.setString(doorText.doorDialogue.at(1).at(progress + 1));

	//Check for end of conversation
	if (dialogue.getString() == "END")
	{
		progress = -1;

		pd->tasks = pd->tasks + 1;

		return true;
	}

	if (dialogue.getString() == "PUZZLE")
	{
		progress = progress + 2;

		pd->currPuzzle = PuzzleNames::DOORLOCK;
		pd->puzzle = true;

		name.setString(doorText.doorDialogue.at(1).at(progress));
		dialogue.setString(doorText.doorDialogue.at(1).at(progress + 1));

	}

	return false;


}

