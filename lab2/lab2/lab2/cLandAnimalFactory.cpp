///////////////////////////////////////////////////////////
//  cLandAnimalFactory.cpp
//  Implementation of the Class cLandAnimalFactory
//  Created on:      01-Feb-2013 8:28:30 PM
///////////////////////////////////////////////////////////

#include "cLandAnimalFactory.h"
#include "cMonkey.h"
#include "cVelociraptor.h"




cLandAnimalFactory::cLandAnimalFactory()
{

}


cLandAnimalFactory::~cLandAnimalFactory()
{

}

iAnimal & cLandAnimalFactory::CreateNormalAnimal() const
{
	return *(new cMonkey());
}

iAnimal & cLandAnimalFactory::CreateSpecialtyAnimal() const
{
	return *(new cVelociraptor());
}

cLandAnimalFactory & cLandAnimalFactory::Instance()
{
	static cLandAnimalFactory instance;

	return instance;
}