#include "Cursor.h"

Cursor::Cursor()
{
	//Cursor texture sheet loaded and set
	cursorTexture.loadFromFile("gfx/cursor.png");
	setTexture(&cursorTexture);

	//Important cursor variables set
	setSize(sf::Vector2f(24.0f, 24.0f));

	//Cursor animation frames set
	idleCursor.addFrame(sf::IntRect(0, 0, 16, 16));
	move.addFrame(sf::IntRect(16, 0, 16, 16));
	interact.addFrame(sf::IntRect(0, 16, 16, 16));

	currentMoveDir = MoveDirection::NONE;

}

Cursor::~Cursor()
{

}



void Cursor::update(float dt)
{
	idleCursor.animate(0);
	setTextureRect(idleCursor.getCurrentFrame());

	//Each frame, cursor relocates to actual mouse cursor location
	setPosition(sf::Vector2f(input->getMouseX(), input->getMouseY()));
}

void Cursor::handleInput(float dt)
{

		
}

void Cursor::fishingCollisionResponse()
{
	interact.animate(0);
	setTextureRect(interact.getCurrentFrame());

}

void Cursor::collisionResponses(Scene* currScene)
{ 
	//Check for reaction to moveboxes
	if (Collision::checkBoxPoint(&currScene->getSceneData().moveZones[MoveDirection::FORWARD], getPosition()))
	{
		setRotation(0);
		move.animate(0);
		setTextureRect(move.getCurrentFrame());

		currentMoveDir = MoveDirection::FORWARD;
	}

	else if (Collision::checkBoxPoint(&currScene->getSceneData().moveZones[MoveDirection::BACK], getPosition()))
	{
		setRotation(180);
		move.animate(0);
		setTextureRect(move.getCurrentFrame());


		currentMoveDir = MoveDirection::BACK;
	}

	else if(Collision::checkBoxPoint(&currScene->getSceneData().moveZones[MoveDirection::LEFT], getPosition()))
	{
		setRotation(270);
		move.animate(0);
		setTextureRect(move.getCurrentFrame());


		currentMoveDir = MoveDirection::LEFT;
	}

	else if (Collision::checkBoxPoint(&currScene->getSceneData().moveZones[MoveDirection::RIGHT], getPosition()))
	{
		setRotation(90);
		move.animate(0);
		setTextureRect(move.getCurrentFrame());


		currentMoveDir = MoveDirection::RIGHT;
	}

	else
	{
		setRotation(0);
		currentMoveDir = MoveDirection::NONE;

		//Check for collision with character
		int check = 0;
		for (auto& i : currScene->getSceneData().characters)
		{
			if (Collision::checkBoxPoint(i.second, getPosition()))
			{
				interact.animate(0);
				setTextureRect(interact.getCurrentFrame());

				setRotation(0);

				currChar = i.second->getCharName();
				check = 1;
			}
		}

		if (check == 0)
		{
			currChar = CharacterName::NONAME;

			//Check for collision with item
			for (auto& i : currScene->getSceneData().items)
			{
				if (Collision::checkBoxPoint(i.second, getPosition()))
				{
					interact.animate(0);
					setTextureRect(interact.getCurrentFrame());

					setRotation(0);

					currItem = i.second->getItemName();
					check = 1;
				}
			}

			if (check == 0)
			{
				currItem = ItemName::NOITEM;
			}
		}

	}


}

//
//void Cursor::collisionResponseInteract()
//{
//	interact.animate(0);
//	setTextureRect(interact.getCurrentFrame());
//
//}

