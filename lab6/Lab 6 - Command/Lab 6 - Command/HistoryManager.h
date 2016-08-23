#pragma once
#include "iCommand.h"
#include <stack>
using std::stack;

class HistoryManager
{
public:
	HistoryManager();
	~HistoryManager();

	void Execute(iCommand* command);

	void Undo();
	void Redo();

	const iCommand & GetNextUndo() const;
	const iCommand & GetNextRedo() const;

	unsigned int GetNumUndo() const;
	unsigned int GetNumRedo() const;

	void ClearAll();

private:
	HistoryManager(const HistoryManager &copy);
	HistoryManager operator=(const HistoryManager &rhs);

	stack<iCommand*> m_undoStack;
	stack<iCommand*> m_redoStack;
};