
#pragma once
#include "SFML\Audio.hpp"

//You probably want sounds in your game
//You're probably gonna wanna get sounds in your game, like footsteps or bangs or voiceclips
//Well here's what you're gonna use to load them!
//Now bear in mind this is only sounds! Not music!
//Music will be the next thing i work on ok don't rush me jings man
//And we'll get them all accessed sometime later
//Set up a manager or something for it

class Sound
{
public:
	Sound();
	~Sound();

	//This takes the filepath and loads up the sound (It's also given a name mind you)
	void loadSound(std::string filename, std::string keyName);

	//Sound variable getters
	std::string getName();
	sf::Sound* getSound();

private:
	//Buffer for the sound ! :3
	sf::SoundBuffer* buffer;

	//SFML variable for the sound and we got a name for it too! What a treat!
	sf::Sound sound;
	std::string name;

};
