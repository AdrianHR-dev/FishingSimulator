#pragma once

#include "Dialogue.h"
#include "EnzoText.h"

class EnzoDialogue : public Dialogue
{
public:

	EnzoDialogue();
	~EnzoDialogue();

	bool DialogueUpdate(PlayerData* pd) override;
	CharacterStates getCurrState(PlayerData* pd) override;

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
	EnzoText enzoText;

};

