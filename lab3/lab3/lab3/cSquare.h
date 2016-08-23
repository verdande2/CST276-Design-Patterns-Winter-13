/************************************************************************
* Class: cSquare
*
* Constructors:	
*	cSquare()
*      Default constructor. Defaults to setting top left point to (0,0).
*	cSquare(long x, long y, long sideLength)
*      2-arg constructor. Sets top left point and side length.
*   cSquare(const cSquare &copy)
*       Copy constructor.
*
* Mutators:
*	void setTopLeftCorner(long x, long y)
*       Sets the square's top left corner point.
*	void setSideLength(long s)
*       Sets the square's side length.
*
* Methods:		
*	cSquare & operator=(const cSquare &rhs)
*       Assignment operator
*   void draw() const
*       Draws the square to the console.
*************************************************************************/
#ifndef cSquare_h
#define cSquare_h
#include "cPoint.h"

class cSquare
{
public:
	cSquare();
	~cSquare();
	cSquare(long x, long y, long sideLength);
	cSquare(const cSquare &copy);
	cSquare & operator=(const cSquare &rhs);

	void setTopLeftCorner(long x, long y);
	void setSideLength(long s);

	void draw() const;
private:
	unsigned int m_sideLength;
	cPoint m_topLeft;
};
#endif