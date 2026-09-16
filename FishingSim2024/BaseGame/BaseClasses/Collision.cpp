#include "Collision.h"

//Check for two boxes colliding!!!!
bool Collision::checkBoundingBox(GameObject* col1, GameObject* col2)
{
	//Compare all boxes sizes and widths to determine  the existence of any collisions
	if (col1->getCollisionBox().left + col1->getCollisionBox().width < col2->getCollisionBox().left)
		return false;
	if (col1->getCollisionBox().left > col2->getCollisionBox().left + col2->getCollisionBox().width)
		return false;
	if (col1->getCollisionBox().top + col1->getCollisionBox().height < col2->getCollisionBox().top)
		return false;
	if (col1->getCollisionBox().top > col2->getCollisionBox().top + col2->getCollisionBox().height)
		return false;

	return true;
}

//Hmmm i wonder if a box would ever collide with a single point hmmm
//GOOD THING THIS FUNCTION CHECKS FOR US B)
bool Collision::checkBoxPoint(GameObject* col1, sf::Vector2f col2)
{
	//Get all sides of boxes compared to point location and determine if any collisions have occurred
	if (col1->getCollisionBox().left + col1->getCollisionBox().width < col2.x)
		return false;
	if (col1->getCollisionBox().left > col2.x)
		return false;
	if (col1->getCollisionBox().top + col1->getCollisionBox().height < col2.y)
		return false;
	if (col1->getCollisionBox().top > col2.y)
		return false;

	return true;
}

//CIRCLE COLLISON!!!!
bool Collision::checkBoundingCircle(GameObject* col1, GameObject* col2)
{
	// Get radii for both objects
	float radius1 = col1->getSize().x / 2;
	float radius2 = col2->getSize().x / 2;
	//Find center point of both objects
	float xpos1 = col1->getPosition().x + radius1;
	float xpos2 = col2->getPosition().x + radius2;
	float ypos1 = col1->getPosition().y + radius1;
	float ypos2 = col2->getPosition().y + radius2;

	//Distance calc to determine collision
	if (pow(xpos2 - xpos1, 2) + pow(ypos2 - ypos1, 2) < pow(radius1 + radius2, 2))
	{
		return true;
	}
	return false;
}

