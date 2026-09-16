#pragma once
#include "SFML/Graphics.hpp"
#include "Input.h"

//This is going to be your standard GameObject class
//ALLL objects will inherit from here
//You can alter each item with individual classes later
//If I;ve missed something HERE then you can come back and do it yourself you lazy git
//Quit hassling me, I'm putting a lot of time and effort into this alright chum? I could've left
//you with nothing to go on, but no! I'm doing this solely for you benefit! So cut me some slack 
//alright?

//Anyway game objects huzzah :3


//Inheriting from rectangle, we haven't really needed to use many other shapes (if any at all)
//For our games so far have we? We can alter this if need be but I do think its fine for now

class GameObject : public sf::RectangleShape
{
public:
	//Constructor destructor
	GameObject();
	~GameObject();

	//Override these in your custom classes chum
	virtual void handleInput(float dt);
	virtual void update(float dt);

	//Alive variable for player 
	//Getter 
	bool isAlive();

	//Setter
	void setAlive(bool newState);

	//Collision stuff here! Getter setter checker etc etc 
	bool isCollider();
	void setCollider(bool newCollide);
	sf::FloatRect getCollisionBox();
	void setCollisionBox(float x, float y, float width, float height);


	//We can ovverride this function too chum
	virtual void collisionResponse(GameObject* collider);

	// Input and window set for object
	void setInput(Input* in)
	{
		input = in;
	};

	void setWindow(sf::RenderWindow* wind)
	{
		window = wind;
	};

	//NOTE HERE! YOU INITIALLY HAD THESE VARIABLES AS PRIVATE!!! NOT ALLOWED I'M AFRAID!!! 
	//We have now fixed it to be protected (And I'm gonna have to go do this to all the other base classes)

protected:
	//Standard variables
	bool alive;

	// Collision variables
	sf::FloatRect collisionBox;
	bool collider;

	//Input for object
	Input* input;
	sf::RenderWindow* window;
};

