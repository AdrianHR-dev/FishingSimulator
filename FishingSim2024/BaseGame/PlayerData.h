#pragma once
#include "SceneNames.h"
#include "CharacterNames.h"
#include "ItemNames.h"
#include "PuzzleNames.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

//Stores players progress and data
struct PlayerData
{
	bool transition;	//init at false
	bool fishing;
	bool talking;	//init at false
	int dayProgress;	//init at 1
	int day; //init at 1
	int tasks;	//init at 1
	int socksTasks;	//init at 1
	CharacterName currChar;	//init at noname
	ItemName currItem;	//init at noitem
	bool isDay;	
	bool nightInit;
	int luck;	//Random num each scene transition
	int drink; //init at 0

	bool initialised = false;
	bool puzzle;
	PuzzleNames currPuzzle;
	float beastTime; //Timer for beast trigger in end sequence
	bool mapHint;
	bool credits;

	void init()
	{
		tasks = 1;
		dayProgress = 1;
		day = 1;
		currChar = NONAME;
		currItem = NOITEM;
		transition = false;
		talking = false;
		fishing = false;
		isDay = true;
		nightInit = true;
		luck = 1;
		socksTasks = 1;
		puzzle = false;
		currPuzzle = PuzzleNames::NOPUZZLE;
		drink = 0;
		beastTime = 0.0f;
		mapHint = false;
		credits = false;
	}

	void startDay()
	{
		isDay = true;
		talking = false;
		day = day + 1;

		if (tasks == 10)
		{
			dayProgress = dayProgress + 1;
		}

		if (socksTasks == 3 || socksTasks == 5)
		{
			socksTasks++;
		}

		else if (socksTasks == 7)
		{
			socksTasks = 6;
		}

		else if (socksTasks < 3 && day > 3)
		{
			socksTasks = -1;
		}

		tasks = 1;
		
		saveData();
		
	}

	//DATA FORMAT
	//DAYPROGRESS
	//DAY
	//SOCKSTASKS

	//SAVE OCCURS AT START OF EACH DAY
	void loadData()
	{
		// Create a text string, which is used to output the text file
		std::string saveData;
		int i = 0;
		// Read from the text file
		std::ifstream saveFile("SaveData/save.txt");

		// Use a while loop together with the getline() function to read the file line by line
		while (std::getline(saveFile, saveData)) {
			// Output the text from the file

			int data = std::stoi(saveData);

			switch (i)
			{

			case(0):
			{
				dayProgress = data;
			};	break;

			case(1):
			{
				day = data;
			};	break;

			case(2):
			{
				socksTasks = data;
			};	break;

			}

			i++;
		}

		// Close the file
		saveFile.close();
	}

	void saveData()
	{
		std::ofstream SaveFile("SaveData/save.txt");

		SaveFile << std::to_string(dayProgress) << std::endl;

		SaveFile << std::to_string(day) << std::endl;

		SaveFile << std::to_string(socksTasks);

		SaveFile.close();
	}
};