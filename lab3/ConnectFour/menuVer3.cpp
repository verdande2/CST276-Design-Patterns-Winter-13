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
using std::vector;
vector<int> cost;
const int COL = 7, ROW = 6;
const int EMPTY = 0, RD = '1', BL = '2';
const int BRED = 12, BBLUE=9, BYELLOW=14, BBLACK = 0;
int winningStatesI[69][4]= {	//the set of column positions of each winning state
	{0,0,0,0},{0,0,0,0},{0,0,0,0}	//begin verticals
	,{1,1,1,1},{1,1,1,1},{1,1,1,1}
	,{2,2,2,2},{2,2,2,2},{2,2,2,2}
	,{3,3,3,3},{3,3,3,3},{3,3,3,3}
	,{4,4,4,4},{4,4,4,4},{4,4,4,4}
	,{5,5,5,5},{5,5,5,5},{5,5,5,5}
	,{6,6,6,6},{6,6,6,6},{6,6,6,6}	//end verticals
	,{0,1,2,3},{1,2,3,4},{2,3,4,5},{3,4,5,6}	//begin horizontals
	,{0,1,2,3},{1,2,3,4},{2,3,4,5},{3,4,5,6}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5},{3,4,5,6}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5},{3,4,5,6}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5},{3,4,5,6}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5},{3,4,5,6}	//end horizontals
	,{0,1,2,3}					//begin right diags
	,{0,1,2,3},{1,2,3,4}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}
	,{1,2,3,4},{2,3,4,5},{3,4,5,6}
	,{2,3,4,5},{3,4,5,6}
	,{3,4,5,6}
	,{3,2,1,0}					//begin left diags
	,{4,3,2,1},{3,2,1,0}
	,{5,4,3,2},{4,3,2,1},{3,2,1,0}
	,{6,5,4,3},{5,4,3,2},{4,3,2,1}
	,{6,5,4,3},{5,4,3,2}
	,{6,5,4,3}};//end left diags
int winningStatesJ[69][4]= {	//the set of row postions of each winning set
	{0,1,2,3},{1,2,3,4},{2,3,4,5}	//begin verticals
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}	//end verticals
	,{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}	//begin horizontals
	,{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}
	,{2,2,2,2},{2,2,2,2},{2,2,2,2},{2,2,2,2}
	,{3,3,3,3},{3,3,3,3},{3,3,3,3},{3,3,3,3}
	,{4,4,4,4},{4,4,4,4},{4,4,4,4},{4,4,4,4}
	,{5,5,5,5},{5,5,5,5},{5,5,5,5},{5,5,5,5}	//end horizontals
	,{2,3,4,5}					//begin right diags
	,{1,2,3,4},{2,3,4,5}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}
	,{0,1,2,3},{2,3,4,5}
	,{0,1,2,3}
	,{0,1,2,3}					//begin left diags
	,{0,1,2,3},{1,2,3,4}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}
	,{0,1,2,3},{1,2,3,4},{2,3,4,5}
	,{1,2,3,4},{2,3,4,5}
	,{2,3,4,5}};	
string mapToStates[COL][ROW];
void initializeMap()
{
	string s[69];
	for(int k = 0; k<69; k++)
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
}
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

int whoWon(string grid[],int size)
{
	string winString = "0000";
	for(int r=0;r<69;r++)
	{	
		for(int q=0;q<4;q++)
		{
			winString[q] =grid[winningStatesI[r][q]][winningStatesJ[r][q]];
		}
		if(winString.find("1111")!=-1)
			return 1;
		if(winString.find("2222")!=-1)
			return 2;
	}
	return 0;
}

