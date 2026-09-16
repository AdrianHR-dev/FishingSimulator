#pragma once

#include "Dialogue.h"
#include "ShinyText.h"

class ShinyDialogue : public Dialogue
{
public:
	ShinyDialogue();
	~ShinyDialogue();

	bool DialogueUpdate(PlayerData* pd) override;

	void setProgress(int p)
	{
		progress = p;
	}

	sf::Text* getName() override
	{
		return &name;
	}

	sf::Text* getText() override
	{
		return &dialogue;
	}

protected:


	sf::Text name;
	sf::Text dialogue;
	ShinyText shinyText;



};

