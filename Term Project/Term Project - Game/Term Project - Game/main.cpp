#include "Game.h"

#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC

#include <iostream>
using std::endl;
using std::cout;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	TheSkyIsFallingGame game;
	game.Start();

	
    return EXIT_SUCCESS;
}