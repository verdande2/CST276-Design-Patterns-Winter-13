/************************************************************************
* Class: cLine
*
* Constructors:	
*	cLine()
*      Default constructor. Defaults to setting start/stop points to 
*      cPoint()'s default constructor
*	cLine(long startX, long startY, long stopX, long stopY)
*      4-arg constructor sets starting and stopping points for the line.
*   cLine(const cLine &copy)
*       Copy constructor.
*
* Mutators:
*	void setStart(long x, long y)
*       Sets the starting point for the line.
*   void setStop(long x, long y)
*       Sets the stopping point for the line.
*
* Methods:		
*	cLine & operator=(const cLine &rhs)
*       Assignment operator
*   void draw() const
*       Draws the line to the console.
*************************************************************************/
#ifndef cLine_h
#define cLine_h
#include "cPoint.h"

class cLine
{
public:
	cLine();
	~cLine();
	cLine(long startX, long startY, long stopX, long stopY);
	cLine(const cLine &copy);
	cLine & operator=(const cLine &rhs);

	void setStart(long x, long y);
	void setStop(long x, long y);

	void draw() const;
private:
	cPoint m_startPoint;
	cPoint m_stopPoint;
};
#endif