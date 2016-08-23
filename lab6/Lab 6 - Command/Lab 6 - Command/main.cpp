#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC

#include "Calculator.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Calculator calc;
	calc.Start();
	
	return 0;
}