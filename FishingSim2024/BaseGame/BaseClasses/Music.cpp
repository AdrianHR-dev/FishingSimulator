#include "Music.h"

Music::Music()
{
}

Music::~Music()
{
}

//Filename and name stored for music
//We're doing this a little differently, songs can be prettyyyyy big soooo
//We're gonna just save the details here for now
void Music::setMusic(std::string lfilename, std::string keyName)
{
	filename = lfilename;
	name = keyName;
}

std::string Music::getName()
{
	return name;
}

std::string Music::getFileName()
{
	return filename;
}
