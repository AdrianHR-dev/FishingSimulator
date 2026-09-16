#pragma once

#include "BaseClasses/GameObject.h"
#include "BaseClasses/Input.h"
#include "BaseClasses/Animation.h"
#include "BaseClasses/Collision.h"
#include "Character.h"

#include "Scene.h"


class Cursor : public GameObject
{
public:
	//Public member functions for cursor
	Cursor();
	~Cursor();

	void update(float dt);
	void handleInput(float dt);

	void collisionResponses(Scene* currScene);
	void fishingCollisionResponse();

	MoveDirection getMoveDir()
	{
		return currentMoveDir;
	}

	CharacterName getCurrChar()
	{
		return currChar;
	}

	ItemName getCurrItem()
	{
		return currItem;
	}

private:
	//Private member variables for cursor class
	MoveDirection currentMoveDir;
	CharacterName currChar;
	ItemName currItem;

	sf::Texture cursorTexture;
	//Animation variables created
	Animation interact;
	Animation idleCursor;
	Animation move;
};