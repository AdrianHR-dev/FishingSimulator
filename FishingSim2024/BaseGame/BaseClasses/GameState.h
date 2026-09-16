#pragma once

//This one is my personal favourite
//And yours too! Because you're me! Presumably!
//If your not me, and thus, we then I apologise for all this rambling you've been put through
//What are you doing here any way
//Are you a stranger playing my game? That would be cool I think
//Hey chum let me know if our game does well enough that strangers start playing it alright?!
//Don't keep me out the loop!

//Anywho, enumerator for allll different types of gamestates
//I've given you two standards here, but this is one of the few BaseClasses I'll let you alter without my permission as you'll definetly
//need to alter this line for EVEYR SINGLE GAME EVER THAT YOU MAKE EVER FOR EVER!!!!!

enum class State { MENU, GAMEPLAY, FISHING, PUZZLE, DRUNKEND, BADEND, GOODEND, CLOSE, CUTSCENE, CREDITS};

class GameState
{
public:
	//Functions are simple enough, just get and set gamestate
	// Set the current state
	void setCurrentState(State gs);
	// Returns the current state.
	State getCurrentState();

protected:
	//And look we got outselves a little gamestate here :3
	//Say hi to the little guy :3
	//Look at him go....
	State currentState;
};