///////////////////////////////////////////////////////////
//  cAquaticAnimalFactory.cpp
//  Implementation of the Class cAquaticAnimalFactory
//  Created on:      01-Feb-2013 8:28:30 PM
///////////////////////////////////////////////////////////

#include "cAquaticAnimalFactory.h"
#include "cDolphin.h"
#include "cNarwhal.h"



cAquaticAnimalFactory::cAquaticAnimalFactory()
{

}


cAquaticAnimalFactory::~cAquaticAnimalFactory()
{
	
}


iAnimal & cAquaticAnimalFactory::CreateNormalAnimal() const
{
	return *(new cDolphin());
}


iAnimal & cAquaticAnimalFactory::CreateSpecialtyAnimal() const
{
	return *(new cNarwhal());
}

cAquaticAnimalFactory & cAquaticAnimalFactory::Instance()
{
	static cAquaticAnimalFactory instance;

	return instance;
}