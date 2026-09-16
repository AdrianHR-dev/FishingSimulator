#pragma once

#include "BaseClasses/GameObject.h"

class HelpButton : public GameObject
{
public:

	HelpButton();
	~HelpButton();

	void update(float dt);

private:

	sf::Texture buttonTexture;

};