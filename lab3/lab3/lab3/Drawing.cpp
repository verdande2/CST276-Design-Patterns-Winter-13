// drawing.cpp : A simple set of drawing functions by Jeremiah Tatro
// modified from code writter my Wes Balwin and Roger McElfresh.
//Code date 11/14/03
#include"Drawing.h"
#if (defined(_WIN32)) 
#include <windows.h>
void color(int b,int f) 
{ 

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((b*16)+f)); 

}

void clrwin(WINDOW&w, int bc, int fc)
{
	for(int i = 0; i < w.getBufferSize(); i++)
	{
		w[i].setChar();
		w[i].setBC(bc);
		w[i].setFC(fc);
	}//note this does not clear the screen just the buffer
}

void clrscr()
{
	COORD coordScreen = { 0, 0 }; 
	DWORD cCharsWritten; 
	CONSOLE_SCREEN_BUFFER_INFO csbi; 
	DWORD dwConSize; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	POINT screensize;
  
	GetConsoleScreenBufferInfo(hConsole, &csbi); 
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y; 
	screensize.x = csbi.dwSize.X;
	screensize.y = csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten); 
	GetConsoleScreenBufferInfo(hConsole, &csbi); 
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten); 
	SetConsoleCursorPosition(hConsole, coordScreen); 
}

void getscreendim(int &x, int &y){

	CONSOLE_SCREEN_BUFFER_INFO csbi; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	x = csbi.dwSize.X;
	y = csbi.dwSize.Y;
	
}

void getcursorposition(int&x,int&y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	x = csbi.dwCursorPosition.X; y = csbi.dwCursorPosition.Y;
}

void gotoxy(int x, int y)
{
	COORD point;
	CONSOLE_SCREEN_BUFFER_INFO csbi; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
  
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	if((x < 0 || x > csbi.dwSize.X) || (y < 0 || y > csbi.dwSize.Y))
		return;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

ostream &operator << (ostream &out, WINDOW_POINT & p)
{ 
	color(p.getBC(),p.getFC());
	gotoxy(p.getX(),p.getY());
	out << p.getChar(); 
	return out;
}

ostream &operator << (ostream &out, WINDOW & w)
{ 
	for(int i = 0; i < w.getBufferSize(); i++)
	{
		out << w[i];
	}
	return out;
}
void draw_hLine(int length, int x, int y)
{

	int i = 0;

	if(x > 0 || y > 0)
	gotoxy(x, y);

	for(i = 0; i < length; i++)
	{
		cout << horiz_line;
	}
	return;
}

void draw_vLine(int length, int x, int y)
{
	int i = 0;

	if(x > 0 || y > 0)
	gotoxy(x, y);

	for(i = 0; i < length; i++)
	{
		gotoxy(x, y + i);
			cout << vert_line;
	}
	return;
}

void draw_Rect(int x, int y, int l, int w)
{
	COORD point;
	CONSOLE_SCREEN_BUFFER_INFO csbi; 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	point.X = csbi.dwCursorPosition.X; point.Y = csbi.dwCursorPosition.Y;

	
	gotoxy(x, y);
	cout << ul_corner;
	draw_hLine(w - 2);
	cout << ur_corner;
	gotoxy(x, y + 1);
	draw_vLine(l - 2, x, y + 1);
	gotoxy(x, y + (l - 1));
	cout << ll_corner;
	draw_hLine(w - 2, x + 1, y + (l - 1));
	cout << lr_corner;
	draw_vLine(l - 2, x + w - 1, y + 1);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
	return;
}
void draw_hLineDLOL(int length, int x, int y)//overlap
{

	int i = 0;

	if(x > 0 || y > 0)
	gotoxy(x, y);
	cout << (char) 204; //¦
	for(i = 1; i < length-1; i++)
	{
		cout << horiz_lineDl;
	}
	cout << (char) 185; //¦
	return;
}

void draw_vLineDLOL(int length, int x, int y)
{
	int i = 0;

	if(x > 0 || y > 0)
	gotoxy(x, y);
	cout << (char)203;//-
	for(i = 1; i < length - 1; i++)
	{
		gotoxy(x, y + i);
			cout << vert_lineDl;
	}
	gotoxy(x, y + length-1);
	cout <<(char)202;//-
	return;
}

#endif