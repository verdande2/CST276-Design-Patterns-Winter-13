#include "RockFactory.h"
#include <algorithm>
using std::max;

RockSprite RockFactory::GetRock(unsigned int base_size, unsigned int size_variation, unsigned int movementSpeed)
{
	// generate a rock with a size within (base-var, base+var) where base = base_size and var = size_variation
	unsigned int size = max(base_size + rand()%(2*size_variation) - size_variation, (unsigned int)10); // minimum size of 25px radius

	return RockSprite(size, movementSpeed);
}