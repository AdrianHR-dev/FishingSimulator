#include "HomeDialogue.h"

HomeDialogue::HomeDialogue()
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

HomeDialogue::~HomeDialogue()
{

}

bool HomeDialogue::DialogueUpdate(PlayerData* pd)
{
	progress = progress + 2;

	name.setString(homeText.homeDialogue.at(1).at(progress));
	dialogue.setString(homeText.homeDialogue.at(1).at(progress + 1));

	//Check for end of conversation
	if (dialogue.getString() == "END")
	{
		progress = -1;

		return true;
	}

	return false;


}

