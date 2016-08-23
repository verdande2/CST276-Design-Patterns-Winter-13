/* Programmer  : Jeremiah Tatro
   Date			: 3/3/2004
   Description  :  Runs a number game allowing for the 
					user to implement different method so
					solve the puzzle.
					*/

#include "util.h"
#include "Drawing.h"
//int getch();
#include <list>
using std::list;

const int COL = 7, ROW = 6;
const int EMPTY = 0, RD = '1', BL = '2';
const int BRED = 12, BBLUE=9, BYELLOW=14, BBLACK = 0;

int DropSelection(int c)//color currently displayed
{
	int i;
	static k = 0;
	bool ArrowPressed;
	static WINDOW red,blue,black;
	static bool doOnce = true;
	if(doOnce)
	{
		red.setDims(3,3,26,1);
		blue.setDims(3,3,26,1);
		black.setDims(3,3,26,1);
		black.enableSingleBorder(true);
		red.enableSingleBorder(true);
		blue.enableSingleBorder(true);
		black.changeColor(0,0);
		red.changeColor(BRED,BRED);
		blue.changeColor(BBLUE,BBLUE);
		doOnce = false;
	}
	cout << ((c==RD)?red:blue);
	while((i=getch())!= 13)//while not pressing escape
	{	
	
		switch(((ArrowPressed =(i== 0 || i == 0xe0))?getch():i))
		{
		
		case 0x36: //num lock might be off so use 6
			if(ArrowPressed)
				break;//pressed wrong key
		case 0x4d: //rightarrow
			if(k<6)
			{
				cout << black;
				k++;
				red.changePosition(26 + k*4,1);
				blue.changePosition(26 + k*4,1);
				black.changePosition(26 + k*4,1);
				cout << ((c==RD)?red:blue);
			}
			
			break;

		case 0x32: //num lock might be off so use 2
			if(ArrowPressed)
				break;//pressed wrong key
		case 0x50://down arrow
			//color();
			return k;
			break;
			
		case 0x34://num lock might be off so use 4
			if(ArrowPressed)
				break;//pressed wrong key
		case 0x4b://left arrow
			if(k>0)
			{
				cout << black;
				k--;
				red.changePosition(26 + k*4,1);
				blue.changePosition(26 + k*4,1);
				black.changePosition(26 + k*4,1);
				cout << ((c==RD)?red:blue);
			}
			break;
		case 0x3b:
			;//F1
		}
	}
	color();
	return k;
}

void displayGrid()
{
	
	//12 = bright red, 9=blue, 8 = gray , 7 = white-gray, 6 = yellow-green,
	//5=purple, 4 = red, 3 = paisley, 2 = green, dark=purple
	WINDOW background;
	background.setDims(29,25,25,5);
	background.changeColor(BBLACK,BYELLOW);
	background.enableDoubleBorder(true);
	
	cout << background;
	int i = 29;
	for(; i < 50; i+=4)
		draw_vLineDLOL(25, i, 5);
	int j = 9;
	for( ;j < 28 ; j+=4)
		draw_hLineDLOL(29, 25,  j);//overlap
	for(int x = 29; x < 50; x+=4)
		for(int y = 9; y < 26 ; y+=4)
		{
			gotoxy(x,y);
			cout << (char)206; //+
		}
}
void displayTile(bool isRed,int column, int rank)
{
	static WINDOW red,blue;
	static bool doOnce = true;
	if(doOnce)
	{
		red.setDims(3,3,0,0);
		blue.setDims(3,3,0,0);
		red.enableSingleBorder(true);
		blue.enableSingleBorder(true);
		red.changeColor(BRED,BRED);
		blue.changeColor(BBLUE,BBLUE);
		doOnce = false;
	}
	assert(rank >= 0);
	assert(rank < 6);
	assert(column >=0);
	assert(column < 7);
	rank = 5 - rank;
	int x = 26 + column*4;
	int y = 6 + rank*4;
	if(isRed)
		red.changePosition(x,y);
	else
		blue.changePosition(x,y);
	cout << ((isRed)?red:blue);
}


bool gridNotFull(string grid[])
{
	for(int i = 0; i < 6; i++)
		if(grid[i].find("0")!=-1)
			return true;
	return false;
}
int whoWon(string grid[],int size)
{
	for(int i = 0; i < size;i++)
		if(grid[i].size()>3)
		{
			if(grid[i].find("1111")!=-1)
				return 1;
			else if(grid[i].find("2222")!=-1)
				return 2;
		}
	return 0;
}

