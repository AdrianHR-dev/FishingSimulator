#pragma once
#include "Dialogue.h"
#include "ShoeText.h"

class ShoeDialogue : public Dialogue
{
public:
	ShoeDialogue();
	~ShoeDialogue();

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
	ShoeText shoeText;


};

