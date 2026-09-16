#include "GameObject.h"


GameObject::GameObject()
{
	input = nullptr;
}

GameObject::~GameObject()
{

}

//OVERRIDE FUNCTIONS HERE
void GameObject::update(float dt)
{

}

void GameObject::handleInput(float dt)
{

}


bool GameObject::isAlive()
{
	return alive;
};

void GameObject::setAlive(bool newState)
{
	alive = newState;
}

//Collision functions here!

//Get set collider
bool GameObject::isCollider()
{
	return collider;
}

void GameObject::setCollider(bool newCollide)
{
	collider = newCollide;
}

//Set get collision box
void GameObject::setCollisionBox(float x, float y, float width, float height)
{
	collisionBox = sf::FloatRect(x, y, width, height);
}

sf::FloatRect GameObject::getCollisionBox()
{
	return sf::FloatRect(collisionBox.left + getPosition().x - getOrigin().x, collisionBox.top + getPosition().y - getOrigin().y, collisionBox.width, collisionBox.height);

}

//CHUM HAVE THIS FUNCTION INHERITED WITHIN ANOTHER CLASS AND OVERWRITTEN!!!
void GameObject::collisionResponse(GameObject* collider)
{

}