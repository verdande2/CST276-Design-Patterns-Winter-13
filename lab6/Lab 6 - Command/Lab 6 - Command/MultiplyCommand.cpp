#include "MultiplyCommand.h"

MultiplyCommand::MultiplyCommand(Accumulator & accumulator, int amount)
	: m_accumulator(accumulator),
	m_amount(amount)
{

}

MultiplyCommand::~MultiplyCommand()
{

}

void MultiplyCommand::execute()
{
	m_accumulator.Multiply(m_amount);
}

void MultiplyCommand::undo()
{
	m_accumulator.Divide(m_amount);
}