int displayMenu(string menuItems[], int size)
{
	int i, k = 0, maxStringLength = 0;
	bool ArrowPressed;
	char buff2[2];
	buff2[1] = '\0';
	assert(size >= 0 && size <=24);
	WINDOW selections[10];
	for(i = 0; i < size ; i++)
		if(menuItems[i].length()> maxStringLength)
			maxStringLength = menuItems[i].length();
	for(i = 0; i < size ; i++)
	{
		buff2[0] = i+'1';
		selections[i].setDims(menuItems[i].length()+2,1,(80-maxStringLength)/2,(24 - size)/2 + i);
		selections[i].setString(buff2+menuItems[i],0,0);
		cout << selections[i];
	}
	selections[0].changeColor(0,11);
	cout << selections[0];
	while((i=getch())!= 13)//while not pressing escape
	{	
	
		switch(((ArrowPressed =(i== 0 || i == 0xe0))?getch():i))
		{
		case 0x48: //uparrow
			if(k>0)
			{
				selections[k].changeColor(15,0);
				cout << selections[k];
				selections[--k].changeColor(0,11);
				cout << selections[k];
			}
			break;
		case 0x50:
			if(k<size-1)
			{
				selections[k].changeColor(15,0);
				cout << selections[k];
				selections[++k].changeColor(0,11);
				cout << selections[k];
			}
			break;
		default:
			if(!ArrowPressed && isdigit(i))
			{
				if(i-'0'<=size&&i-'0'>0)
				{
					selections[k].changeColor(15,0);
					cout << selections[k];
					selections[k=i-'1'].changeColor(0,11);
					cout << selections[k];
				}
			}

		}
	}
	color();
	return k;
}

