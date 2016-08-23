#include "util.h"
#include <windows.h>

#if (!defined(_WIN32)&&!defined(_MAC))
int getch(void)
{				// this resets linux so that you dont have
				// to press enter with when using getchar()
  struct termios stored_settings;
  struct termios new_settings;
  int ch;

  tcgetattr(0, &stored_settings);
  new_settings = stored_settings;
  new_settings.c_lflag &= (~ICANON);
  new_settings.c_cc[VTIME] = 0;
  new_settings.c_cc[VMIN] = 1;
  tcsetattr(0, TCSANOW, &new_settings);

  ch = getchar();

  tcsetattr(0, TCSANOW, &stored_settings);
  // this resets to the og settings

  return ch;  
}
#endif

util::util(){
	randflag = true;
	if(sizeof(int) == 2){
		high = 0x7fff;
		low = 0xffff;
	}
	else {
		high =0x7fffffff;
		low =0xffffffff;
	}

}

void util::cls(){
	if(systemOP)
		system("clear");
	else
		system("cls");
}


bool util::pause(char escape,char mssg[]){			//pauses screen for user
	cout << mssg ; //change to a different message
	char n = getch();			//if passed in escape key matches stroke
			//the function returns true. Note can be used to exit early
	return(n==escape);
}

int hmchars(char* A, char B){
	int I = strlen(A);
		if(I <= 0)
			return 0;
	int count = 0;
	for(int i = 0; i < I ; i++)
		if(A[i]==B) count++;
	return count;
}
/*
	This function will fully test the input of the user
*/
int util::getint(istream& in){
	return getlong(high,low,in);
}
int util::getint( int floor, int ceiling, istream& in){
	if(ceiling > high)		//ceiling-floor error checking
		ceiling = high;
	else if(floor < low)
		floor = low;
	else if(ceiling < floor){
		ceiling = high;
		floor = low;
	}
	else if(ceiling == floor)
		floor = low;

	return getlong(floor,ceiling,in);
}

long util::getlong(istream& in){
	long ceiling = (long)(2147483647);
	long floor = (long)(-2147483647);
	return getlong(floor,ceiling,in);
}


long util::getlong( long floor, long ceiling,istream& in){
	char cVar[80];
	long temp,temp2,temp3,temp4;
	bool lower, upper, flags[10];
	in.clear();

	if(ceiling < floor){
		ceiling = (long)2147483647;
		floor = (long)-2147483647;
	}
	if(ceiling == floor)
		floor = (long)-2147483647;

	cVar[12]='\0'; 	//insures null termination

	do{
		do{
			in.getline(cVar,79);
		}while(cVar[0]=='\0');
		cVar[12]='\0'; 	//insures null termination
		temp = atol(cVar);
		temp2 = hmchars(cVar,'-');
		temp3 = strspn(cVar, "1234567890-");
		temp4 = strlen(cVar);
		char lowercmp[6], uppercmp[6];

		if(temp4==10){
			strcpy(lowercmp,&cVar[5]);
			cVar[5]='\0';
			strcpy(uppercmp,&cVar[0]);
		}
		else if(temp4==11){
			strcpy(lowercmp,&cVar[6]);
			cVar[6]='\0';
			strcpy(uppercmp,&cVar[1]);
		}

		/* Note I can't compare a long to a bigger number so I have
			to split the number into two parts and compare them*/
		flags[5]=(atol(uppercmp)>21474);
		flags[6]=(atol(lowercmp)>83647);
		flags[7]=(atol(uppercmp)==21474);
		/*  The lower absolute value of the lowerbound == upperbound + 1 */
		if(cVar[0]=='-')
			flags[6]=(atol(lowercmp)>83648);

		lower = (temp4==11&&cVar[0]=='-'&&(flags[5]||(flags[7]&&flags[6])));
				//lower bound of a long that is a size of 4 bytes
		upper = (temp4==10&&cVar[0]!='-'&& (flags[5]||(flags[7]&&flags[6])));

		flags[0]=temp4!=temp3;
		flags[1]=temp2 > 1 || (temp2==1&&cVar[0]!='-');
		flags[2]=temp4 > 11||(temp4==11&&cVar[0]!='-');
		flags[3]=(temp4==11&&temp2==0);
		flags[4]=(flags[0]||flags[1]||flags[2]||flags[3]||upper||lower);

		if(!flags[4])
			flags[4]=((temp>ceiling)||(temp<floor));

		if(flags[0])
			cout << "Sorry, letters are not accepted" << endl;
		if(flags[1])
			cout << "Error, in use of '-' character"<< endl;
		if(flags[2]||flags[3]){
			cout << "Buffer overflow error, too many characters for input."<<endl;
			while(in.get()!='\n')
				in.clear();
		}
		if(flags[4])
			cout << "Please enter an integer (" << floor << " to " << ceiling <<"): ";

	}while ( flags[4]);
			
	cout << endl;
	return temp;  //returns cVar as an integer value
}

int util::getrand(int ceiling, int floor){
	if (floor >= ceiling)
		return 0;
	if(randflag){
		//struct timeval t_val;
		//gettimeofday(&t_val,NULL);
		randflag =false;
		srand(time(0));		//seeds random number generator only once
	}
	int temp = ceiling - floor;
	return ((rand())%(temp+1)+floor);
}

long util::getrand(long ceiling, long floor){
	if (floor >= ceiling)
		return 0;
	if(randflag){
		randflag =false;
		srand(time(0));		//seeds random number generator
	}
	long temp = ceiling - floor;
	return ((long)((rand())%(temp+1)+floor));
}

