#pragma once

#include "BaseClasses/GameObject.h"
#include "BaseClasses/Input.h"
#include "BaseClasses/Animation.h"
#include "BaseClasses/Collision.h"

class MenuButton : public GameObject
{
public:

	//Public member functions
	MenuButton();
	~MenuButton();

	void update(float dt);

	void collisionResponse();

protected:
	//Private member variables
	sf::Texture buttonTexture;

	Animation idleButton;
	Animation selectButton;

};