struct moves{
	char movelist[42];
	string grid[COL];//initialize grid to empty
	string invertgrid[ROW];
	string rightdiag[ROW];
	string leftdiag[ROW];
	int lastmove;
	int scoreArray[69];
	moves():lastmove(0)
	{	
		int i;
		for( i = 0; i < 42; i++)
			movelist[i] = '9';
		for(i=0;i<COL;i++)
			grid[i] = "000000";
		for(i=0;i<ROW;i++)
			invertgrid[i] = "0000000";
		for(i=0;i<69;i++)
			scoreArray[i]=0;
		rightdiag[0] =  "0000";  rightdiag[5] =  "0000";  leftdiag[0] =  "0000";  leftdiag[5] =  "0000";		
		rightdiag[1] =  "00000";  rightdiag[4] =  "00000";  leftdiag[1] =  "00000";  leftdiag[4] =  "00000";		
		rightdiag[2] =  "000000";  rightdiag[3] =  "000000";  leftdiag[2] =  "000000";  leftdiag[3] =  "000000";
	}
};
int getScore(moves & m,int depth,int i, int j)
{
	static string winString = "0000";
	static char winningStates[69][4] = {//bit mapped i,j
		{0x00,0x01,0x02,0x03},{0x01,0x02,0x03,0x04},//0,1
		{0x02,0x03,0x04,0x05},{0x10,0x11,0x12,0x13},//2,3
		{0x11,0x12,0x13,0x14},{0x12,0x13,0x14,0x15},
		{0x20,0x21,0x22,0x23},{0x21,0x22,0x23,0x24},
		{0x22,0x23,0x24,0x25},{0x30,0x31,0x32,0x33},
		{0x31,0x32,0x33,0x34},{0x32,0x33,0x34,0x35},
		{0x40,0x41,0x42,0x43},{0x41,0x42,0x43,0x44},
		{0x42,0x43,0x44,0x45},{0x50,0x51,0x52,0x53},
		{0x51,0x52,0x53,0x54},{0x52,0x53,0x54,0x55},
		{0x60,0x61,0x62,0x63},{0x60,0x61,0x62,0x63},
		{0x60,0x61,0x62,0x63},						//horizontal    20
		{0x00,0x10,0x20,0x30},{0x10,0x20,0x30,0x40},
		{0x20,0x30,0x40,0x50},{0x30,0x40,0x50,0x60},
		{0x01,0x11,0x21,0x31},{0x11,0x21,0x31,0x41},
		{0x21,0x31,0x41,0x51},{0x31,0x41,0x51,0x61},
		{0x02,0x12,0x22,0x32},{0x12,0x22,0x32,0x42},//30
		{0x22,0x32,0x42,0x52},{0x32,0x42,0x52,0x62},
		{0x03,0x13,0x23,0x33},{0x13,0x23,0x33,0x43},
		{0x23,0x33,0x43,0x53},{0x33,0x43,0x53,0x63},
		{0x04,0x14,0x24,0x34},{0x14,0x24,0x34,0x44},
		{0x24,0x34,0x44,0x54},{0x34,0x44,0x54,0x64},//40
		{0x05,0x15,0x25,0x35},{0x15,0x25,0x35,0x45},
		{0x25,0x35,0x45,0x55},{0x35,0x45,0x55,0x65},//vertical
		{0x02,0x13,0x24,0x35},{0x01,0x12,0x23,0x34},
		{0x12,0x23,0x34,0x45},{0x00,0x11,0x22,0x33},
		{0x11,0x22,0x33,0x44},{0x22,0x33,0x44,0x55},//50
		{0x10,0x21,0x32,0x43},{0x21,0x32,0x43,0x54},
		{0x32,0x43,0x54,0x65},{0x20,0x31,0x42,0x53},
		{0x31,0x42,0x53,0x64},{0x30,0x41,0x52,0x63},//right diags
		{0x30,0x21,0x12,0x03},{0x40,0x31,0x22,0x13},
		{0x31,0x22,0x13,0x04},{0x50,0x41,0x32,0x23},//60
		{0x41,0x32,0x23,0x14},{0x32,0x23,0x14,0x05},
		{0x60,0x51,0x42,0x33},{0x51,0x42,0x33,0x24},
		{0x42,0x33,0x24,0x15},{0x61,0x52,0x43,0x34},
		{0x52,0x43,0x34,0x25},{0x62,0x53,0x44,0x35}};//leftdiags

		static string s[69];
		int k,n[4],p[4],q,r;
		static bool doOnce = true;
		static string mapToStates[COL][ROW];
		if(doOnce)
		{
			for(k = 0; k<69; k++)
				s[k]= '0'+ k;
			mapToStates[0][0] =  s[0]+s[21]+s[48] ;			
			mapToStates[0][1] =  s[0]+s[1]+s[25]+s[46];
			mapToStates[0][2] =  s[0]+s[1]+s[2]+s[29]+s[45];	
			mapToStates[0][3] =  s[0]+s[1]+s[2]+s[33]+s[57];
			mapToStates[0][4] =  s[1]+s[2]+s[37]+s[59];			
			mapToStates[0][5] =  s[2]+s[41]+s[62];
			mapToStates[1][0] =  s[3]+s[21]+s[22]+s[51];		
			mapToStates[1][1] =  s[3]+s[4]+s[25]+s[26]+s[48]+s[49];	
			mapToStates[1][2] =  s[3]+s[4]+s[5]+s[29]+s[30]+s[46]+s[47]+s[57];	
			mapToStates[1][3] =  s[3]+s[4]+s[5]+s[33]+s[34]+s[45]+s[58]+s[59];	
			mapToStates[1][4] =  s[4]+s[5]+s[37]+s[38]+s[61]+s[62];	
			mapToStates[1][5] =  s[5]+s[41]+s[42]+s[65];		
			mapToStates[2][0] =  s[6]+s[21]+s[22]+s[23]+s[54];	
			mapToStates[2][1] =  s[6]+s[7]+s[25]+s[26]+s[27]+s[51]+s[52]+s[57];
			mapToStates[2][2] =  s[6]+s[7]+s[8]+s[29]+s[30]+s[31]+s[48]+s[49]+s[50]+s[58]+s[59];	
			mapToStates[2][3] =  s[6]+s[7]+s[8]+s[33]+s[34]+s[35]+s[46]+s[47]+s[60]+s[61]+s[62];	
			mapToStates[2][4] =  s[7]+s[8]+s[37]+s[38]+s[39]+s[45]+s[64]+s[65];	
			mapToStates[2][5] =  s[8]+s[41]+s[42]+s[43]+s[67];	
			mapToStates[3][0] =  s[9]+s[21]+s[22]+s[23]+s[24]+s[56]+s[57];
			mapToStates[3][1] =  s[9]+s[10]+s[25]+s[26]+s[27]+s[28]+s[54]+s[55]+s[58]+s[59];
			mapToStates[3][2] =  s[9]+s[10]+s[11]+s[29]+s[30]+s[31]+s[32]+s[51]+s[52]+s[53]+s[60]+s[61]+s[62];
            mapToStates[3][3] =  s[9]+s[10]+s[11]+s[33]+s[34]+s[35]+s[36]+s[48]+s[49]+s[50]+s[63]+s[64]+s[65];
			mapToStates[3][4] =  s[10]+s[11]+s[37]+s[38]+s[39]+s[40]+s[46]+s[47]+s[66]+s[67];
			mapToStates[3][5] =  s[11]+s[41]+s[42]+s[43]+s[44]+s[45]+s[68];	
			mapToStates[4][0] =  s[12]+s[22]+s[23]+s[24]+s[58];
			mapToStates[4][1] =  s[12]+s[13]+s[26]+s[27]+s[28]+s[56]+s[60]+s[61];
			mapToStates[4][2] =  s[12]+s[13]+s[14]+s[30]+s[31]+s[32]+s[54]+s[55]+s[63]+s[64]+s[65];
			mapToStates[4][3] =  s[12]+s[13]+s[14]+s[34]+s[35]+s[36]+s[51]+s[52]+s[53]+s[66]+s[67];	
			mapToStates[4][4] =  s[13]+s[14]+s[38]+s[39]+s[40]+s[49]+s[50]+s[68];
			mapToStates[4][5] =  s[14]+s[42]+s[43]+s[44]+s[47];	mapToStates[5][0] =  s[15]+s[23]+s[24]+s[60];
			mapToStates[5][1] =  s[15]+s[16]+s[27]+s[28]+s[63]+s[64];	
			mapToStates[5][2] =  s[15]+s[16]+s[17]+s[31]+s[32]+s[56]+s[66]+s[67];	
			mapToStates[5][3] =  s[15]+s[16]+s[17]+s[35]+s[36]+s[54]+s[55]+s[68];	
			mapToStates[5][4] =  s[16]+s[17]+s[39]+s[40]+s[52]+s[53];	
			mapToStates[5][5] =  s[17]+s[43]+s[44]+s[50];		
			mapToStates[6][0] =  s[18]+s[24]+s[63];
			mapToStates[6][1] =  s[18]+s[19]+s[28]+s[66];		
			mapToStates[6][2] =  s[18]+s[19]+s[20]+s[32]+s[68];	
			mapToStates[6][3] =  s[18]+s[19]+s[20]+s[36]+s[56];	
			mapToStates[6][4] =  s[19]+s[20]+s[40]+s[55];
			mapToStates[6][5] =  s[20]+s[44]+s[53];
			
			doOnce = false;
		}
		for(k=0;k<mapToStates[i][j].size();k++)
		{	
			r =(int)mapToStates[i][j][k] - '0';
			for(q=0;q<4;q++)
			{
				n[q] = winningStates[r][q];
				winString[q]=m.grid[n[q] & 15][n[q]>>4];
				//p[q] = n[q] & 15;
				//n[q] = n[q] >> 4;
			}
			if(winString.find("1")!=-1&&winString.find("2")!=-1)
				m.scoreArray[r] = 0;
			else if(winString.find("1111")!=-1)
				m.scoreArray[r] = 999 - depth;
			else if(winString.find("2222")!=-1)
				m.scoreArray[r] = -999 + depth;
			else if(winString.find("1110")!=-1)
				m.scoreArray[r] = 100;
			else if(winString.find("0111")!=-1)
				m.scoreArray[r] = -100;
			else if(winString.find("2220")!=-1)
				m.scoreArray[r] = 100;
			else if(winString.find("0222")!=-1)
				m.scoreArray[r] = -100;
			else if(winString.find("1100")!=-1)
				m.scoreArray[r] = 50;
			else if(winString.find("0011")!=-1)
				m.scoreArray[r] = 50;
			else if(winString.find("0110")!=-1)
				m.scoreArray[r] = 100;
			else if(winString.find("0101")!=-1)
				m.scoreArray[r] = 50;
			else if(winString.find("1010")!=-1)
				m.scoreArray[r] = 50;
			else if(winString.find("1001")!=-1)
				m.scoreArray[r] = 50;
			else if(winString.find("1")!=-1)
				m.scoreArray[r] = 1;
			else if(winString.find("0022")!=-1)
				m.scoreArray[r] = -50;
			else if(winString.find("2200")!=-1)
				m.scoreArray[r] = -50;
			else if(winString.find("0220")!=-1)
				m.scoreArray[r] = -100;
			else if(winString.find("2020")!=-1)
				m.scoreArray[r] = -50;
			else if(winString.find("0202")!=-1)
				m.scoreArray[r] = -50;
			else if(winString.find("2002")!=-1)
				m.scoreArray[r] = -50;
			else if(winString.find("2")!=-1)
				m.scoreArray[r] = -1;
			else
				m.scoreArray[r] = 0;
		}
			/*
			switch(m.grid[n[0]][p[0]])
			{
			case '0':
				switch(m.grid[n[1]][p[1]])
				{
				case '0':
					switch(m.grid[n[2]][p[2]])
					{
					case '0':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = 0;
							break;
						case '1':
							m.scoreArray[r] = 1;
							break;
						case '2':
							m.scoreArray[r] = -1;
							break;
						}
						break;
					case '1':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = 1;
							break;
						case '1':
							m.scoreArray[r] = 10;
							break;
						case '2':
							m.scoreArray[r] = 0;
							break;
						}
						break;
					case '2':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = -1;
							break;
						case '1':
							m.scoreArray[r] = 0;
							break;
						case '2':
							m.scoreArray[r] = -10;
							break;
						}
						break;
					}
					break;
				case '1':
					switch(m.grid[n[2]][p[2]])
					{
					case '0':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = 1;
							break;
						case '1':
							m.scoreArray[r] = 10;
							break;
						case '2':
							m.scoreArray[r] = 0;
							break;
						}
						break;
					case '1':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = 20;
							break;
						case '1':
							m.scoreArray[r] = 50;
							break;
						case '2':
							m.scoreArray[r] = 0;
							break;
						}
						break;
					case '2':
						m.scoreArray[r] = 0;
						break;
					}
					break;
				case '2':
					switch(m.grid[n[2]][p[2]])
					{
					case '0':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = -1;
							break;
						case '1':
							m.scoreArray[r] = 0;
							break;
						case '2':
							m.scoreArray[r] = -10;
							break;
						}
						break;
					case '1':
						m.scoreArray[r] = 0;
						break;
					case '2':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = -20;
							break;
						case '1':
							m.scoreArray[r] = 0;
							break;
						case '2':
							m.scoreArray[r] = -50;
							break;
						}
						break;
					}
					break;
				}
				break;
			case '1':
				switch(m.grid[n[1]][p[1]])
				{
				case '0':
					switch(m.grid[n[2]][p[2]])
					{
					case '0':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = 1;
							break;
						case '1':
							m.scoreArray[r] = 10;
							break;
						case '2':
							m.scoreArray[r] = 0;
							break;
						}
						break;
					case '1':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = 20;
							break;
						case '1':
							m.scoreArray[r] = 50;
							break;
						case '2':
							m.scoreArray[r] = 0;
							break;
						}
						break;
					case '2':
						m.scoreArray[r] = 0;
						break;
					}
					break;
				case '1':
					switch(m.grid[n[2]][p[2]])
					{
					case '0':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = 10;
							break;
						case '1':
							m.scoreArray[r] = 50;
							break;
						case '2':
							m.scoreArray[r] = 0;
							break;
						}
						break;
					case '1':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = 50;
							break;
						case '1':
							m.scoreArray[r] = 999-depth;
							return m.scoreArray[r];
							break;
						case '2':
							m.scoreArray[r] = 0;
							break;
						}
						break;
					case '2':
						m.scoreArray[r] = 0;
						break;
					}
					break;
				case '2':
					m.scoreArray[r] = 0;
					break;
				}
				break;
			case '2':
				switch(m.grid[n[1]][p[1]])
				{
				case '0':
					switch(m.grid[n[2]][p[2]])
					{
					case '0':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = -1;
							break;
						case '1':
							m.scoreArray[r] = 0;
							break;
						case '2':
							m.scoreArray[r] = -10;
							break;
						}
						break;
					case '1':
						m.scoreArray[r] = 0;
						break;
					case '2':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = -10;
							break;
						case '1':
							m.scoreArray[r] = 0;
							break;
						case '2':
							m.scoreArray[r] = -50;
							break;
						}
						break;
					}
					break;
				case '1':
					m.scoreArray[r] = 0;
					break;
				case '2':
					switch(m.grid[n[2]][p[2]])
					{
					case '0':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = -10;
							break;
						case '1':
							m.scoreArray[r] = 0;
							break;
						case '2':
							m.scoreArray[r] = -50;
							break;
						}
						break;
					case '1':
						m.scoreArray[r] = 0;
						break;
					case '2':
						switch(m.grid[n[3]][p[3]])
						{
						case '0':
							m.scoreArray[r] = -50;
							break;
						case '1':
							m.scoreArray[r] = 0;
							break;
						case '2':
							m.scoreArray[r] = -999+depth;
							return m.scoreArray[r];
							break;
						}
						break;
					}
					break;
				}
				break;
			}
		}*/
		r=0;
		for(k=0;k<69;k++)
		{
			r+=m.scoreArray[k];
		}	
	return r;
}

