#pragma once

#include "Item.h"
#include "DoorDialogue.h"

class Door : public Item
{
public:
	Door();
	~Door();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endInvestigation(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &doorDialogue;
	}

private:

	DoorDialogue doorDialogue;
};

