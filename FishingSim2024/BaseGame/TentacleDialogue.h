#pragma once

#include "Dialogue.h"
#include "TentacleText.h"

class TentacleDialogue : public Dialogue
{
public:
	TentacleDialogue();
	~TentacleDialogue();

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
	TentacleText tentacleText;

};

