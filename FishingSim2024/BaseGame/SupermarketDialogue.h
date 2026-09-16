#pragma once
#include "Dialogue.h"
#include "SupermarketText.h"

class SupermarketDialogue : public Dialogue
{
public:

	SupermarketDialogue();
	~SupermarketDialogue();

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
	SupermarketText supermarketText;
};

