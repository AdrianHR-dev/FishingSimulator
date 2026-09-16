#include "HomeText.h"

HomeText::HomeText()
{

	std::map<int, std::string> homeInvestigation;


	homeInvestigation.insert({ 1,"" });
	homeInvestigation.insert({ 2,"Go home?\n [Y] = Yes	[N] = No" });

	homeInvestigation.insert({ 3, "END" });
	homeInvestigation.insert({ 4, "END" });


	homeDialogue.insert({ 1, homeInvestigation });
}

HomeText::~HomeText()
{


}