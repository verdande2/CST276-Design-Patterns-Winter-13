/************************************************************************
* Class: cPoint
*
* Constructors:	
*	cPoint()
*      Default constructor. Defaults to setting start/stop points to (0,0).
*	cPoint(long x, long y)
*      2-arg constructor. Sets point's x and y to given values.
*   cPoint(const cPoint &copy)
*       Copy constructor.
*
* Mutators:
*	void setX(long x)
*       Sets the point's x value.
*   void setY(long y)
*       Sets the point's y value.
*   void set(long x, long y)
*       Sets the point's x and y values.
*
* Methods:		
*	cPoint & operator=(const cPoint &rhs)
*       Assignment operator.
*	bool operator==(const cPoint &right) const
*       Comparison operator.
*   long getX() const
*       Returns the point's x value.
*   long getY() const
*       Returns the point's y value.
*   POINT getWindowsPoint() const
*       Returns a windows.h POINT struct representing the point.
*************************************************************************/
#ifndef cPoint_h
#define cPoint_h
#include <windows.h>

class cPoint
{
public:
	cPoint();
	~cPoint();
	cPoint(long x, long y);
	cPoint(const cPoint &copy);

	cPoint & operator=(const cPoint &rhs);
	bool operator==(const cPoint &right) const;

	void setX(long x);
	void setY(long y);
	void set(long x, long y);

	long getX() const;
	long getY() const;
	POINT getWindowsPoint() const;
private:
	long m_x;
	long m_y;
};
#endif