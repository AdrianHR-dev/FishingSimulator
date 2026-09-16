#pragma once
#include "Character.h"
#include "DrunkardDialogue.h"

class Drunkard : public Character
{

public:

	Drunkard();
	~Drunkard();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endConvo(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &drunkardDialogue;
	}	

private:

	Animation neutral;
	Animation blank;
	Animation turn;
	Animation thinking;
	Animation angry;
	Animation distance;

	DrunkardDialogue drunkardDialogue;
};

