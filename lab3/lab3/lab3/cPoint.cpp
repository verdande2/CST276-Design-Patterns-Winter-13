#include "cPoint.h"
#include "Drawing.h"

/**************************************************************
*	    Purpose:  Default constructor.
*                 
*         Entry:  None.
*
*          Exit:  Constructs point set to (0,0)
****************************************************************/
cPoint::cPoint()
	: m_x(0),
	m_y(0)
{

}


/**************************************************************
*	    Purpose:  Destructor.
*                 
*         Entry:  None.
*
*          Exit:  None.
****************************************************************/
cPoint::~cPoint()
{

}


/**************************************************************
*	    Purpose:  2-arg constructor.
*                 
*         Entry:  long x: x coordinate of the point
*                 long y: y coordinate of the point
*
*          Exit:  Constructs point with given coordinates.
****************************************************************/
cPoint::cPoint(long x, long y)
	: m_x(x),
	m_y(y)
{

}


/**************************************************************
*	    Purpose:  Copy constructor.
*                 
*         Entry:  const cPoint& copy: The point to copy from.
*
*          Exit:  Point has same values as copy.
****************************************************************/
cPoint::cPoint(const cPoint &copy)
	: m_x(copy.m_x),
	m_y(copy.m_y)
{

}


/**************************************************************
*	    Purpose:  Assignment operator.
*                 
*         Entry:  const cPoint &rhs: The point to assign from.
*
*          Exit:  Point has same values as rhs.
****************************************************************/
cPoint & cPoint::operator=(const cPoint &rhs)
{
	m_x = rhs.m_x;
	m_y = rhs.m_y;
	return *this;
}


/**************************************************************
*	    Purpose:  Comparison operator.
*                 
*         Entry:  const cPoint &right: The other point to compare to.
*
*          Exit:  (bool) representing if the points are the same.
****************************************************************/
bool cPoint::operator==(const cPoint &right) const
{
	return (m_x == right.m_x && m_y == right.m_y);
}


/**************************************************************
*	    Purpose:  Setter for x value.
*                 
*         Entry:  long x: x value
*
*          Exit:  Set x value.
****************************************************************/
void cPoint::setX(long x)
{
	m_x = x;
}


/**************************************************************
*	    Purpose:  Setter for y value
*                 
*         Entry:  long y: y value
*
*          Exit:  Set y value.
****************************************************************/
void cPoint::setY(long y)
{
	m_y = y;
}


/**************************************************************
*	    Purpose:  Setter for x and y.
*                 
*         Entry:  long x: x value
*                 long y: y value
*
*          Exit:  Set x and y values.
****************************************************************/
void cPoint::set(long x, long y)
{
	m_x = x;
	m_y = y;
}


/**************************************************************
*	    Purpose:  Getter for x value.
*                 
*         Entry:  None.
*
*          Exit:  (long) returns x.
****************************************************************/
long cPoint::getX() const
{
	return m_x;
}


/**************************************************************
*	    Purpose:  Getter for y value.
*                 
*         Entry:  None.
*
*          Exit:  (long) returns y.
****************************************************************/
long cPoint::getY() const
{
	return m_y;
}


/**************************************************************
*	    Purpose:  Getter for x and y
*                 
*         Entry:  None.
*
*          Exit:  (POINT) returns POINT struct with x, y.
****************************************************************/
POINT cPoint::getWindowsPoint() const
{
	POINT p;
	p.x = m_x;
	p.y = m_y;
	return p;
}