// drawing.cpp : A simple set of drawing functions by Jeremiah Tatro
// modified from code writter my Wes Balwin and Roger McElfresh.
//Code date 11/14/03
//Note this doesn't work in Linux yet, check back in a couple of weeks and I will 
//port it to both operating systems

#include "util.h"
#include <cassert>
#include <string>
using std::string;

#ifndef DRAWING_H
#define DRAWING_H

const unsigned char horiz_line = 'Ä';
const unsigned char vert_line  = '³';
const unsigned char ul_corner  = 'Ú';
const unsigned char ur_corner  = '¿';
const unsigned char ll_corner  = 'À';
const unsigned char lr_corner  = 'Ù';
const unsigned char horiz_lineDl = (char)205;
const unsigned char vert_lineDl  = (char)186;
const unsigned char ul_cornerDl  = (char)201;
const unsigned char ur_cornerDl  = (char)187;
const unsigned char ll_cornerDl  = (char)200;
const unsigned char lr_cornerDl  = (char)188;
const unsigned char vL_rightseg = (char)195;
const unsigned char vL_leftseg = (char)180;
const unsigned char vL_hL =(char) 197;
const unsigned char hL_bottomseg = (char)194;
const unsigned char hL_topseg = (char)193;

#if(defined(_WIN32))

class WINDOW_POINT{
	char x;//byte representing x  cannot > 255
	char y;//byte representing y  cannot > 255
	char point; //char value at (x,y)
	char fc; //foreground color at (x,y)
	char bc; //background color  (x,y)
public:
	int getX(){return (int)x;}
	int getY(){return (int)y;}
	int getFC(){return (int) fc;}
	int getBC(){return (int) bc;}
	char getChar(){return point;}
	void setX(int a){x=(a>255&&a<0)?0:(int)a;}
	void setY(int a){y=(a>255&&a<0)?0:(int)a;}
	void setPoint(WINDOW_POINT p)
	{x=p.x;y=p.y;point=p.point;fc=p.fc;bc=p.bc;/*setMag();*/}
	void setChar(char c=' '){ point = c;}
	void setFC(int f=0){fc=f;}
	void setBC(int b=15){bc=b;}
	friend ostream &operator << (ostream &out, WINDOW_POINT & p);

	WINDOW_POINT& operator = (WINDOW_POINT& p)
	{x=p.x;y=p.y;point=p.point;fc=p.fc;bc=p.bc;;return *this;}
	WINDOW_POINT(){x='\0';y='\0';point=' ';fc='\0';bc=(char)255;}
	WINDOW_POINT(const WINDOW_POINT& p)
	{x=p.x;y=p.y;point=p.point;fc=p.fc;bc=p.bc;}

};

class STRING_POINT{
public:
	WINDOW_POINT p;
	string s;
};

#define MAX  1921
class WINDOW{
public:
	WINDOW_POINT * pts; //max dims l*w = MAX
private:
	int xlength;
	int ydepth;
	int xPos;
	int yPos;
	bool sB;
	bool dB;
	int menuSize;

public:
	~WINDOW(){delete [] pts; pts = NULL;}
	WINDOW(WINDOW & p)
	{	
		xlength = p.xlength;
		ydepth = p.ydepth;
		xPos = p.xPos;
		yPos = p.yPos;
		pts = new WINDOW_POINT[p.getBufferSize()];//
		for(int i = 0; i < p.getBufferSize(); i++)
			pts[i] = p.pts[i];
		sB=p.sB;
		dB=p.dB;
		menuSize= p.menuSize;
	}
	WINDOW& operator = (WINDOW& p)
	{	
		xlength = p.xlength;
		ydepth = p.ydepth;
		xPos = p.xPos;
		yPos = p.yPos;
		sB=p.sB;
		dB=p.dB;
		menuSize= p.menuSize;
		//menuSize = p.menuSize;
		pts = new WINDOW_POINT[p.getBufferSize()];//
		for(int i = 0; i < p.getBufferSize(); i++)
			pts[i] = p.pts[i];
		return *this;

	}
	WINDOW& operator = (STRING_POINT & sp)
	{
		assert(sp.p.getX() < (xlength + xPos));
		assert(sp.p.getY() < (ydepth + yPos));
	}
	WINDOW()
	{
		sB = false;
		dB = false;
		xlength = 3;ydepth = 3;xPos = 0; yPos =0;
		menuSize = 0;
		pts = new WINDOW_POINT[9];//
	}
	void changeColor(int fc, int bc)
	{
		for(int i = 0; i < getBufferSize(); i++)
		{
			pts[i].setBC(bc);
			pts[i].setFC(fc);
		}
	}
	int getBufferSize()const{return xlength*ydepth;}

