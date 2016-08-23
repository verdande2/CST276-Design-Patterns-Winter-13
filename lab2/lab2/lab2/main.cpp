#include <iostream>
using std::cout;
using std::endl;
#include "cZoo.h"
#include "cLandAnimalFactory.h"
#include "cAquaticAnimalFactory.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	cout << "Lab 2 Demo by Andrew Sparkes" << endl << endl;

	cout << "Creating a zoo (zoo1) with a land animal factory..." << endl;
	cLandAnimalFactory landFactory = cLandAnimalFactory::Instance();
	cZoo zoo1(landFactory);

	cout << "Populating zoo1..." << endl;
	zoo1.Populate();

	cout << "Displaying all animals in zoo1..." << endl;
	zoo1.MakeAllAnimalsMakeNoise();

	cout << "Creating another zoo (zoo2) with an aquatic animal factory..." << endl;
	cAquaticAnimalFactory aquaticFactory = cAquaticAnimalFactory::Instance();
	cZoo zoo2(aquaticFactory);

	cout << "Populating zoo2..." << endl;
	zoo2.Populate();

	cout << "Displaying all animals in zoo2..." << endl;
	zoo2.MakeAllAnimalsMakeNoise();

	system("pause");
	return 0;
}