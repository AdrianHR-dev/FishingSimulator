#pragma once

#include "Dialogue.h"
#include "HomeText.h"

class HomeDialogue : public Dialogue
{
public:

	HomeDialogue();
	~HomeDialogue();

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
	HomeText homeText;
};

