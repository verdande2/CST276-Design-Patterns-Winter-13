#pragma once

class Accumulator
{
public:
	Accumulator();
	~Accumulator();

	int GetCurrentValue() const;

	void Add(int amount);
	void Subtract(int amount);
	void Multiply(int amount);
	void Divide(int amount);

private:
	Accumulator operator=(const Accumulator &rhs);
	Accumulator(const Accumulator &copy);
	int m_value;
};