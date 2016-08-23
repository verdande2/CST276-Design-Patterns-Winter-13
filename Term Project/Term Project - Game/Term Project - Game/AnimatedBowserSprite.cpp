#include "AnimatedBowserSprite.h"
#include "ImageManager.h"
#include <string>

#include <iostream>

AnimatedBowserSprite::AnimatedBowserSprite(unsigned int movementSpeed)
	: m_facing(FACING_RIGHT),
	m_movementSpeed(movementSpeed)
{
	sf::Image bowserImage = ImageManager::GetImage("images/bowser.png");
	m_texture.loadFromImage(bowserImage);
	m_sprite.setTexture(m_texture);
	
	m_frameLength = 300;
	m_numFrames = 4;
	m_width = 32;
	m_height =32;

	Reset(); 
}

AnimatedBowserSprite::~AnimatedBowserSprite(){}

void AnimatedBowserSprite::Update(unsigned int elapsedTime)
{
	// debug
	/*std::cout << "current position: (" << m_sprite.getPosition().x << "," << m_sprite.getPosition().y << ") frame: " << m_currentFrame << "/" << m_numFrames << " facing: ";
	switch(m_facing)
	{
		case FACING_LEFT:
			std::cout << "left";
			break;
		case FACING_RIGHT:
			std::cout << "right";
			break;
	}
	std::cout << std::endl;*/

	m_timeSinceLastUpdate += elapsedTime;
	if(m_timeSinceLastUpdate >= m_frameLength)
	{
		AdvanceFrame();
		m_timeSinceLastUpdate = 0;
	}
}
void AnimatedBowserSprite::AdvanceFrame()
{
	m_currentFrame = (m_currentFrame+1) % m_numFrames;

	unsigned int x_offset, y_offset;
	switch(m_facing)
	{
		case FACING_LEFT:
			y_offset = 0;
			x_offset = m_currentFrame * m_width;
			break;
		case FACING_RIGHT:
			y_offset = m_height;
			x_offset = m_currentFrame * m_width;
			break;
	}

	m_sprite.setTextureRect(sf::IntRect(x_offset, y_offset, m_width, m_height));
}

void AnimatedBowserSprite::SetFacing(AnimatedBowserSprite::FACING facing)
{
	if(facing != m_facing)
	{
		Reset(); // immediately change to the alternate facing sprite offsets
	}
	m_facing = facing;
	//AdvanceFrame();
}

void AnimatedBowserSprite::MoveLeft(unsigned int elapsedTime)
{
	SetFacing(AnimatedBowserSprite::FACING_LEFT);
	m_sprite.move(0.0f - (float)m_movementSpeed*elapsedTime/1000, 0.0f);
}

void AnimatedBowserSprite::MoveRight(unsigned int elapsedTime)
{
	SetFacing(AnimatedBowserSprite::FACING_RIGHT);
	m_sprite.move(m_movementSpeed*elapsedTime/1000, 0.0f);
}

void AnimatedBowserSprite::Reset()
{
	// set up initial offsets for animated sprite
	m_currentFrame = 0;

	unsigned int y_offset;
	switch(m_facing)
	{
		case AnimatedBowserSprite::FACING_LEFT:
			y_offset = 0;
			break;
		case AnimatedBowserSprite::FACING_RIGHT:
			y_offset = m_height;
			break;
	}
	m_sprite.setTextureRect(sf::IntRect(0, y_offset, m_width, m_height));
}