struct moves{
	char movelist[42];
	string grid[COL];//initialize grid to empty
	int lastmove;
	int scoreArray[69];
	moves():lastmove(0)
	{	
		int i;
		for( i = 0; i < 42; i++)
			movelist[i] = '9';
		for(i=0;i<COL;i++)
			grid[i] = "000000";
		for(i=0;i<69;i++)
			scoreArray[i]=0;
	}
};
int getScore(moves & m,int depth,int i, int j)
{
	static string winString = "0000";
	static string s[69];
	int k,p[4],q,r;
	static bool doOnce = true;
	char temp;
	bool pos;
	for(k=0;k<mapToStates[i][j].size();k++)
	{	
		r =((int)mapToStates[i][j][k]) - '0';
		for(q=0;q<4;q++)
		{
			winString[q] =m.grid[winningStatesI[r][q]][winningStatesJ[r][q]];
		}
		if(winString.find("1")!=-1&&winString.find("2")!=-1)
			m.scoreArray[r] = 0;
		else if(winString.find("0000")!=-1)
			m.scoreArray[r] = 0;
		else if((pos = winString.find("1")!=-1)?temp = '1':temp = '2')
		{
			if(winString[0]==temp)//1xxx
			{
				if(winString[1]==temp)//11xx
				{
					if(winString[2]==temp)//111x
					{
						if(winString[3]==temp)//1111
							m.scoreArray[r] = 9999 - depth;
						else				//1110
							m.scoreArray[r] = 75 - depth;
					}
					else	//110x
					{
						if(winString[3]=='1')//1101
							m.scoreArray[r] = 40- depth;
						else
							m.scoreArray[r] = 20 - depth;//1100
					}
				}				//10xx
				else
				{
					if(winString[2]==temp)//101x
					{
						if(winString[3]==temp)//1011
							m.scoreArray[r] = 40- depth;
						else				//1010
							m.scoreArray[r] = 20- depth;
					}
					else				//100x
					{
						if(winString[3]==temp)//1001
							m.scoreArray[r] = 20- depth;
						else				//1000
							m.scoreArray[r] = 5- depth;
					}
				}
			}
			else//0xxx
			{
				if(winString[1]==temp)//01xx
				{
					if(winString[2]==temp)//011x
					{
						if(winString[3]==temp)//0111
							m.scoreArray[r] = 75- depth;
						else				//0110
							m.scoreArray[r] = 60- depth;
					}
					else	//010x
					{
						if(winString[3]=='1')//0101
							m.scoreArray[r] = 20- depth;
						else
							m.scoreArray[r] = 5- depth;//0100
					}
				}				//00xx
				else
				{
					if(winString[2]==temp)//001x
					{
						if(winString[3]==temp)//0011
							m.scoreArray[r] = 20- depth;
						else				//0010
							m.scoreArray[r] = 5- depth;
					}
					else				//000x
					{
						if(winString[3]==temp)//0001
							m.scoreArray[r] = 5- depth;
						
					}
				}
			}
			if(!pos)
				m.scoreArray[r] *=-1;
		}//end for
		
		}
		r=0;
		for(k=0;k<69;k++)
		{
			r+=m.scoreArray[k];
		}	
	return r;
}

void undoLastMove(moves & m,int depth)
{
	int i = m.movelist[m.lastmove - 1] - '0';
	int j = m.grid[i].find("0");
	if( j == -1)
		j = 5;
	else j--;
	m.grid[i][j]= '0';
	m.movelist[--m.lastmove]='9';
	(void)getScore(m,depth,i,j);
	return;
}
void Move(moves & m,int i, int j)
{
    m.movelist[m.lastmove++]= '0' + i;
	m.grid[i][j]= (char)((m.lastmove % 2)?RD:BL);
}

int minimax(moves & m, int depth,bool isMax,int Alpha, int Beta, int limit = 6);
int minimax(moves & m,int depth,bool isMax,int Alpha,int Beta, int limit)
{
	int bestmove = (isMax)?Alpha:Beta;
	int i = m.movelist[m.lastmove - 1] - '0';
	int j = m.grid[i].find("0");
	if(j==-1)
		j = 5;
	else
		j--;
	int temp = getScore(m,depth,i,j);
	if(depth == limit||m.lastmove==42)
		return temp;
	if(temp >= 9990  && isMax)
		return temp;
	else if(temp <= -9990 && !isMax)
		return temp;
	for( i = 0; i < 7; i++)
	{
		if((temp = m.grid[i].find("0"))==-1)
		{
			continue;//that column is full so dont try
		}
		Move(m,i,temp);
		temp = minimax(m,depth+1,!isMax,Alpha,Beta);
		undoLastMove(m,depth);

		if(isMax && temp > bestmove)
		{
			bestmove = temp;
			Alpha = temp;
		}
		else if(!isMax && temp < bestmove)
		{
			bestmove = temp;
			Beta = temp;
		}
		//if(isMax && Beta > Alpha)	
		//	return bestmove;
		//else if(!isMax && Beta < Alpha)
		//	return bestmove;
	}
	return bestmove;
}
int findNextMove(moves & m,int = 3);
int findNextMove(moves & m, int limit)
{
	static util u;
	int temp,i;
	int index=0;
	int player = 1 + m.lastmove%2;
	int cost[7] = {0};
	int Alpha = -9999, Beta = 9999, bestmove = (player==1)?-9999:9999;

	for(i = 0; i < COL; i++)
	{
		if((temp = m.grid[i].find("0"))==-1)
		{
			continue;//that column is full so dont try
		}
		Move(m,i,m.grid[i].find("0"));
		temp = minimax(m,0,player!=1,Alpha,Beta);
		undoLastMove(m,0);
		if(player==1)
		{
			if(temp>bestmove)
			{
				bestmove = temp;
				index = i;
			}
		}else
		{
			if(temp<bestmove)
			{
				bestmove = temp;
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
	while(m.lastmove < 42 &&
		(winner = whoWon(m.grid,COL))==0)
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
	initializeMap();
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