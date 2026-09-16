#pragma once
#include "Dialogue.h"
#include "DrunkardText.h"

class DrunkardDialogue : public Dialogue
{
public:
	DrunkardDialogue();
	~DrunkardDialogue();

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
	DrunkardText drunkardText;
};

