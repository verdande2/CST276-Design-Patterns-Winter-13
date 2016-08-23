#pragma once
#include "Accumulator.h"
#include "iCommand.h"

class DivideCommand : public iCommand
{
public:
	DivideCommand(Accumulator & accumulator, int amount);
	~DivideCommand();

	void execute();
	void undo();
private:
	DivideCommand(const DivideCommand &copy);
	DivideCommand operator=(const DivideCommand &rhs);
	DivideCommand();

	Accumulator & m_accumulator;
	int m_amount;
};