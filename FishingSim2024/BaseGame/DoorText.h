#pragma once


#include "Map.h"
#include "string.h"

class DoorText
{
public:

	DoorText();
	~DoorText();

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> doorDialogue;

};