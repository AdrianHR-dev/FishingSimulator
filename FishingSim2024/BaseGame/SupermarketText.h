#pragma once
#include "map"
#include "string"

class SupermarketText
{
public:
	SupermarketText();
	~SupermarketText();

	//Maps player progress number to a map, which maps text progress to strings
	std::map <int, std::map <int, std::string>> supermarketDialogue;
};

