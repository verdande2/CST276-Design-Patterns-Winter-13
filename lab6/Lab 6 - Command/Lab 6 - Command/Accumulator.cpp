#include "Accumulator.h"

#include <exception>
using std::exception;

Accumulator::Accumulator()
	: m_value(0)
{
	
}

Accumulator::~Accumulator()
{
	m_value = 0;
}

int Accumulator::GetCurrentValue() const
{
	return m_value;
}

void Accumulator::Add(int amount)
{
	m_value += amount;
}

void Accumulator::Subtract(int amount)
{
	m_value -= amount;
}

void Accumulator::Multiply(int amount)
{
	m_value *= amount;
}

void Accumulator::Divide(int amount)
{
	if(amount == 0)
	{
		throw exception("Cannot divide by zero.");
	}
	
	if(m_value % amount != 0)
	{
		throw exception("This accumulator supports only integer values (divisor must evenly divide dividend).");
	}
	
	m_value /= amount;
}