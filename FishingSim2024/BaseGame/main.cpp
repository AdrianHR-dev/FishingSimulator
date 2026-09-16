

//SFML INCLUDES
#include <SFML/Graphics.hpp>

//Base class includes
#include "BaseClasses/Input.h"
#include "BaseClasses/SoundManager.h"
#include "BaseClasses/GameState.h"
#include "SlidePuzzle.h"
#include "MagicSquare.h"
#include "DoorPuzzle.h"

//Add game-specific includes here in future eg. specific levels or scenes or states or suchlike or something

#include "PlayerData.h"
#include "PACLevel.h"
#include "FishingLevel.h"
#include "Menu.h"
#include "Map.h"
#include "BasePuzzle.h"
#include "DrunkEnd.h"
#include "BadEnd.h"
#include "GoodEnd.h"
#include "Cutscene.h"
#include "Credits.h"

void windowEvent(sf::RenderWindow* window, Input* in)
{

    //Window events handled here, cleaner than keeping it in main
    sf::Event event;
    while (window->pollEvent(event)) {
        //Switch statment for window event handling
        switch (event.type)
        {
            //Window close event
        case (sf::Event::Closed):
        {
            window->close();
        };  break;
        //Window resize event
        case(sf::Event::Resized):
        {
            //You will *NOT* resize the window to anything other than this!!! (1984 reference)
            window->setSize(sf::Vector2u(700, 700));
        };  break;
        //Input events are here, these are sent to functions in input class
        case(sf::Event::KeyPressed):
        {
            //Sends in code of pressed key
            //Sets it to be down
            in->setKeyDown(event.key.code);
        };  break;
        case(sf::Event::KeyReleased):
        {
            //OPPOSITE! now we're setting key UP :3
            in->setKeyUp(event.key.code);

        };  break;
       //And now the mouse!

        //Keep an eye on the mouse's position
        case(sf::Event::MouseMoved):
        {
            //X and y set in input class
            in->setMouseX(event.mouseMove.x);
            in->setMouseY(event.mouseMove.y);

        };  break;

        //Mouse button press
        case(sf::Event::MouseButtonPressed):
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                //Left mouse button pressed
                in->setLeftMouse(Input::MouseState::DOWN);
            }

            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                //Right mouse button pressed
                in->setLeftMouse(Input::MouseState::DOWN);
            }

        };  break;

        case(sf::Event::MouseButtonReleased):
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                //Left mouse button UP
                in->setLeftMouse(Input::MouseState::UP);
            }

            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                //Right mouse button UP
                in->setLeftMouse(Input::MouseState::UP);
            }

        };  break;

        }
    }
}


