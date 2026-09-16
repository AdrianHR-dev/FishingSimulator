#pragma once

#include "Character.h"
#include "TestDialogue.h"

class TestCharacter : public Character
{
public:

	TestCharacter();
	~TestCharacter();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endConvo(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &testDialogue;
	}

private:

	Animation neutral;
	Animation smile;
	Animation turn;
	Animation thinking;
	Animation nervous;
	Animation distance;

	TestDialogue testDialogue;
};

