#pragma once
#include "Accumulator.h"
#include "iCommand.h"

class AddCommand : public iCommand
{
public:
	AddCommand(Accumulator & accumulator);
	void execute();
	void undo();
private:
	int m_amount;
	bool m_executed;
};