#pragma once

#include "Dialogue.h"
#include "DoorText.h"

class DoorDialogue : public Dialogue
{
public:

	DoorDialogue();
	~DoorDialogue();

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
	DoorText doorText;
};


