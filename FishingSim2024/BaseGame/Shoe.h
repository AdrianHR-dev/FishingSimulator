#pragma once

#include "Item.h"
#include "ShoeDialogue.h"

class Shoe : public Item
{
public:

	Shoe();
	~Shoe();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endInvestigation(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &shoeDialogue;
	}

private:

	ShoeDialogue shoeDialogue;
};

