#include "AddCommand.h"

AddCommand::AddCommand(Accumulator & accumulator, int amount)
	: m_accumulator(accumulator),
	m_amount(amount)
{

}

AddCommand::~AddCommand()
{

}

void AddCommand::execute()
{
	m_accumulator.Add(m_amount);
}

void AddCommand::undo()
{
	m_accumulator.Subtract(m_amount);
}