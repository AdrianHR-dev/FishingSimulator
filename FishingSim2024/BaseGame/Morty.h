#pragma once


#include "Character.h"
#include "MortyDialogue.h"

class Morty : public Character
{
public:

	Morty();
	~Morty();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endConvo(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &mortyDialogue;
	}

private:

	Animation neutral;
	Animation blank;
	Animation smile;
	Animation thinking;
	Animation angry;
	Animation distance;

	MortyDialogue mortyDialogue;
};


