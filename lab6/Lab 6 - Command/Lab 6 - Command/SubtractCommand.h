#pragma once
#include "Accumulator.h"
#include "iCommand.h"

class SubtractCommand : public iCommand
{
public:
	SubtractCommand(Accumulator & accumulator, int amount);
	~SubtractCommand();

	void execute();
	void undo();
private:
	SubtractCommand(const SubtractCommand &copy);
	SubtractCommand operator=(const SubtractCommand &rhs);
	SubtractCommand();

	Accumulator & m_accumulator;
	int m_amount;
};