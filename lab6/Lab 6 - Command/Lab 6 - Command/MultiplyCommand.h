#pragma once
#include "Accumulator.h"
#include "iCommand.h"

class MultiplyCommand : public iCommand
{
public:
	MultiplyCommand(Accumulator & accumulator, int amount);
	~MultiplyCommand();

	void execute();
	void undo();
private:
	MultiplyCommand(const MultiplyCommand &copy);
	MultiplyCommand operator=(const MultiplyCommand &rhs);
	MultiplyCommand();

	Accumulator & m_accumulator;
	int m_amount;
};