void undoLastMove(moves & m)
{
	int rt,lt;
	char temp;
	int i = m.movelist[m.lastmove - 1] - '0';
	int j = m.grid[i].find("0");
	if( j == -1)
		j = 5;
	else j--;
	
	m.grid[i][j]= '0';
	m.invertgrid[j][i] = '0';
	rt = i - j;
	lt = i + j;
	if(rt > -3 && rt<4)
		m.rightdiag[rt + 2][((i<j)?i:j)] = '0';
	if(lt<9 && lt > 2)
	{
		if(lt == 8)
			m.leftdiag[lt-3][j-2]= '0';
		else if(lt == 7)
			m.leftdiag[lt-3][j-1] = '0';
		else
			m.leftdiag[lt-3][j]= '0';
	}
	m.movelist[--m.lastmove]='9';
	return;
}
void Move(moves & m,int i, int j)
{
	int rt,lt;
	char temp;
    m.movelist[m.lastmove++]= '0' + i;
	bool toggle = m.lastmove % 2;
	m.grid[i][j]= temp = (char)((toggle)?RD:BL);
	m.invertgrid[j][i] = temp;
	rt = i - j;
	lt = i + j;
	if(rt > -3 && rt<4)
		m.rightdiag[rt + 2][((i<j)?i:j)] = temp;
	if(lt<9 && lt > 2)
	{
		if(lt == 8)
			m.leftdiag[lt-3][j-2]= temp;
		else if(lt == 7)
			m.leftdiag[lt-3][j-1] = temp;
		else
			m.leftdiag[lt-3][j]= temp;
	}
}

