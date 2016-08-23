#include "HistoryManager.h"

#include <exception>
using std::exception;

HistoryManager::HistoryManager()
{

}

HistoryManager::~HistoryManager()
{
	ClearAll();
}

void HistoryManager::Execute(iCommand* command)
{
	m_undoStack.push(command);
	command->execute();
	
	// we just performed a command (not an undo), so clear the redo stack
	// note this is emulating behavior in a program like Word
	while(!m_redoStack.empty())
	{
		m_redoStack.pop();
	}
}

void HistoryManager::Undo()
{
	if(m_undoStack.empty())
	{
		throw exception("Cannot undo, no commands on the undo stack.");
	}
	iCommand* command = m_undoStack.top();
	m_undoStack.pop();

	try
	{
		command->undo();
	}
	catch(exception e)
	{
		// even if an exception was thrown, we still need to push the command to the redo stack so it can be cleaned up properly later
		// we still rethrow the exception and let some other code handle it
		m_redoStack.push(command);
		throw e;
	}
	m_redoStack.push(command);
}

void HistoryManager::Redo()
{
	if(m_redoStack.empty())
	{
		throw exception("Cannot redo, no commands on the redo stack.");
	}
	iCommand* command = m_redoStack.top();
	m_redoStack.pop();

	m_undoStack.push(command);
	command->execute();
}

const iCommand & HistoryManager::GetNextUndo() const
{
	return *m_undoStack.top();
}

const iCommand & HistoryManager::GetNextRedo() const
{
	return *m_redoStack.top();
}

unsigned int HistoryManager::GetNumUndo() const
{
	return (unsigned int) m_undoStack.size();
}

unsigned int HistoryManager::GetNumRedo() const
{
	return (unsigned int) m_redoStack.size();
}

void HistoryManager::ClearAll()
{
	// delete all commands held in the manager
	while(!m_undoStack.empty())
	{
		delete m_undoStack.top();
		m_undoStack.pop();
	}
	while(!m_redoStack.empty())
	{
		delete m_redoStack.top();
		m_redoStack.pop();
	}
}