#pragma once

#include "Item.h"
#include "BaseClasses/Animation.h"

class Body : public Item
{
public:

	Body();
	~Body();

	void update(float dt) override;
	void handleInput(float dt) override;

	bool interact(PlayerData* pd) override;

private:


};

