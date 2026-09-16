#pragma once

#include "Map.h"
#include "string.h"

class TentacleText
{
public:

	TentacleText();
	~TentacleText();

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> tentacleDialogue;


};

