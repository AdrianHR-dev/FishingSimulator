#pragma once

#include "Map.h"
#include "string.h"

class ShinyText
{
public:

	ShinyText();
	~ShinyText();

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> shinyDialogue;


};

