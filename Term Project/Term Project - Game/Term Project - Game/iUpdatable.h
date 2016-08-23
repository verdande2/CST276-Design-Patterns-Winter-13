#pragma once

class iUpdatable
{
public:
	virtual void Update(unsigned int timeElapsed) = 0;
};