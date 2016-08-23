#include "DivideCommand.h"

DivideCommand::DivideCommand(Accumulator & accumulator, int amount)
	: m_accumulator(accumulator),
	m_amount(amount)
{

}

DivideCommand::~DivideCommand()
{

}

void DivideCommand::execute()
{
	m_accumulator.Divide(m_amount);
}

void DivideCommand::undo()
{
	m_accumulator.Multiply(m_amount);
}