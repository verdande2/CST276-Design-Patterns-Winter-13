#pragma once
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"

class RockSprite : public AnimatedSprite
{
public:
	RockSprite(unsigned int radius, unsigned int movementSpeed);
	~RockSprite();

	RockSprite operator=(const RockSprite &rhs);


	void SetMovementSpeed(unsigned int movementSpeed);
	void SetRadius(unsigned int radius);

	unsigned int GetRadius() const;
	unsigned int GetMovementSpeed() const;

	void MoveDown(unsigned int elapsedTime); // moves the rock down the screen according to velocity*elapsedTime
	void Update(unsigned int elapsedTime);
private:
	RockSprite();
	
	void AdvanceFrame();
	void Reset();

	unsigned int m_movementSpeed;
	unsigned int m_radius;
	int m_rotationVelocity; // in deg/sec
};