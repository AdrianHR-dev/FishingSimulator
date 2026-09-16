#include "SupermarketText.h"

SupermarketText::SupermarketText()
{

	std::map<int, std::string> supermarketInvestigation;


	supermarketInvestigation.insert({ 1,"You" });
	supermarketInvestigation.insert({ 2,"I'll just go in, get some water and head\nhome once I deliver it." });

	supermarketInvestigation.insert({ 3,"You" });
	supermarketInvestigation.insert({ 4,"(I bought two big bottles of water)" });

	supermarketInvestigation.insert({ 5, "END" });
	supermarketInvestigation.insert({ 6, "END" });


	supermarketDialogue.insert({ 3, supermarketInvestigation });
}

SupermarketText::~SupermarketText()
{

}