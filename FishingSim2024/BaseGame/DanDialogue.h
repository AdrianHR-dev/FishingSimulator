#pragma once

#include "Dialogue.h"
#include "Scene.h"
#include "DanText.h"

class DanDialogue : public Dialogue
{
public:
	DanDialogue();
	~DanDialogue();

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
	DanText danText;

};

