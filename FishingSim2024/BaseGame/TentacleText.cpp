#include "TentacleText.h"

TentacleText::TentacleText()
{

	std::map<int, std::string> tentacleInvestigation;

	tentacleInvestigation.insert({ 1,"You" });
	tentacleInvestigation.insert({ 2,"...?" });

	tentacleInvestigation.insert({ 3,"You" });
	tentacleInvestigation.insert({ 4,"What is that? It looks like... some sort \nof huge fish trying to come down\n from the dam..." });

	tentacleInvestigation.insert({ 5,"You" });
	tentacleInvestigation.insert({ 6,"Or... Maybe... \nJust a part of an even bigger fish...?" });

	tentacleInvestigation.insert({ 7,"You" });
	tentacleInvestigation.insert({ 8,"I should head on over and see if \neverything is ok." });

	tentacleInvestigation.insert({ 9, "You" });
	tentacleInvestigation.insert({ 10, "END" });


	tentacleDialogue.insert({ 1, tentacleInvestigation });
}

TentacleText::~TentacleText()
{


}
