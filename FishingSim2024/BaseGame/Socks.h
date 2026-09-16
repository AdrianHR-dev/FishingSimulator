#pragma once
#include "Character.h"
#include "SocksDialogue.h"

class Socks : public Character
{
	
public:

	Socks();
	~Socks();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;
	void endConvo(PlayerData* pd) override;

	Dialogue* getDialogue() override
	{
		return &socksDialogue;
	}

private:

	Animation blank;
	Animation smile;
	Animation thinking;
	Animation angry;
	Animation distance;
	Animation map;

	SocksDialogue socksDialogue;

};

