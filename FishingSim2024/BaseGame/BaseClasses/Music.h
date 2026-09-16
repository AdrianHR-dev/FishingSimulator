
#pragma once
#include "SFML\Audio.hpp"

//Yeah see told you we'd get music in
//Yeah cus you like songs don't you? I heard you like songs
//I like songs.
//Remember when we made some songs? We should do that again that was cool
//And then we can use this class to put them in our games!
//Wouldn't that be cool chum??

class Music
{
public:
	Music();
	~Music();

	//Music set with filename and given key, similar to sound function
	void setMusic(std::string lfilename, std::string keyName);

	//Getters for music variables
	std::string getName();
	std::string getFileName();

private:
	//Music filename stored with name given
	std::string filename;
	std::string name;
};

