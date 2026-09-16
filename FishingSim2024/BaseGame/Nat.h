#pragma once

#include "Character.h"
#include "NatDialogue.h"

class Nat : public Character
{
public:

	Nat();
	~Nat();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endConvo(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &natDialogue;
	}

private:

	Animation neutral;
	Animation blank;
	Animation smile;
	Animation thinking;
	Animation angry;
	Animation distance;

	NatDialogue natDialogue;
};

