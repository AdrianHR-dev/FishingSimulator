#pragma once

#include "BaseClasses/GameObject.h"
#include "Dialogue.h"
#include "BaseClasses/Animation.h"
#include "CharacterNames.h"
#include "PlayerData.h"


class Character : public GameObject
{

public:

	Character();
	~Character();

	void handleInput(float dt) override;
	void update(float dt) override;


	virtual bool interact(PlayerData* pd);
	virtual void endConvo(PlayerData* pd);

	bool getTalking()
	{
		return talking;
	}

	CharacterName getCharName()
	{
		return charName;
	}

	virtual Dialogue* getDialogue() 
	{
		return &dialogue;
	}

protected:
	Dialogue dialogue;
	sf::Texture charTexture;
	CharacterName charName;
	bool talking;

};

