#include "SubtractCommand.h"

SubtractCommand::SubtractCommand(Accumulator & accumulator, int amount)
	: m_accumulator(accumulator),
	m_amount(amount)
{

}

SubtractCommand::~SubtractCommand()
{

}

void SubtractCommand::execute()
{
	m_accumulator.Subtract(m_amount);
}

void SubtractCommand::undo()
{
	m_accumulator.Add(m_amount);
}