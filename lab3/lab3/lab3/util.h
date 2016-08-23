/*	Jeremiah Tatro
	09/15/2002
	This is a utilities editor which is designed to make available
	common routines to projects to reduce programming time.  
	Please note the following libraries included do not need to be included 
	in your .h files. you can comment them out but the functions may not
	work without them

  NOTE !!!!!!!!!!   using this program for programs, money etc... is fully
  permitted by the author as long as you provide any changes as readable 
  source to the public.  You got this for free so let others learn off of you.
*/
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>		//note change to iostream.h and 
using std::cout;
using std::cin;
using std::hex;
using std::dec;
using std::endl;
using std::istream;
using std::ostream;
//using namespace std;		//comment out  using namespace if
#endif						//using iostream.h in your files


#ifndef CSTDIO
#define CSTDIO
#include <cstdio>
#endif

#if (!defined(_WIN32)&&!defined(_MAC))
#ifndef TERMIO_H
#define TERMIO_H		//for getch() in linux
#define systemOP 1
#include <termio.h>
#endif
#ifndef SYS_TIME_H		//for gettimeofday()
#define SYS_TIME_H		//gets time in microseconds
#include <sys/time.h>
#endif
#endif

#if (defined(_WIN32)) 
#define systemOP 0
#ifndef CONIO_H
#define CONIO_H
#include <CONIO.H>
#endif
#endif

#ifndef CSTDLIB
#define CSTDLIB
#include <cstdlib>
#endif

#ifndef VECTOR
#define VECTOR
#include <vector>
#endif

#ifndef CMATH
#define CMATH
#include <cmath>
#endif

#ifndef CTIME
#define CTIME
#include <ctime>
#endif

#ifndef UTIL_H
#define UTIL_H

class util{

  public:
	util();//for seeding srand once
	~util(){}
	void cls(); //clears the screen
	bool pause(char = 'e',char message[] = "Hit any key to continue\n");
	int getint(int floor = ((sizeof(int)==2)?0xf000:0xf0000000), int ceiling = ((sizeof(int)==2)?0x7fff:0x7fffffff),istream& = cin);
			//note you can make the ceiling smaller than the default not larger

			// and you can make the floor larger than the default not smaller
			// and ceilng cannot be less than or equal to floor
	int getint(istream&);
	long getlong(istream&);
	long getlong(long floor = 0xf0000000, long ceiling = 0x7fffffff, istream& = cin);
	int getrand(int ceiling = 10, int floor = 1);
	long getrand(long ceiling, long floor = 1);

  private:
	bool randflag;
	int high;
	int low;

};


template<class T>
struct utilTemps{
		void swapp(T &a, T &b) //swaps two objects values
			//note copy constructor should be written
			//for this to work correctly in some instances
		{T temp;temp = a;a=b;b = temp;}

};

#endif



