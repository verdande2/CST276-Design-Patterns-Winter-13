#pragma once
#include "RockSprite.h"

class RockFactory
{
public:
	static RockSprite GetRock(unsigned int base_size, unsigned int size_variation, unsigned int velocity);
private:

};