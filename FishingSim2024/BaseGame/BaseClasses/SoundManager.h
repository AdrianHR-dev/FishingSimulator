#pragma once

#include "Sound.h"
#include "Music.h"
#include "SFML\Audio.hpp"

//Might end up getting a little fiddly here
//If you want to speak to your manager nows your chance! Ermmm... the sound manager that is!!!
//Yeah let me see if I get this right

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	//Sound object ADDED
	void addSound(std::string filename, std::string lname);
	//sound object PLAYED (assuming it exists)
	void playSoundbyName(std::string lname);
	//stops all sounds at the same time
	void stopAllSounds();
	//Returns a specific sound by it's name
	sf::Sound* getSound(std::string lname);

	// Add music object, provide file path and key string.
	void addMusic(std::string filename, std::string lname);
	// Play/stream music based on key string provided (if music exists).
	void playMusicbyName(std::string lname);
	// Stop music.
	void stopAllMusic();
	// Return pointer to music object. Useful for controlling looping, play state, volume etc.
	sf::Music* getMusic();

private:
	//This vector stores all the sound objects for us how polite of it!
	std::vector<Sound> soundObjects;
	//This is another vector here to store the music objects how kind
	std::vector<Music> musicObjects;
	//Only the one music object, SFML shenanigans
	sf::Music music;
	
	//Sound object here
	//Reduce reuse recycle! And suchlike and whatnot....
	Sound s;
};

