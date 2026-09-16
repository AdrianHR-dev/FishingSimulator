#pragma once

#include "Character.h"
#include "DanDialogue.h"

class Dan : public Character
{
public:

	Dan();
	~Dan();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endConvo(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &danDialogue;
	}

	void setNight(bool n)
	{
		night = n;
	}

private:

	Animation neutral;
	Animation smile;
	Animation turn;
	Animation thinking;
	Animation nervous;
	Animation distance;
	Animation blank;

	DanDialogue danDialogue;

	bool night;


};

