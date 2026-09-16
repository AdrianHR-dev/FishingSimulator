#pragma once

#include "Character.h"
#include "FishermanDialogue.h"

class Fisherman : public Character
{
public:

	Fisherman();
	~Fisherman();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endConvo(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &fishermanDialogue;
	}

private:

	Animation neutral;
	Animation smile;
	Animation blank;
	Animation thinking;
	Animation angry;
	Animation distance;

	FishermanDialogue fishermanDialogue;
};