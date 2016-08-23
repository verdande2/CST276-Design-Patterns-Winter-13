///////////////////////////////////////////////////////////
//  cCage.cpp
//  Implementation of the Class cCage
//  Created on:      01-Feb-2013 8:31:59 PM
///////////////////////////////////////////////////////////

#include "cCage.h"


cCage::cCage()
	: m_wallType(""),
	m_width(0),
	m_length(0),
	m_animal(nullptr)
{
	
}

cCage::cCage(const string &wallType, int width, int length, iAnimal &animal)
	: m_wallType(wallType),
	m_width(width),
	m_length(length),
	m_animal(&animal)
{

}


cCage::~cCage()
{

}


const iAnimal & cCage::GetAnimal() const
{
	const iAnimal *animalPtr = nullptr;
	if(nullptr != m_animal)
	{
		animalPtr = const_cast<const iAnimal *>(m_animal);
	}
	return *animalPtr;
}


int cCage::GetLength() const
{
	return m_length;
}


const string & cCage::GetWallType() const
{
	return m_wallType;
}


int cCage::GetWidth() const
{
	return m_width;
}


void cCage::SetAnimal(iAnimal &animal){
	m_animal = &animal;
}


void cCage::SetLength(int length)
{
	m_length = length;
}


void cCage::SetWidth(int width)
{
	m_width = width;
}

void cCage::SetWallType(const string &wallType)
{
	m_wallType = wallType;
}