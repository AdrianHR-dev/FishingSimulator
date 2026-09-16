#pragma once

#pragma once

#include "Item.h"
#include "BaseClasses/Animation.h"

class Beast : public Item
{
public:

	Beast();
	~Beast();

	void update(float dt) override;
	void handleInput(float dt) override;

private:

	Animation rise;
	sf::Texture beastTexture;

};

