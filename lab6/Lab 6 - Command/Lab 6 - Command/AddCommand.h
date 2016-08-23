#pragma once
#include "Accumulator.h"
#include "iCommand.h"

class AddCommand : public iCommand
{
public:
	AddCommand(Accumulator & accumulator, int amount);
	~AddCommand();

	void execute();
	void undo();
private:
	AddCommand(const AddCommand &copy);
	AddCommand operator=(const AddCommand &rhs);
	AddCommand();

	Accumulator & m_accumulator;
	int m_amount;
};