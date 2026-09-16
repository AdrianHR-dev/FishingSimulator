#include "Animation.h"

Animation::Animation()
{
	//Initialise all necessary variables
	currentFrame = 0;
	elapsedTime = 0.f;
	isPlaying = true;
	isLooping = true;
	animationSpeed = 0.0f;
	flipped = false;
}

Animation::~Animation()
{

}

//Adds a rectangular frame to the animation
void Animation::addFrame(sf::IntRect rect)
{
	frames.push_back(rect);
}

// The Biggie! The function that does the animating!
//Runs the animation if playing, loops at the end if told to
void Animation::animate(float dt)
{
	if (isPlaying)
	{
		elapsedTime += dt;
		if (elapsedTime >= animationSpeed)
		{
			currentFrame++;
			if (currentFrame >= (int)frames.size())
			{
				if (isLooping)
				{
					currentFrame = 0;
				}
				else
				{
					currentFrame--;
					setPlaying(false);
				}
			}
			elapsedTime = 0;
		}
	}
}

//All the animation controls getters and setters

//Get current frame
sf::IntRect Animation::getCurrentFrame()
{
	frame = frames[currentFrame];
	if (flipped)
	{

		frame = sf::IntRect(frame.left + frame.width, frame.top, -frame.width, frame.height);
	}
	return frame;
}

//Animation size
int Animation::getSize()
{
	return (int)frames.size();
}

//Speed
void Animation::setFrameSpeed(float speed)
{
	animationSpeed = speed;
}

float Animation::getFrameSpeed()
{
	return animationSpeed;
}

//Flipped
void Animation::setFlipped(bool flip)
{
	flipped = flip;
};

bool Animation::getFlipped()
{
	return flipped;
};

//Looping
void Animation::setLooping(bool loop)
{
	isLooping = loop;
}

bool Animation::getLooping()
{
	return isLooping;
};

//Playing
void Animation::setPlaying(bool play)
{
	isPlaying = play;
};

bool Animation::getPlaying()
{
	return isPlaying;
};

//Begin playing animation
void Animation::play(bool play) {
	isPlaying = true;
};

//Halts AND resets animation all in one go! Amazing!
void Animation::stop()
{
	setPlaying(false);
	currentFrame = 0;
	elapsedTime = 0;
}

//Reset animation loop
void Animation::reset()
{
	currentFrame = 0;
	elapsedTime = 0;
}

//Pause animation
void Animation::pause()
{
	isPlaying = false;
}


