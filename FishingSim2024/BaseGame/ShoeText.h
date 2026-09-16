#pragma once

#include "map"
#include "string"

struct ShoeText
{
public:
	ShoeText();
	~ShoeText();

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> shoeDialogue;


};