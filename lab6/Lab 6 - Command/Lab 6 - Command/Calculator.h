#pragma once
#include "Accumulator.h"
#include "HistoryManager.h"
#include <string>
using std::string;

class Calculator
{
public:
	Calculator();
	~Calculator();

	void Start();
	void ShowDisplay() const;
	string TakeInput() const;
	void ProcessCommand(string command);
	void Undo();
	void Redo();
	void ShowHelp() const;
	void ShowStartPage() const;
private:
	Calculator(const Calculator &copy);
	Calculator & operator=(const Calculator &rhs);

	Accumulator m_accumulator;
	HistoryManager m_historyManager;
};