#include "SupermarketDialogue.h"

SupermarketDialogue::SupermarketDialogue()
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

SupermarketDialogue::~SupermarketDialogue()
{

}

bool SupermarketDialogue::DialogueUpdate(PlayerData* pd)
{
	progress = progress + 2;

	name.setString(supermarketText.supermarketDialogue.at(pd->tasks).at(progress));
	dialogue.setString(supermarketText.supermarketDialogue.at(pd->tasks).at(progress + 1));

	//Check for end of conversation
	if (dialogue.getString() == "END")
	{
		progress = -1;

		//Determine whether to increment task count
		switch (pd->tasks)
		{

		case(3):
		{
			pd->tasks = pd->tasks + 1;
		};	break;

		}
		return true;
	}

	return false;


}