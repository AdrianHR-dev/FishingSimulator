#include "Sound.h"

Sound::Sound()
{
	//Buffer initialised as null
	buffer = nullptr;
}

Sound::~Sound()
{

}

// Loads sound into memory and can be identified by key (name).
// Receives filepath and key name, loads sound file and stores alonside key
void Sound::loadSound(std::string filename, std::string keyName)
{
	buffer = new sf::SoundBuffer();
	buffer->loadFromFile(filename);
	sound.setBuffer(*buffer);
	name = keyName;
}

std::string Sound::getName()
{
	//Sound name returned for searches
	return name;
}

sf::Sound* Sound::getSound()
{
	return &sound;
}
