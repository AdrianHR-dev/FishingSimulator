#pragma once

#include "Character.h"
#include "BartenderDialogue.h"

class Bartender : public Character
{
public:

	Bartender();
	~Bartender();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endConvo(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &bartenderDialogue;
	}

private:

	Animation neutral;
	Animation smile;
	Animation blank;
	Animation thinking;
	Animation angry;
	Animation distance;

	BartenderDialogue bartenderDialogue;
};