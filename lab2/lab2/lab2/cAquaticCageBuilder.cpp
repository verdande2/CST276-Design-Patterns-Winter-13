///////////////////////////////////////////////////////////
//  cAquaticCageBuilder.cpp
//  Implementation of the Class cAquaticCageBuilder
//  Created on:      03-Feb-2013 3:12:46 PM
//  Original author: Verdande
///////////////////////////////////////////////////////////

#include "cAquaticCageBuilder.h"
#include "cAquaticCage.h"



cAquaticCageBuilder::cAquaticCageBuilder(){
	m_cage = new cAquaticCage();
}



cAquaticCageBuilder::~cAquaticCageBuilder(){
	
}





void cAquaticCageBuilder::BuildDimensions()
{
	m_cage->SetLength(100);
	m_cage->SetWidth(50);
}


void cAquaticCageBuilder::BuildWalls()
{
	m_cage->SetWallType("Glass");
}