#pragma once

#include "Dialogue.h"
#include "FishermanText.h"

class FishermanDialogue : public Dialogue
{
public:
	FishermanDialogue();
	~FishermanDialogue();

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
	FishermanText fishermanText;

};

