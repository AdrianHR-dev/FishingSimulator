#pragma once

#include "Dialogue.h"
#include "MortyText.h"


class MortyDialogue : public Dialogue
{
public:
	MortyDialogue();
	~MortyDialogue();

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
	MortyText mortyText;
};


