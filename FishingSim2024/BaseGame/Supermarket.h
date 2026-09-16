#pragma once

#include "Item.h"
#include "SupermarketDialogue.h"

class Shop : public Item
{
public:
	Shop();
	~Shop();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endInvestigation(PlayerData* pd) override;

	SupermarketDialogue* getDialogue() override
	{
		return &supermarketDialogue;
	}

private:

	SupermarketDialogue supermarketDialogue;

};

