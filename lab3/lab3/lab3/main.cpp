/***********************************************************
* Author:					Andrew Sparkes
* Date Created:				2-7-13
* Last Modification Date:	2-12-13
* Lab Number:				CST 276 Lab 3
* Filename:					main.cpp
*
* Overview:
*	This program will demo my adapter to Drawing.h.
*
* Input:
*	The program requires no input.
*
* Output:
*	The program outputs two lines and two square shapes to 
*   the console window. It demos usage of an adapter class 
*   to drawing.h.
************************************************************/
#include <iostream>
using std::cout;
using std::endl;

#include "cLine.h"
#include "cSquare.h"

int main()
{
	// output row and column numbers to help with positioning
	for(int i = 0; i < 80; ++i)
	{
		cout << i % 10;
	}
	for(int i = 1; i < 25; ++i)
	{
		cout << i % 10;

		// don't output an endl on the last row,
		// as it causes the console to bump down a line
		if(i != 24)
		{
			cout << endl;
		}
	}
	
	// draw a line
	cLine vline(1, 1, 1, 4);
	vline.draw();

	// draw another line
	cLine hline(10, 10, 19, 10);
	hline.draw();

	// draw a square
	cSquare square1(40, 20, 3);
	square1.draw();

	// draw another square
	cSquare square2(60, 5, 6);
	square2.draw();


	system("pause");
	return 0;
}