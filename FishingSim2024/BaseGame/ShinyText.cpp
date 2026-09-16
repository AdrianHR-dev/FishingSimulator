#include "ShinyText.h"

ShinyText::ShinyText()
{

	std::map<int, std::string> shinyInvestigation;

	shinyInvestigation.insert({ 1,"You" });
	shinyInvestigation.insert({ 2,"...?" });

	shinyInvestigation.insert({ 3,"You" });
	shinyInvestigation.insert({ 4,"There's something lying in the grass \nhere..." });

	shinyInvestigation.insert({ 5,"You" });
	shinyInvestigation.insert({ 6,"It's a set of keys! This has to be the set \nI'm looking for!" });

	shinyInvestigation.insert({ 7,"You" });
	shinyInvestigation.insert({ 8,"I should take this back to the fisherman \nnow." });

	shinyInvestigation.insert({ 9, "You" });
	shinyInvestigation.insert({ 10, "END" });


	shinyDialogue.insert({ 1, shinyInvestigation });
}

ShinyText::~ShinyText()
{


}
