#include "ShoeText.h"

ShoeText::ShoeText()
{

	std::map<int, std::string> shoeInvestigation;


	shoeInvestigation.insert({1,"You"});
	shoeInvestigation.insert({ 2,"...?" });

	shoeInvestigation.insert({ 3,"You" });
	shoeInvestigation.insert({ 4,"Someone seems to have lost their shoe \ndown there..." });

	shoeInvestigation.insert({ 5, "You" });
	shoeInvestigation.insert({ 6, "I hope they're ok..." });

	shoeInvestigation.insert({ 7, "You" });
	shoeInvestigation.insert({ 8, "END" });


	shoeDialogue.insert({ 1, shoeInvestigation });
}

ShoeText::~ShoeText()
{


}