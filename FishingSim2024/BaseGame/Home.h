#pragma once

#include "Item.h"
#include "HomeDialogue.h"

class Home : public Item
{
public:
	Home();
	~Home();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endInvestigation(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &homeDialogue;
	}

private:

	HomeDialogue homeDialogue;
};

