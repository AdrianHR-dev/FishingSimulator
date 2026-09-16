#pragma once

#include "Item.h"
#include "TentacleDialogue.h"
#include "BaseClasses/Animation.h"

class Tentacle : public Item
{
public:
	Tentacle();
	~Tentacle();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endInvestigation(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &tentacleDialogue;
	}

private:

	TentacleDialogue tentacleDialogue;
	Animation tentacleAnim;

};

