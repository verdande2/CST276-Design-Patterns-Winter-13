#include "Calculator.h"

#include "iCommand.h"
#include "AddCommand.h"
#include "SubtractCommand.h"
#include "MultiplyCommand.h"
#include "DivideCommand.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <iomanip>
using std::setw;

#include <string>
using std::string;

#include <exception>
using std::exception;

#include <regex>
using std::tr1::regex;
using std::tr1::cmatch;
using std::tr1::smatch;
using std::tr1::regex_match;
using std::tr1::regex_search;

#include "ConsoleColor.h"
using ConsoleColor::SetTextColor;
using ConsoleColor::SetBgColor;

Calculator::Calculator()
{
	
}

Calculator::~Calculator()
{

}

void Calculator::ShowDisplay() const
{
	SetTextColor(ConsoleColor::GRAY);
	cout << "Current Accumulator Value: ";

	SetTextColor(ConsoleColor::RED);
	cout << setw(8) << m_accumulator.GetCurrentValue() << endl;

	SetBgColor(ConsoleColor::GRAY);
	
	SetTextColor(ConsoleColor::BLUE);
	cout << "Undo(" << m_historyManager.GetNumUndo() << ")";

	SetTextColor(ConsoleColor::GREEN);
	cout << setw(27) << "Redo(" << m_historyManager.GetNumRedo() << ")" << endl;

	SetTextColor(ConsoleColor::DARK_WHITE);
	SetBgColor(ConsoleColor::BLACK);
}

string Calculator::TakeInput() const
{
	string command;
	cout << ">";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	getline(cin, command);

	return command;
}

void Calculator::ProcessCommand(string command)
{
	regex regexExitCommand("^exit$", std::tr1::regex_constants::icase);
	regex regexUndoCommand("^undo$", std::tr1::regex_constants::icase);
	regex regexRedoCommand("^redo$", std::tr1::regex_constants::icase);
	regex regexHelpCommand("^help$", std::tr1::regex_constants::icase);
	regex regexAddCommand("^(\\d+) \\+$", std::tr1::regex_constants::icase);
	regex regexSubtractCommand("^(\\d+) -$", std::tr1::regex_constants::icase);
	regex regexMultiplyCommand("^(\\d+) \\*$", std::tr1::regex_constants::icase);
	regex regexDivideCommand("^(\\d+) /$", std::tr1::regex_constants::icase);

	cmatch match;

	iCommand* commandToExecute = nullptr;

	cout << "Processing " << command.c_str() << endl;
	//regex_search(move.begin(), move.end(), fromPlay) // validate 
	//regex_search(move.c_str(), from, fromPlay) // store result in from (cmatch)

	if(regex_search(command.c_str(), match, regexExitCommand))
	{
		// exit command, do nothing and let it pass through
		return; // no need to continue in the function 
	}
	else if(regex_search(command.c_str(), match, regexUndoCommand))
	{
		m_historyManager.Undo();
		return; // no need to continue in the function
	}
	else if(regex_search(command.c_str(), match, regexHelpCommand))
	{
		ShowHelp();
		return; // no need to continue in the function
	}
	else if(regex_search(command.c_str(), match, regexRedoCommand))
	{
		m_historyManager.Redo();
		return; // no need to continue in the function
	}
	else if(regex_search(command.c_str(), match, regexAddCommand))
	{
		commandToExecute = new AddCommand(m_accumulator, atoi(match[1].str().c_str()));
	}
	else if(regex_search(command.c_str(), match, regexSubtractCommand))
	{
		commandToExecute = new SubtractCommand(m_accumulator, atoi(match[1].str().c_str()));
	}
	else if(regex_search(command.c_str(), match, regexMultiplyCommand))
	{
		commandToExecute = new MultiplyCommand(m_accumulator, atoi(match[1].str().c_str()));
	}
	else if(regex_search(command.c_str(), match, regexDivideCommand))
	{
		commandToExecute = new DivideCommand(m_accumulator, atoi(match[1].str().c_str()));
	}else{
		throw exception("Invalid command.");
	}

	// now we have a valid command, execute it through the history manager
	m_historyManager.Execute(commandToExecute); // once the command is passed to the history manager, it is responsible for cleanup
}

void Calculator::Start()
{
	bool error = false;
	string command;
	
	ShowStartPage();

	while(error || command != "exit" ){
		try{
			ShowDisplay();
			command = TakeInput();
			ProcessCommand(command);
			error = false;
		}catch(exception e){
			cout << e.what() << endl;
			error = true;
		}
	}
}

void Calculator::ShowHelp() const
{
	SetTextColor(ConsoleColor::DARK_WHITE);
	cout << "-----Help-------------------------------" << endl;
	cout << "Supported commands: " << endl;
	cout << "[amount] + \t\tAddition" << endl;
	cout << "[amount] - \t\tSubtraction" << endl;
	cout << "[amount] / \t\tDivision" << endl;
	cout << "[amount] * \t\tMultiplication" << endl;
	cout << "undo \t\t\tUndo the last performed command." << endl;
	cout << "redo \t\t\tRedo the last undone command." << endl;
	cout << "help \t\t\tShows the help page." << endl;
	cout << "exit \t\t\tExits the program." << endl;
}

void Calculator::ShowStartPage() const
{
	SetTextColor(ConsoleColor::RED);
	system("cls");

	for(int i=0; i<4; ++i)
	{
		cout << endl;
	}

	cout << "                      Lab 6 - Command Pattern Calculator" << endl;
	cout << "                             by Andrew Sparkes" << endl;

	for(int i=0; i<18; ++i)
	{
		cout << endl;
	}

	SetTextColor(ConsoleColor::DARK_WHITE);
	system("pause");
	system("cls");
}