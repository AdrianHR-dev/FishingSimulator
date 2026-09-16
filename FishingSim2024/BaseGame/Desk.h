#pragma once

#include "Item.h"
#include "BaseClasses/Animation.h"
#include "DeskDialogue.h"

class Desk : public Item
{
public:

	Desk();
	~Desk();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endInvestigation(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &deskDialogue;
	}

private:

	DeskDialogue deskDialogue;

	Animation blank;
	Animation page;
};


