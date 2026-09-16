#pragma once
#include <vector>

//Input manager class!! Makes life a little easier... imo.... rather than using sf::Keyboard all over the place....
//We need ... keys!!!! And... mouse inputs!!!!

class Input
{
	//Now we can add more functions here in future, idk what type of games you're wanting to make chum right?
	//But for now I know what game *I* want to make so we're gonna do some simple chicanery with the mouse
	//And maybe keys just to have as a standard
	//VECTOR OF KEYS PRESSED DID I INCLUDE VECTOR?!?!
	//ok now i have:3
public:
	//This enum class is used to determine the state of the mouse (guh-doy)
	enum class MouseState { UP, DOWN, PRESSED };

	//Ok, ok, pretty cool pretty cool.. standard stuff
	Input();
	void update();

	//Focusing on keys here, these relate to the keys variable you'll find down in priv
	//Gets :3
	bool isKeyDown(int key);
	bool isKeyPressed(int key);

	//Sets :3
	void setKeyDown(int key);
	void setKeyUp(int key);

	//And mouse stuff here!!

	//Sets

	void setMouseX(int mx);
	void setMouseY(int my);

	//Gets
	int getMouseX();
	int getMouseY();

	//State sets
	void setLeftMouse(MouseState ms);
	void setRightMouse(MouseState ms);

	//State gets
	bool isLeftMouseDown();
	bool isRightMouseDown();


private:

	//Hi, I'm an array of 256 booleans. You might know me from such
	//classics as "That line of code a little further up where the note
	// mentioned me" and "Right here! I'm right here!". 
	//Sorry maybe a silly bit idk but just remember:
	//YOU thought this was funny so ..... blame yourself if you don't like my wit!
	//Anywho, they're all initialised to false.
	//As in, pressed??? False!
	bool keys[256]{ false };

	//Vector for pressed keys
	std::vector<int> pressed;

	//AND MOUSE VARIABLES TOO!
	//Ints for mouse position
	int mouseX, mouseY;
	//And here a mousestate is created for both the left AND right of the mouse
	//My mouse only really has those buttons and ig a middle button?
	//But idk why you'd want to use it?
	//Atleast not rn; add something here later if you really want to
	MouseState left, right;
};

