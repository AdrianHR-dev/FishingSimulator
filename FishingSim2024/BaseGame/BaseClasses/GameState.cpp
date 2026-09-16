#include "GameState.h"

//SET STATE!!!!
void GameState::setCurrentState(State gs)
{
	currentState = gs;
}

//RETURN STATE!!!!
State GameState::getCurrentState()
{
	return currentState;
}