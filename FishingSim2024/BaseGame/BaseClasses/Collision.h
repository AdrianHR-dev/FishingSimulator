
#pragma once
#include "GameObject.h"

//CollisiOn aw man I love colliding with things
//It's just like real life!
//Remember when we fell off that wall? And we collided with the ground?
//Really hard?
//It's just like that... but in a game! In code! In programming
//Ok let's peep the implementation chum

class Collision
{
public:
	//Only need the collision checks for this class! What a treat how simple!
	
	//Standard bounding box between two boxes!
	static bool checkBoundingBox(GameObject* col1, GameObject* col2);

	//This checks for a collision between a box and... a point!!!!
	static bool checkBoxPoint(GameObject* col1, sf::Vector2f col2);

	//Check collision between two circles!!! I don't *THINK* we've really been using many circles tbh
	//BUT you've got a long life ahead of you, I'm sure you'll need this some time
	static bool checkBoundingCircle(GameObject* col1, GameObject* col2);

};