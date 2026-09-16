#include "Fish.h"

Fish::Fish()
{
	//Loads and sets fish splash texture
	splashSheet.loadFromFile("gfx/Items/splashSheet.png");
	setTexture(&splashSheet);

	//Loads catch texture
	catchTexture.loadFromFile("gfx/Catches/catches.png");

	//Fish hidden initially
	setSize(sf::Vector2f(0.0f, 0.0f));

	//Fish starts in idle mode
	fishStatus = FishStatus::IDLE;

	//Set all 8 frames of splash animation
	splash.addFrame(sf::IntRect(0, 0, 16, 16));
	splash.addFrame(sf::IntRect(16, 0, 16, 16));
	splash.addFrame(sf::IntRect(32, 0, 16, 16));
	splash.addFrame(sf::IntRect(0, 16, 16, 16));
	splash.addFrame(sf::IntRect(16, 16, 16, 16));
	splash.addFrame(sf::IntRect(32, 16, 16, 16));
	splash.addFrame(sf::IntRect(0, 32, 16, 16));
	splash.addFrame(sf::IntRect(16, 32, 16, 16));

	fishCatch.addFrame(sf::IntRect(250, 0, 250, 250));
	shoeCatch.addFrame(sf::IntRect(0, 250, 250, 250));
	handCatch.addFrame(sf::IntRect(250, 250, 250, 250));
	engineCatch.addFrame(sf::IntRect(0, 500, 250, 250));

	//Splash fps and looping set
	splash.setFrameSpeed(1.0f / 12.0f);
	splash.setLooping(false);

	timeLog = 0.0f;
}

Fish::~Fish()
{

}

void Fish::update(float dt)
{
	if (timeLog < 5 && fishStatus != FishStatus::CAUGHT)
	{
		timeLog = timeLog + dt;
	}

	if (timeLog >= 5.0f && fishStatus != FishStatus::CAUGHT)
	{
		fishStatus = FishStatus::SPLASH;
	}

	if (fishStatus == FishStatus::SPLASH)
	{
		//Fish size applied
		setSize(sf::Vector2f(96.0f, 96.0f));

		//Fish collision box set for splash
		setCollisionBox(0, 0, 96, 96);

		setTexture(&splashSheet);

		//Fish splash animation plays
		splash.animate(dt);
		setTextureRect(splash.getCurrentFrame());

		//Once splash animation finishes, fish returns to idle state
		if (splash.getPlaying() == false)
		{
			setFishStatus(FishStatus::IDLE);
			timeLog = 0;
			splash.stop();
		}
	}
	//If fish is idle, hidden from view
	else if (fishStatus == FishStatus::IDLE)
	{
		//Random fish location updated
		int x = rand() % 490 + 50;
		int y = rand() % 550 + 100;

		setPosition(sf::Vector2f(x, y));

		//Fish variables reset for idle state
		setCollisionBox(0, 0, 0, 0);
		setSize(sf::Vector2f(0, 0));

		//Animation reset
		setTexture(&splashSheet);
		splash.setPlaying(true);
		splash.animate(0);
	}

	//Otherwise, fish is caught and victory screen displayed
	else if (fishStatus == FishStatus::CAUGHT)
	{
		//Variables set for victory screen
		setSize(sf::Vector2f(500.0f, 500.0f));
		setPosition(75.0f, 75.0f);

		//Texture set and loaded in level class as texture depends on gamestate!

		setTexture(&catchTexture);
		
	}
}

FishStatus Fish::getFishStatus()
{
	return fishStatus;
}

void Fish::setFishStatus(FishStatus newStatus)
{
	fishStatus = newStatus;
}
