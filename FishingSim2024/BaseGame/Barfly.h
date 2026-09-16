#pragma once

#include "Character.h"
#include "BarflyDialogue.h"

class Barfly :public Character
{
public:


	Barfly();
	~Barfly();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endConvo(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &barflyDialogue;
	}

	void setNight(bool n)
	{
		night = n;
	}

private:

	Animation neutral;
	Animation side;
	Animation blank;
	Animation thinking;
	Animation angry;
	Animation distance;

	BarflyDialogue barflyDialogue;
	bool night;



};