	bool enableSingleBorder(bool en)//set en to false to disable singleBorder
	{
		int i;
		if(!en || dB)
		{
			sB = false;
			return false;
		}
		else
		{	
			if(getBufferSize()== 1 || getBufferSize()==0
				|| xlength == 1 || ydepth == 1)
				return false; //dims arent big enough to draw a border
			else
			{
				pts[0].setChar((char)ul_corner);
				pts[xlength-1].setChar((char)ur_corner);
				pts[(ydepth-1)*(xlength)].setChar((char)ll_corner);
				pts[getBufferSize()-1].setChar((char)lr_corner);
				for(i = 1; i < (xlength -1); i++)
				{
					pts[i].setChar((char)horiz_line);
					pts[(ydepth-1)*(xlength) + i].setChar((char)horiz_line);
				}
				for(i = xlength; i < (ydepth-1)*(xlength);i+=xlength)
				{
					pts[i].setChar((char)vert_line);
					pts[i+xlength-1].setChar((char)vert_line);
				}
			}	
			return true;
		}
	}

	bool enableDoubleBorder(bool en)//set en to false to disable singleBorder
	{
		int i;
		if(!en || sB)
		{
			dB = false;
			return false;
		}
		else
		{	
			if(getBufferSize()== 1 || getBufferSize()==0
				|| xlength == 1 || ydepth == 1)
				return false; //dims arent big enough to draw a border
			else
			{
				pts[0].setChar((char)ul_cornerDl);
				pts[xlength-1].setChar((char)ur_cornerDl);
				pts[(ydepth-1)*(xlength)].setChar((char)ll_cornerDl);
				pts[getBufferSize()-1].setChar((char)lr_cornerDl);
				for( i = 1; i < (xlength -1); i++)
				{
					pts[i].setChar((char)horiz_lineDl);
					pts[(ydepth-1)*(xlength) + i].setChar((char)horiz_lineDl);
				}
				for( i = xlength; i < (ydepth-1)*(xlength);i+=xlength)
				{
					pts[i].setChar((char)vert_lineDl);
					pts[i+xlength-1].setChar((char)vert_lineDl);
				}
			}	
			return true;
		}
	}

	bool singleBorderEnabled(){ return sB;}

	bool doubleBorderEnabled(){ return dB;}

	void changePosition(int x = 0, int y =0)
	{
		assert(x>=0&& y >=0);
		assert(x+1+xlength < 255 && y + 1+ ydepth < 255);
		assert((x+1+xlength)*(y+1+ydepth)<MAX);
		int xdiff = x - xPos;
		int ydiff = y - yPos;
		xPos = x;
		yPos = y;
		for(int i = 0; i < getBufferSize();i++)
		{
			pts[i].setX(pts[i].getX() + xdiff);
			pts[i].setY(pts[i].getY() + ydiff);
		}
	}
	void setString(char c[], int slen = 0, int x = 0, int y= 0)
	{
		assert((x+1)*(y+1) <getBufferSize());
		assert((x+1)*(y+1) + slen <= getBufferSize());
		assert(x < xlength);
		assert(y < ydepth);
		for(int i=0; i < slen; i++)
		{
			pts[y*xlength + x + i].setChar(((isprint(c[i]))?c[i]:' '));
		}
	}
	void setString(string c, int x = 0, int y= 0)
	{
		assert((x+1)*(y+1) <getBufferSize());
		assert((x+1)*(y+1) + c.length() <= getBufferSize());
		assert(x < xlength);
		assert(y < ydepth);
		for(int i=0; i < c.length(); i++)
		{
			pts[y*xlength + x + i].setChar(((isprint(c[i]))?c[i]:' '));
		}
	}
	void setDims(int xpara=0, int ypara=0,int StartX=0, int StartY=0)
	{
		assert(xpara>=0&& ypara >=0);
		assert(xpara+StartX < 255 && ypara + StartY < 255);
		assert((xpara+StartX)*(ypara+StartY)<MAX);
		xlength= xpara;ydepth=ypara;
		xPos = StartX;
		yPos = StartY;
		delete [] pts;
		pts = new WINDOW_POINT[(xpara+1)*(ypara+1)];
		for(int i =0; i <xlength*ydepth;i++)
		{pts[i].setX(i%xlength+xPos);pts[i].setY(i/xlength+yPos);}
	}
	void setPoint(WINDOW_POINT & p, int x=0,int y =0)
	{ assert(x < xlength && y < ydepth); pts[y*xlength + x] = p;}
	friend ostream &operator << (ostream &out, WINDOW & w);

