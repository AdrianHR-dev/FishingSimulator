#pragma once
#include "BaseClasses/GameObject.h"
#include "BaseClasses/Animation.h"

enum class FishStatus { SPLASH, IDLE, CAUGHT };

class Fish : public GameObject
{
public:

	Fish();
	~Fish();

	void update(float dt);

	//GETTERS FOR ANIMATIONS TO BE ACCESSED FROM BACKGROUND CLASS
	Animation* getFishCatch()
	{
		return &fishCatch;
	}

	Animation* getShoeCatch()
	{
		return &shoeCatch;
	}

	Animation* getEngineCatch()
	{
		return &engineCatch;
	}

	Animation* getHandCatch()
	{
		return &handCatch;
	}

	//TEXTURE GETTERS FOR LEVEL CLASS ACCESS

	sf::Texture* getCatchSheet()
	{
		return &catchTexture;
	}

	//Getter and setter for fish status
	FishStatus getFishStatus();
	void setFishStatus(FishStatus newStatus);

private:

	sf::Texture splashSheet;
	Animation splash;

	sf::Texture catchTexture;
	Animation fishCatch;
	Animation shoeCatch;
	Animation engineCatch;
	Animation handCatch;

	FishStatus fishStatus;

	float timeLog;

};

