#pragma once

#include "BaseClasses/GameObject.h"

class MoveZone : public GameObject
{
public:

	MoveZone();
	~MoveZone();

	void handleInput(float dt) override;
	void update(float dt) override;

private:

};