int minimax(moves & m, int depth,bool isMax,int Alpha=999, int Beta =-999, int limit = 7);
int minimax(moves & m,int depth,bool isMax,int Alpha,int Beta, int limit)
{
	
	int i = m.movelist[m.lastmove - 1] - '0';
	int j = m.grid[i].find("0");
	int i1,j1;
	int k;
	int temp = getScore(m,depth,i,j);
	if(depth == limit)
		return temp;
	if(temp == 999 - depth  && isMax)
		return temp;
	else if(temp == -999 + depth && !isMax)
		return temp;
	for( i = 0; i < 7; i++)
	{
		if((temp = m.grid[i].find("0"))==-1)
		{
			continue;//that column is full so dont try
		}
		Move(m,i,temp);
		temp = minimax(m,depth+1,!isMax);
		i1 =  m.movelist[m.lastmove - 1] - '0';
		j1 = j = m.grid[i].find("0");
		undoLastMove(m);
		k = m.movelist[m.lastmove - 1] - '0';
		(void)getScore(m,depth,i1,j1);
		if(temp == 999 - depth  && isMax)
			return temp;
		else if(temp == -999 + depth && !isMax)
			return temp;
		if(isMax && Beta < temp)
			Beta = temp;
		else if(!isMax && Alpha > temp)
			Alpha = temp;
	}
	if(isMax)
        return Beta;
	return Alpha;
}
int findNextMove(moves & m,int = 8);
int findNextMove(moves & m, int limit)
{
	static util u;
	int temp,i;
	int index;
	int player = 1 + m.lastmove%2;
	string p1 = (player==1)?"1":"2";//p1 represents whom is looking not if you are player 1
	string p2 = (player==1)?"2":"1";
	int cost[7] = {0};
	int max = -999,min=999;
	
	//base case you must win if you can 

	//check vertical
/*	for(i = 0; i<COL;i++)
	{
		if((temp=m.grid[i].find(p1+p1+p1+"0"))!=-1)
			return i;
	}
	//check horizontal
	for( i = 0;i<ROW;i++)
	{
		
		if((temp = m.invertgrid[i].find(p1+p1+p1+'0'))!=-1)
			return temp + 3;
		if((temp = m.invertgrid[i].find('0'+p1+p1+p1))!=-1)
			return temp;
		if((temp = m.invertgrid[i].find(p1+'0'+p1+p1))!=-1)
			if(m.grid[temp+1].find("0")==i)
				return temp + 1;
		if((temp = m.invertgrid[i].find(p1+p1+'0'+p1))!=-1)
			if(m.grid[temp+2].find("0")==i)
				return temp + 2;
	}
	//check right diags
	for(i = 0 ; i < ROW; i++)
	{
		if((temp = m.rightdiag[i].find('0'+p1+p1+p1))!=-1)
		{
			if(i<3)
			{
			  if( m.grid[temp].find("0") == 2-i)
				  return temp;
			}
			else 
			{
				if(m.grid[i-2+temp].find("0") == temp)
					return i - 2 + temp;
			}
		}
		if((temp = m.rightdiag[i].find(p1+p1+p1+'0'))!=-1)
		{
			if(i<3)
			{
			  if( m.grid[temp+3].find("0") == 5-i)
				  return temp + 3;
			}
			else 
			{
				if(m.grid[i+1+temp].find("0") == temp+3)
					return i +1 + temp;	
			}
		}
		
		if((temp = m.rightdiag[i].find(p1+p1+'0'+p1))!=-1)
		{
			if(i<3)
			{
			  if( m.grid[temp+2].find("0") == 4-i)
				  return temp + 2;
			}
			else 
			{
				if(m.grid[i+temp].find("0") == temp+2)
					return i + temp;	
			}
		}
	}


	//check left diags
	for(i = 0 ; i < ROW; i++)
	{
		if((temp = m.leftdiag[i].find('0'+p1+p1+p1))!=-1)
		{
			if(i<4)
			{
			  if( m.grid[4+i-temp].find("0") == temp)
				  return 4+i-temp;
			}
			else 
			{
				if(m.grid[6-temp].find("0") == i-4+temp)
					return 6-temp;
			}
		}
		if((temp = m.rightdiag[i].find(p1+p1+p1+'0'))!=-1)
		{
			if(i<3)
			{
			  if( m.grid[temp+3].find("0") == 5-i)
				  return temp + 3;
			}
			else 
			{
				if(m.grid[i+1+temp].find("0") == temp+3)
					return i +1 + temp;	
			}
		}
		if((temp = m.rightdiag[i].find(p1+p1+'0'+p1))!=-1)
		{
			if(i<3)
			{
			  if( m.grid[temp+2].find("0") == 4-i)
				  return temp + 2;
			}
			else 
			{
				if(m.grid[i+temp].find("0") == temp+2)
					return i + temp;	
			}
		}
	}

	//or block if you have to block

	for(i = 0; i<COL;i++)
	{
		if((temp=m.grid[i].find(p2+p2+p2+'0'))!=-1)
			return i;
	}
	for( i = 0;i<ROW;i++)
	{
		if(m.invertgrid[i]=="0000000")
			break;
		if((temp = m.invertgrid[i].find(p2+p2+p2+'0'))!=-1)
			return temp + 3;
		if((temp = m.invertgrid[i].find('0'+p2+p2+p2))!=-1)
			return temp;
		if((temp = m.invertgrid[i].find(p2+'0'+p2+p2))!=-1)
			if(m.grid[temp+1].find("0")==i)
				return temp + 1;
		if((temp = m.invertgrid[i].find(p2+p2+'0'+p2))!=-1)
			if(m.grid[temp+2].find("0")==i)
				return temp + 2;
	}
	for(i = 0 ; i < ROW; i++)
	{
		if((temp = m.rightdiag[i].find('0'+p2+p2+p2))!=-1)
			if(i<3)
			{
			  if( m.grid[temp].find("0") == 2-i)
				  return temp;
			}
			else 
				if(m.grid[i-2+temp].find("0") == temp)
					return i - 2 + temp;
		if((temp = m.rightdiag[i].find(p2+p2+p2+'0'))!=-1)
			if(i<3)
			{
			  if( m.grid[temp+3].find("0") == 5-i)
				  return temp + 3;
			}
			else 
				if(m.grid[i+1+temp].find("0") == temp+3)
					return i +1 + temp;	
		if((temp = m.rightdiag[i].find(p2+p2+'0'+p2))!=-1)
			if(i<3)
			{
			  if( m.grid[temp+2].find("0") == 4-i)
				  return temp + 2;
			}
			else 
				if(m.grid[i+temp].find("0") == temp+2)
					return i + temp;	
	}


	for(i = 0 ; i < ROW; i++)
	{
		if((temp = m.rightdiag[i].find('0'+p2+p2+p2))!=-1)
		{
			if(i<3)
			{
			  if( m.grid[temp].find("0") == 2-i)
				  return temp;
			}
			else 
			{
				if(m.grid[i-2+temp].find("0") == temp)
					return i - 2 + temp;
			}
		}
		if((temp = m.rightdiag[i].find(p2+p2+p2+'0'))!=-1)
		{
			if(i<3)
			{
			  if( m.grid[temp+3].find("0") == 5-i)
				  return temp + 3;
			}
			else 
			{
				if(m.grid[i+1+temp].find("0") == temp+3)
					return i +1 + temp;	
			}
		}
		if((temp = m.rightdiag[i].find(p2+p2+'0'+p2))!=-1)
		{
			if(i<3)
			{
			  if( m.grid[temp+2].find("0") == 4-i)
				  return temp + 2;
			}
			else 
			{
				if(m.grid[i+temp].find("0") == temp+2)
					return i + temp;	
			}
		}
	}


	//check left diags
	for(i = 0 ; i < ROW; i++)
	{
		if((temp = m.leftdiag[i].find('0'+p2+p2+p2))!=-1)
		{
			if(i<4)
			{
			  if( m.grid[4+i-temp].find("0") == temp)
				  return 4+i-temp;
			}
			else 
			{
				if(m.grid[6-temp].find("0") == i-4+temp)
					return 6-temp;
			}
		}
		if((temp = m.rightdiag[i].find(p2+p2+p2+'0'))!=-1)
		{
			if(i<3)
			{
			  if( m.grid[temp+3].find("0") == 5-i)
				  return temp + 3;
			}
			else 
			{
				if(m.grid[i+1+temp].find("0") == temp+3)
					return i +1 + temp;	
			}
		}
		if((temp = m.rightdiag[i].find(p2+p2+'0'+p2))!=-1)
		{
			if(i<3)
			{
			  if( m.grid[temp+2].find("0") == 4-i)
				  return temp + 2;
			}
			else 
			{
				if(m.grid[i+temp].find("0") == temp+2)
					return i + temp;	
			}
		}
	}

*/
	for(i = 0; i < COL; i++)
	{
		Move(m,i,m.grid[i].find("0"));
		temp = minimax(m,0,player!=1);
		undoLastMove(m);
		if(player==1)
		{
			if(temp>max)
			{
				max = temp;
				index = i;
			}
		}else
		{
			if(temp<min)
			{
				min = temp;
				index = i;
			}
		}
	}
	return index;
			
			//return u.getrand(6,0);
}
int playGame(int player1=1, int player2=2);//1=human,2=human,3=computer,0=tie
int playGame(int player1, int player2)
{
	
	util u;
	color();
	clrscr();
	displayGrid();
	bool toggle = true;
	int i,j;
	int winner = 0;
	moves m;   
    while(gridNotFull(m.grid)&&
		(winner = whoWon(m.grid,COL))==0 && (winner = whoWon(m.invertgrid,ROW))==0 &&
		(winner = whoWon(m.rightdiag,ROW))==0 && (winner = whoWon(m.leftdiag,ROW))==0)
	{
		if(toggle && player1 == 3)
			i = findNextMove(m);
		if(!toggle && player2 == 3)
			i = findNextMove(m);
		if((toggle && player1 == 1 )||( !toggle && player2 == 2))
			i = DropSelection(((toggle)?RD:BL));
		if((j=m.grid[i].find("0"))!=-1)
		{
			Move(m,i,j);
			displayTile(toggle,i,j);
			toggle = !toggle;
		}
	}
	if(winner == 1 && player1 == 3)
		return 3;
	if(winner == 2 && player2 == 3)
		return 4;
	return winner;
}

