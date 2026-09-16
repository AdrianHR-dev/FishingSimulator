#include "DoorText.h"

DoorText::DoorText()
{

	std::map<int, std::string> doorInvestigation1;


	doorInvestigation1.insert({ 1,"You" });
	doorInvestigation1.insert({ 2,"..." });

	doorInvestigation1.insert({ 3, "You" });
	doorInvestigation1.insert({ 4, "It's locked." });

	doorInvestigation1.insert({ 5, "You" });
	doorInvestigation1.insert({ 6, "Obviously." });

	doorInvestigation1.insert({ 7, "You" });
	doorInvestigation1.insert({ 8, "Let's see... a 4-digit combination lock..." });

	doorInvestigation1.insert({ 9, "You" });
	doorInvestigation1.insert({ 10, "Well there's a note here, so maybe-" });

	doorInvestigation1.insert({ 11, "You" });
	doorInvestigation1.insert({ 12, "..." });

	doorInvestigation1.insert({ 13, "You" });
	doorInvestigation1.insert({ 14, "No, of course it doesn't just say the code."});

	doorInvestigation1.insert({ 15, "You" });
	doorInvestigation1.insert({ 16, "Ok, let's have a look here." });

	doorInvestigation1.insert({ 17, "You" });
	doorInvestigation1.insert({ 18, "PUZZLE" });

	doorInvestigation1.insert({ 19, "You" });
	doorInvestigation1.insert({ 20, "..." });

	doorInvestigation1.insert({ 21, "You" });
	doorInvestigation1.insert({ 22, "Huh. I actually got it."});

	doorInvestigation1.insert({ 23, "You" });
	doorInvestigation1.insert({ 24, "This better be worth it." });

	doorInvestigation1.insert({ 25, "You" });
	doorInvestigation1.insert({ 26, "END" });


	doorDialogue.insert({ 1, doorInvestigation1 });
}

DoorText::~DoorText()
{


}