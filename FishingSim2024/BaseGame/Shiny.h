#pragma once

#include "Item.h"
#include "ShinyDialogue.h"
#include "BaseClasses/Animation.h"

class Shiny : public Item
{
public:
	Shiny();
	~Shiny();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endInvestigation(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &shinyDialogue;
	}

private:

	ShinyDialogue shinyDialogue;
	Animation shineAnim;
	sf::Texture shinyTexture;

};

