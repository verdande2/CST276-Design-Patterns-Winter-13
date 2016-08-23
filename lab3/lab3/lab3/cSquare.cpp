#include "cSquare.h"
#include "Drawing.h"

/**************************************************************
*	    Purpose:  Default constructor.
*                 
*         Entry:  None.
*
*          Exit:  Set top left point to (0,0) and side length to 2.
****************************************************************/
cSquare::cSquare()
	: m_topLeft(cPoint(0,0)),
	m_sideLength(2)
{

}


/**************************************************************
*	    Purpose:  3-arg constructor
*                 
*         Entry:  long x: x value for top left point
*                 long y: y value for top left point
*                 long sideLength: side length for square
*
*          Exit:  Square constructed with given x, y, sideLength.
****************************************************************/
cSquare::cSquare(long x, long y, long sideLength)
	: m_topLeft(cPoint(x, y)),
	m_sideLength(sideLength)
{

}


/**************************************************************
*	    Purpose:  Destructor.
*                 
*         Entry:  None.
*
*          Exit:  None.
****************************************************************/
cSquare::~cSquare()
{

}


/**************************************************************
*	    Purpose:  Copy constructor.
*                 
*         Entry:  const cSquare &copy: Square to copy from.
*
*          Exit:  Square now has same values as copy.
****************************************************************/
cSquare::cSquare(const cSquare &copy)
	: m_topLeft(copy.m_topLeft),
	m_sideLength(copy.m_sideLength)
{

}


/**************************************************************
*	    Purpose:  Assignment operator.
*                 
*         Entry:  const cSquare &rhs: Square to assign from.
*
*          Exit:  (cSquare &) Square has been assigned same values 
*                 as rhs.
****************************************************************/
cSquare & cSquare::operator=(const cSquare &rhs)
{
	m_topLeft.setX(rhs.m_topLeft.getX());
	m_topLeft.setY(rhs.m_topLeft.getY());
	return *this;
}


/**************************************************************
*	    Purpose:  Sets top left corner point for square
*                 
*         Entry:  long x: x value for top left point.
*                 long y: y value for top left point.
*
*          Exit:  Top left point is set.
****************************************************************/
void cSquare::setTopLeftCorner(long x, long y)
{
	m_topLeft.set(x, y);
}


/**************************************************************
*	    Purpose:  Sets the side length of the square.
*                 
*         Entry:  long s: side length.
*
*          Exit:  Side length is set.
****************************************************************/
void cSquare::setSideLength(long s)
{
	m_sideLength = s;
}


/**************************************************************
*	    Purpose:  Draws the square on the console.
*                 
*         Entry:  None.
*
*          Exit:  Square is drawn on the console.
****************************************************************/
void cSquare::draw() const
{
	draw_Rect(m_topLeft.getX(), m_topLeft.getY(), m_sideLength, m_sideLength);
}