int main(int argc, char** argv[]) {
    //Render window of given size and name
    sf::RenderWindow window(sf::VideoMode(700, 700), "Fishing Simulator: Deluxe Edition");

    Input input;
    GameState gameState;
    SoundManager soundManager;
    PlayerData player;

    //init player and load data
    player.init();
    player.loadData();

    std::map<PuzzleNames, BasePuzzle*> puzzles;

    puzzles.insert({ PuzzleNames::TESTPUZZLE, new BasePuzzle(&window, &input, &gameState, &soundManager, &player)});
    puzzles.insert({ PuzzleNames::SLIDE, new SlidePuzzle(&window, &input, &gameState, &soundManager, &player) });
    puzzles.insert({ PuzzleNames::MAGICSQUARE, new MagicSquare(&window, &input, &gameState, &soundManager, &player) });
    puzzles.insert({ PuzzleNames::DOORLOCK, new DoorPuzzle(&window, &input, &gameState, &soundManager, &player) });

    gameState.setCurrentState(State::MENU);

    //Creates levels 
    PACLevel pacLevel(&window, &input, &gameState, &soundManager, &player);
    FishingLevel fishingLevel(&window, &input, &gameState, &soundManager, &player);
    Menu menu(&window, &input, &gameState, &soundManager, &player);
    DrunkEnd drunkEnd(&window, &input, &gameState, &soundManager, &player);
    BadEnd badEnd(&window, &input, &gameState, &soundManager, &player);
    GoodEnd goodEnd(&window, &input, &gameState, &soundManager, &player);
    Cutscene cutscene(&window, &input, &gameState, &soundManager, &player);
    Credits credits(&window, &input, &gameState, &soundManager, &player);

    //Change in time calculation variables
    sf::Clock clock;
    float dt;

    //Audio setup
    //Soundeffects
    soundManager.addSound("sfx/footsteps.wav", "footsteps");
    soundManager.addSound("sfx/textBeep.ogg", "textBeep");
    soundManager.addSound("sfx/splash.wav", "splash");
    soundManager.addSound("sfx/BigSplash.wav", "bigSplash");
    soundManager.addSound("sfx/tileMov.wav", "tileMove");
    soundManager.addSound("sfx/puzzleSolve.wav", "puzzleSolve");
    soundManager.addSound("sfx/attack.wav", "attack");
    soundManager.addSound("sfx/explode.wav", "explode");

    //Dialogue
    //DAY 1 (Also used for day 2 and 3)
    soundManager.addSound("sfx/day1Catch.wav", "day1Catch");

    //DAY 4
    soundManager.addSound("sfx/day4Catch.wav", "day4Catch");

    //DAY 5
    soundManager.addSound("sfx/day5Catch.wav", "day5Catch");

    //DAY 6
    soundManager.addSound("sfx/day6Catch.wav", "day6Catch");

    //Music
    soundManager.addMusic("sfx/water.wav", "water");
    soundManager.addMusic("sfx/nightAmbience.wav", "nightAmb");
    soundManager.addMusic("sfx/seasideTavern.wav", "seasideTavern");
    soundManager.addMusic("sfx/ambience.wav", "ambience");

    menu.initMusic();

    while (window.isOpen()) {
        //Window event handler called
        windowEvent(&window, &input);

        //Change in time calculation for each frame
        dt = clock.restart().asSeconds();

        switch (gameState.getCurrentState())
        {
            //Menu update and input and render function
        case(State::MENU):
        {
            menu.handleInput(dt);
            menu.update(dt);
            menu.render();

        }; break;

        case(State::GAMEPLAY):
        {
            pacLevel.handleInput(dt);
            pacLevel.update(dt);
            pacLevel.render();

        }; break;

        case(State::FISHING):
        {
            fishingLevel.handleInput(dt);
            fishingLevel.update(dt);
            fishingLevel.render();
        }; break;

        case(State::DRUNKEND):
        {
            drunkEnd.handleInput(dt);
            drunkEnd.update(dt);
            drunkEnd.render();
        }; break;

        case(State::BADEND):
        {
            badEnd.handleInput(dt);
            badEnd.update(dt);
            badEnd.render();
        }; break;

        case(State::GOODEND):
        {
            goodEnd.handleInput(dt);
            goodEnd.update(dt);
            goodEnd.render();
        }; break;

        case(State::CUTSCENE):
        {
            cutscene.handleInput(dt);
            cutscene.update(dt);
            cutscene.render();
        }; break;

        case(State::CREDITS):
        {
            credits.handleInput(dt);
            credits.update(dt);
            credits.render();
        }; break;

        case(State::PUZZLE):
        {
            puzzles.at(player.currPuzzle)->handleInput(dt);
            puzzles.at(player.currPuzzle)->update(dt);
            puzzles.at(player.currPuzzle)->render();

            if (player.puzzle == false)
            {
                player.currPuzzle = PuzzleNames::NOPUZZLE;
                gameState.setCurrentState(State::GAMEPLAY);
            }

        }; break;

        case(State::CLOSE):
        {
            return 0; 

        };  break;

        }

        input.update();
    }

    return 0;
 
}