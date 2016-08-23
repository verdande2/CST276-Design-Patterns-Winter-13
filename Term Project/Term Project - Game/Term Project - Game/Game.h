#pragma once
#include "AnimatedBowserSprite.h"
#include <SFML/Audio.hpp>
#include <unordered_set>
#include "RockFactory.h"
#include "RockSprite.h"
#include "iUpdatable.h"
#include <list>

class TheSkyIsFallingGame
{
public:
	TheSkyIsFallingGame();
	~TheSkyIsFallingGame();

	void Start();
	
	static const unsigned int CHARACTER_MOVE_SPEED = 250; // px/sec
	static const unsigned int BASE_ROCK_VELOCITY = 200; // px/sec
	static const unsigned int RESOLUTION_WIDTH = 800;
	static const unsigned int RESOLUTION_HEIGHT = 600;
	static const unsigned int COLOR_MODE = 32;

private:
	void Init();
	void DrawMenuBar();
	void MainGameLoop();
	bool CheckForCollisions();
	void StartBackgroundMusic();
	void StopBackgroundMusic();

	void ThrowRocks(unsigned int elapsedTime);
	void CleanUpRocks();

	void ResetAfterDeath();

	void IncreaseRockSize();
	void DecreaseRockSize();
	
	void RegisterClockUpdatableObject(iUpdatable* obj);
	void UnregisterClockUpdatableObject(iUpdatable* obj);

	AnimatedBowserSprite m_player;

	sf::Clock m_clock;
	std::list<iUpdatable*> m_clockObservers;

	std::unordered_set<RockSprite*> m_rocks; 

	sf::Music m_backgroundMusic;
	sf::RenderWindow m_window;

	unsigned int m_rockSpawnRate; // in rocks per second
	unsigned int m_rockBaseSize; // radius of rock
	unsigned int m_rockVelocity; // in px/sec
	unsigned int m_rockSizeVariation; // rocks will be of size m_rockBaseSize +/- m_rockSizeVariation

	RockFactory m_rockFactory;

	void HandleEvent(sf::Event event);
};