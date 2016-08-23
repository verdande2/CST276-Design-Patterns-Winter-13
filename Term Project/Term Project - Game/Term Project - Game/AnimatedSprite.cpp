#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
	: m_currentFrame(0),
	m_frameLength(0),
	m_numFrames(0),
	m_timeSinceLastUpdate(0),
	m_width(0),
	m_height(0)
{

}
AnimatedSprite::~AnimatedSprite()
{

}

AnimatedSprite::AnimatedSprite(const AnimatedSprite &copy)
{
	
}

sf::Sprite & AnimatedSprite::GetSprite()
{
	return m_sprite;
}
unsigned int AnimatedSprite::GetNumFrames() const
{
	return m_numFrames;
}
unsigned int AnimatedSprite::GetFrameLength() const
{
	return m_frameLength;
}
unsigned int AnimatedSprite::GetHeight() const
{
	return m_height;
}
unsigned int AnimatedSprite::GetWidth() const
{
	return m_width;
}