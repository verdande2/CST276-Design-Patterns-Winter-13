#pragma once

class iCommand
{
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};