///////////////////////////////////////////////////////////
//  cCageBuilder.cpp
//  Implementation of the Class cCageBuilder
//  Created on:      03-Feb-2013 3:12:47 PM
//  Original author: Verdande
///////////////////////////////////////////////////////////

#include "cCageBuilder.h"


cCageBuilder::cCageBuilder() : m_cage(nullptr)
{
	
}



cCageBuilder::~cCageBuilder()
{

}





void cCageBuilder::BuildCage()
{
	BuildDimensions();
	BuildWalls();
}

cCage & cCageBuilder::Cage()
{
	return *m_cage;
}