	WINDOW_POINT & getPoint(int xpara, int ypara)
	{assert(xpara*ypara<MAX); 
	assert(xpara < xlength && xpara>=0); 
	assert(ypara < ydepth && ypara >=0);
	return pts[ypara*xlength + xpara];}
	WINDOW_POINT & operator[](int index)
	{assert(index < getBufferSize());return pts[index];}
};
#undef MAX

class Terminal:public WINDOW{
private:
	int * INport;
	int * OUTport;
	int INsize;
	int OUTsize;
public:
	Terminal():WINDOW()
	{
		INport = new int[1];
		OUTport = new int[1];
		INsize = 1;
		OUTsize = 1;
	}
	int getINport(int i){ assert(i<INsize);return INport[i];}
	int getOUTport(int i){ assert(i<OUTsize);return OUTport[i];}
	void setINport(int i, int portNum){assert(i<INsize); INport[i]=portNum;}
	void setOUTport(int i, int portNum){assert(i<OUTsize); OUTport[i] = portNum;}
	void setInPortDim(int size){ 
		assert(size>0);
		int j;
		int * temp = new int[INsize];
		for(j = 0; j<INsize;j++)
			temp[j]=INport[j];
		delete [] INport; 
		INport = new int[size];
		for(j = 0; j<size;j++)
			if(j<INsize)
				INport[j]= temp[j];
			else
				INport[j]=-1;//uninitialized;
		INsize = size;
		delete []temp;
		temp = NULL;
	}
	void setOUTPortDim(int size){ 
		int j;
		assert(size>0);
		int * temp = new int[OUTsize];
		for( j = 0; j<OUTsize;j++)
			temp[j]=OUTport[j];
		delete [] OUTport; 
		OUTport = new int[size];
		for( j = 0; j<size;j++)
			if(j<OUTsize)
				OUTport[j]= temp[j];
			else
				OUTport[j]=-1;//uninitialized;
		OUTsize = size;
		delete []temp;
		temp = NULL;
	}
};

struct Wire{
	int INterminal;	//keeps terminal whose inport the wire is connected to
	int INport;		//keeps port # of INterminal
	int OUTterminal;//keeps terminal whose outport the wire is connected to
	int OUTport;	//keeps port of of INterminal
	Wire(){INterminal=-1;INport=-1;OUTterminal=-1;OUTport=-1;}
};




void clrwin(WINDOW&w,int bc = 0, int fc = 15);//default background black


#endif
void color(int backgroundc=0,int fcregroundc=15);

void getscreendim(int &x, int &y);

void getcursorposition(int&x,int&y);

void clrscr();


void gotoxy(int x, int y);

void draw_hLine(int length, int x = 0, int y = 0);

void draw_vLine(int length, int x = 0, int y = 0);

void draw_Rect(int x, int y, int l, int w);

void draw_hLineDLOL(int length, int x, int y);//overlap

void draw_vLineDLOL(int length, int x, int y);

#endif