int main()
{
	util u;
	const int MENUITEMS = 3;
	const int SUBMENUITEMS = 5;
	int selection;
	int winner;
	int player1 = 1, player2 = 3;
	string menu[MENUITEMS]= {" Player Selection Submenu", " Play Game", " Exit"};
	string playerSubMenu[SUBMENUITEMS]={" Player vs Player"," Player vs Comp"," Comp vs Player", " Computer vs Computer", " Exit withou Change"};


	do{
		color();
		clrscr();
		switch(selection = displayMenu(menu,MENUITEMS))
		{
		case 0:
			color();
			clrscr();
			switch(displayMenu(playerSubMenu,SUBMENUITEMS))
			{
			case 0:
				player1 = 1; player2 = 2;
				break;
			case 1:
				player1 = 1; player2 = 3;
				break;
			case 2:
				player1 = 3; player2 = 2;
				break;
			case 3:
				player1 = 3; player2 = 3;
				break;
			default:
				;
			}
			break;
		case 1:
			winner = playGame(player1,player2);
			color();
			gotoxy(0,24);
			if(winner == 3)
				cout << "Red computer wins!!\n\n";
			else if(winner == 4)
				cout << "Blue computer wins!!\n\n";
			else if(winner == 0)
				cout << "Sorry tie game!!\n\n";
			else
				cout << "Player " << winner << " WINS!!\n\n";
			u.pause();
			clrscr();
			break;
		case 2:
			cout << "Exiting....\n\n";
			break;
		}
	}while(selection!=MENUITEMS -1);

	return 0;
}