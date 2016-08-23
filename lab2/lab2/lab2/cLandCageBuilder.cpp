///////////////////////////////////////////////////////////
//  cLandCageBuilder.cpp
//  Implementation of the Class cLandCageBuilder
//  Created on:      03-Feb-2013 3:12:43 PM
//  Original author: Verdande
///////////////////////////////////////////////////////////

#include "cLandCageBuilder.h"
#include "cLandCage.h"


cLandCageBuilder::cLandCageBuilder(){
	m_cage = new cLandCage();
}



cLandCageBuilder::~cLandCageBuilder(){

}





void cLandCageBuilder::BuildDimensions()
{
	m_cage->SetLength(40);
	m_cage->SetWidth(40);
}


void cLandCageBuilder::BuildWalls()
{
	m_cage->SetWallType("Bars");
}