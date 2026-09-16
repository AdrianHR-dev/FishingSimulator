#pragma once

#include "Map.h"
#include "string.h"

class HomeText
{
public:

	HomeText();
	~HomeText();

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> homeDialogue;

};

