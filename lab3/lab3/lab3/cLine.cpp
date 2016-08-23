#include "cLine.h"
#include "Drawing.h"
#include "cPoint.h"
#include <Windows.h>


/**************************************************************
*	    Purpose:  Default constructor.
*                 
*         Entry:  None.
*
*          Exit:  Start and stop points defaulted to (0,0)
****************************************************************/
cLine::cLine()
	: m_startPoint(cPoint(0,0)),
	m_stopPoint(cPoint(0,0))
{
	
}


/**************************************************************
*	    Purpose:  4-arg constructor.
*                 
*         Entry:  long startX: Start point's x value.
*                 long startY: Start point's y value.
*                 long stopX: Stop point's x value.
*                 long stopY: Stop point's y value.
*
*          Exit:  Line set with given values.
****************************************************************/
cLine::cLine(long startX, long startY, long stopX, long stopY)
	: m_startPoint(cPoint(startX, startY)),
	m_stopPoint(cPoint(stopX, stopY))
{
	
}


/**************************************************************
*	    Purpose:  Destructor.
*                 
*         Entry:  None.
*
*          Exit:  None.
****************************************************************/
cLine::~cLine()
{

}


/**************************************************************
*	    Purpose:  Copy constructor.
*                 
*         Entry:  const cLine &copy: The line to copy from.
*
*          Exit:  Line has the same values as the copy.
****************************************************************/
cLine::cLine(const cLine &copy)
	: m_startPoint(copy.m_startPoint),
	m_stopPoint(copy.m_stopPoint)
{

}


/**************************************************************
*	    Purpose:  Assignment operator.
*                 
*         Entry:  const cLine &rhs: The line to assign from.
*
*          Exit:  (cLine &) Returns the line after assigning from rhs.
****************************************************************/
cLine & cLine::operator=(const cLine &rhs)
{
	m_startPoint = rhs.m_startPoint;
	m_stopPoint = rhs.m_stopPoint;
	return *this;
}


/**************************************************************
*	    Purpose:  Sets starting point for line.
*                 
*         Entry:  long x: x value for starting point.
*                 long y: y value for starting point.
*
*          Exit:  Starting point is set.
****************************************************************/
void cLine::setStart(long x, long y)
{
	m_startPoint.set(x, y);
}


/**************************************************************
*	    Purpose:  Sets stopping point for line.
*                 
*         Entry:  long x: x value for stopping point.
*                 long y: y value for stopping point.
*
*          Exit:  Stopping point is set.
****************************************************************/
void cLine::setStop(long x, long y)
{
	m_stopPoint.set(x, y);
}


/**************************************************************
*	    Purpose:  Draws the line on the console.
*                 
*         Entry:  None.
*
*          Exit:  The line has been drawn to the console.
****************************************************************/
void cLine::draw() const
{
	if(m_startPoint == m_stopPoint)
	{
		// the start point is equal to the end point => invalid line
		throw "Cannot draw a line that has same start and endpoint";
	}else if(m_startPoint.getX() == m_stopPoint.getX())
	{
		// same x coord => vertical
		draw_vLine(m_stopPoint.getY() - m_startPoint.getY() + 1, m_startPoint.getX(), m_startPoint.getY());
	}else if(m_startPoint.getY() == m_stopPoint.getY())
	{
		// same y coord => horizontal
		draw_hLine(m_stopPoint.getX() - m_startPoint.getX() + 1, m_startPoint.getX(), m_startPoint.getY());
	}
}
