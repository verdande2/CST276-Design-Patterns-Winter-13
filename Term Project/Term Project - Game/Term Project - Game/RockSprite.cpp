#include "RockSprite.h"
#include "ImageManager.h"

RockSprite::RockSprite(unsigned int radius, unsigned int movementSpeed)
	: m_radius(radius),
	m_movementSpeed(movementSpeed)
{
	sf::Image rockImage = ImageManager::GetImage("images/rock.png");
	m_texture.loadFromImage(rockImage);
	m_sprite.setTexture(m_texture);

	m_rotationVelocity = (rand()%360+1) - 180;
	if(m_rotationVelocity == 0)
	{
		m_rotationVelocity = 1; // quick, dirty
	}

	// now scale the rock to proper size
	m_width = 2*m_radius;
	m_height = 2*m_radius;
	float scaleFactor = m_radius/75.0f;
	m_sprite.scale(scaleFactor, scaleFactor);

	m_sprite.setOrigin(m_radius, m_radius);
}

RockSprite::~RockSprite(){}


void RockSprite::SetMovementSpeed(unsigned int movementSpeed)
{
	m_movementSpeed = movementSpeed;
}

void RockSprite::SetRadius(unsigned int radius)
{
	m_radius = radius;
}

void RockSprite::Update(unsigned int elapsedTime)
{
	// no need to mess with m_timeSinceLastUpdate because this currently is just a rotating sprite instead of frames
	//m_sprite.rotate((float)elapsedTime / 1000.0f * (float)m_rotationVelocity);
}

void RockSprite::MoveDown(unsigned int elapsedTime)
{
	m_sprite.move(0, (float)elapsedTime / 1000.0f * (float)m_movementSpeed);
}

void RockSprite::Reset()
{
	m_sprite.setRotation(0.0f);
}

void RockSprite::AdvanceFrame()
{
	// sprite animation temp disabled for rock
}

unsigned int RockSprite::GetRadius() const
{
	return m_radius;
}

unsigned int RockSprite::GetMovementSpeed() const
{
	return m_movementSpeed;
}