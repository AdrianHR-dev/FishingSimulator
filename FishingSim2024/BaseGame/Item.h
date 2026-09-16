#pragma once
#include "BaseClasses/GameObject.h"
#include "Dialogue.h"
#include "ItemNames.h"

class Item : public GameObject
{
public:

	Item();
	~Item();


	void handleInput(float dt) override;
	void update(float dt) override;

	virtual bool interact(PlayerData* pd);
	virtual void endInvestigation(PlayerData* pd);

	bool getTalking()
	{
		return talking;
	}

	ItemName getItemName()
	{
		return itemName;
	}

	virtual Dialogue* getDialogue()
	{
		return &dialogue;
	}

protected:

	Dialogue dialogue;
	sf::Texture itemTexture;
	ItemName itemName;
	bool talking;






};

