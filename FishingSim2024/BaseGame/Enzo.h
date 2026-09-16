#pragma once

#include "Character.h"
#include "EnzoDialogue.h"

class Enzo : public Character
{
public:

	Enzo();
	~Enzo();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endConvo(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &enzoDialogue;
	}

private:

	Animation neutral;
	Animation distance;

	EnzoDialogue enzoDialogue;
};

