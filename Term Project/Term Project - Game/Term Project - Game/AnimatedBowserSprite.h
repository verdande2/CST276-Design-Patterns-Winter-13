#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "AnimatedSprite.h"
#include "iUpdatable.h"

class AnimatedBowserSprite : public AnimatedSprite
{
private:
	void Reset();
	void AdvanceFrame();

	static enum FACING
	{
		FACING_LEFT,
		FACING_RIGHT
	};

	void SetFacing(AnimatedBowserSprite::FACING facing);

	FACING m_facing;
	unsigned int m_movementSpeed;

public:
	AnimatedBowserSprite(unsigned int movementSpeed);
	~AnimatedBowserSprite();

	void Update(unsigned int elapsedTime);

	void MoveRight(unsigned int elapsedTime);
	void MoveLeft(unsigned int elapsedTime);


};