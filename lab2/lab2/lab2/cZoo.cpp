///////////////////////////////////////////////////////////
//  cZoo.cpp
//  Implementation of the Class cZoo
//  Created on:      01-Feb-2013 8:32:01 PM
//  Original author: andrew.sparkes
///////////////////////////////////////////////////////////

#include "cZoo.h"
#include <iostream>
using std::cout;
using std::endl;
#include "cLandAnimal.h"
#include "cAquaticAnimal.h"

#include "cLandCage.h"
#include "cAquaticCage.h"

#include "cAquaticCageBuilder.h"
#include "cLandCageBuilder.h"


cZoo::cZoo()
	: m_animalFactory(nullptr)
{
	
}

cZoo::cZoo(const cZoo &copy)
	: m_cages(copy.m_cages),
	m_animalFactory(copy.m_animalFactory) // note that this copies the pointer, so the copied zoo has the same animal factory aka shallow copy
{

}


cZoo::cZoo(iAnimalFactory &animalFactory) : m_animalFactory(&animalFactory)
{
	for(auto i = m_cages.begin(); i != m_cages.end(); ++i)
	{
		// delete each cage's animal
		delete & ((*i).GetAnimal());
	}
}


cZoo::~cZoo(){
	for(auto i = m_cages.begin(); i != m_cages.end(); ++i)
	{
		// delete each cage's animal
		delete & ((*i).GetAnimal());
	}
}

void cZoo::Populate()
{
	// default behavior is to set up 2 normal animals and 1 specialty animals
	for(int i = 0; i < 2; ++i)
	{
		AddAnimal(m_animalFactory->CreateNormalAnimal());
	}

	for(int i = 0; i < 1; ++i)
	{
		AddAnimal(m_animalFactory->CreateSpecialtyAnimal());
	}
}

void cZoo::AddAnimal(iAnimal &animal)
{
	cCage* newCagePtr = nullptr;
	cCageBuilder* builder = nullptr;

	if(dynamic_cast<cLandAnimal *>(&animal) != 0)
	{
		// we have a land animal, so make a land cage
		builder = new cLandCageBuilder();

	}
	else if(dynamic_cast<cAquaticAnimal *>(&animal) != 0)
	{
		// we have an aquatic animal, so make an aquatic cage
		builder = new cAquaticCageBuilder();
	}
	else
	{
		throw "An animal was passed to cZoo::AddAnimal() that was not a cAquaticAnimal nor a cLandAnimal";
	}

	builder->BuildCage();
	newCagePtr = &(builder->Cage());
	newCagePtr->SetAnimal(animal);
	m_cages.push_back(*newCagePtr);
	delete newCagePtr;

	delete builder;
}


void cZoo::MakeAllAnimalsMakeNoise() const
{
	for(vector<cCage>::const_iterator i = m_cages.begin(); i != m_cages.end(); ++i)
	{	
		cout << "From a " << (*i).GetLength() << "x" << (*i).GetWidth() << " cage made of " << (*i).GetWallType() << "..." << endl;
		(*i).GetAnimal().MakeNoise();
		cout << endl;
	}
}