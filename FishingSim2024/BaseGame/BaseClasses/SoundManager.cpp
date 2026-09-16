#include "SoundManager.h"


//Initial value set
//Music in your game will start looping autoamtically
//That usually happens on a main menu dunnit chum?
SoundManager::SoundManager()
{
	music.setLoop(true);
	music.setVolume(100);
}

SoundManager::~SoundManager()
{

}

//Pushes a sound onto the vector with a filename and sound name
void SoundManager::addSound(std::string filename, std::string keyName)
{

	soundObjects.push_back(s);
	soundObjects.back().loadSound(filename, keyName);

}

//Plays sound based on given name
void SoundManager::playSoundbyName(std::string keyName)
{
	for (int i = 0; i < soundObjects.size(); i++)
	{
		if (soundObjects[i].getName() == keyName)
		{
			soundObjects[i].getSound()->play();
			return;
		}
	}
}

//Stops all sound effects playing
void SoundManager::stopAllSounds()
{
	for (int i = 0; i < soundObjects.size(); i++)
	{
		soundObjects[i].getSound()->stop();
	}
}

//Gets a sound incase you gotta fiddle-diddle with it a little
//THIS WASN'T WORKING WE GONNA TRY POINTERS!
//ok it might be working now
//OK JOB DONE!
//UNLESS ANYTHING GOES WRONG WITH THE ACTUAL GAME PROGRAMMING LET IT BE KNOWN!
//THIS WAS THE FINAL THING I FINISHED!
//actually no wait i gotta go add all this to main nvrmind
sf::Sound* SoundManager::getSound(std::string keyName)
{
	for (int i = 0; i < soundObjects.size(); i++)
	{
		if (soundObjects[i].getName() == keyName)
		{
			return soundObjects[i].getSound();
		}
	}
	
	return NULL;
}

// Stores filename and key of music file. These are not loaded into memory but streamed when required.
void SoundManager::addMusic(std::string filename, std::string keyName)
{
	Music mu;
	musicObjects.push_back(mu);
	musicObjects.back().setMusic(filename, keyName);
}

// Starts streaming music file based on key provided.
void SoundManager::playMusicbyName(std::string keyName)
{
	for (int i = 0; i < musicObjects.size(); i++)
	{
		if (musicObjects[i].getName() == keyName)
		{
			music.openFromFile(musicObjects[i].getFileName());
			music.play();
			return;
		}
	}
}

// Stops music.
void SoundManager::stopAllMusic()
{
	music.stop();
}

// Returns pointer to music object.
sf::Music* SoundManager::getMusic()
{
	return &music;
}