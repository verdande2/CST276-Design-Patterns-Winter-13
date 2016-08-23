#pragma once
#include <SFML/Graphics.hpp>
#include "iUpdatable.h"

class AnimatedSprite : public iUpdatable
{
public:
	sf::Sprite & GetSprite();
	
	unsigned int GetNumFrames() const;
	unsigned int GetFrameLength() const;
	unsigned int GetHeight() const;
	unsigned int GetWidth() const;

	virtual ~AnimatedSprite();
	AnimatedSprite();
	AnimatedSprite(const AnimatedSprite &copy);

protected:
	unsigned int m_numFrames;
	unsigned int m_frameLength; // ms

	unsigned int m_timeSinceLastUpdate; // ms
	unsigned int m_currentFrame;

	unsigned int m_width;
	unsigned int m_height;

	sf::Sprite m_sprite;
	sf::Texture m_texture;
private:
	virtual void AdvanceFrame() = 0;
	virtual void Reset() = 0;
};