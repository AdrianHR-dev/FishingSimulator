#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

//Animations hooray! We love a good animation don't we chum?
//Like spongebob! Spongebob squarepants from the tv....
//He's an animation...


class Animation
{
public:

	Animation();
	~Animation();

	//These functions construct an animation
	//Frames added, speed set
	void addFrame(sf::IntRect rect);
	void setFrameSpeed(float speed);

	//Get frames in animation
	int getSize();

	//Run animation
	void animate(float dt);
	//Reset animation
	void reset();

	//Get the frame of animation
	sf::IntRect getCurrentFrame();

	//All the animation controls getters and setters
	float getFrameSpeed();
	void setFlipped(bool flip);
	bool getFlipped();
	void setLooping(bool loop);
	bool getLooping();
	void setPlaying(bool play);
	bool getPlaying();
	void play(bool play);
	void stop();
	void pause();


	//SEE! THIS ONE WAS ALSO SUPPOSED TO BE PROTECTED! GOOD THING I HAVE FIXED IT
	//AND CHANGED IT TO PROTECTED!!!
protected:
	//Heres all your variables chum
	//Frames vector + individual frame variables
	std::vector<sf::IntRect>frames;
	sf::IntRect frame;
	//Current frame of animation
	int currentFrame;
	//All the other handy-dandy variables
	//Speed, time tracking, playing, looping etc!
	//Again, you may come up with other ideas a few years down the line but this is what we have for now
	float animationSpeed;
	bool flipped;
	bool isLooping;
	bool isPlaying;
	float elapsedTime;

};